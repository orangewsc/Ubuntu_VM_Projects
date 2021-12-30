#ifndef VSOMEIP_ENABLE_SIGNAL_HANDLING
#include <csignal>
#endif
#include <vsomeip/vsomeip.hpp>
#include <chrono>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <iostream>

static vsomeip::service_t service_id = 0x4001;
static vsomeip::instance_t service_instance_id = 0x4e21;

/*
const static vsomeip::method_t RDA_0ms_method_id = 0x1001;
const static vsomeip::method_t RDA_100ms_method_id = 0x1002;
const static vsomeip::method_t RDA_20ms_method_id = 0x1003;
const static vsomeip::method_t RDA_50ms_method_id = 0x1004;
const static vsomeip::method_t RDAObs_50ms_method_id = 0x1005;
*/

//////second version trj 20180123///////////////
const static vsomeip::method_t RDA_0ms_method_id = 0x1001;
const static vsomeip::method_t RDA_20ms_method_id = 0x1002;
const static vsomeip::method_t RDA_50ms_method_id = 0x1003;
const static vsomeip::method_t RDA_100ms_method_id = 0x1004;
const static vsomeip::method_t RDAObs_50ms_method_id = 0x1005;

#define SAMPLE_EVENTGROUP_ID	0xa
#define SAMPLE_EVENT_ID_20ms	0x1007
#define SAMPLE_EVENT_ID_50ms	0x1008



class saic_service
{
public:
    saic_service() :
                    rtm_(vsomeip::runtime::get()),
                    app_(rtm_->create_application()),
                    stop_(false),
                    stop_thread_(std::bind(&saic_service::stop, this)),
					notify_thread_(std::bind(&saic_service::notify, this))
    {
		is_offered_ = false;

		RDASwStsHSC4_ = 0;

		DOWSelStsHSC4_ = 0;
    }

    ~saic_service()
    {
        stop_thread_.join();
    }

    bool init()
    {
        // init the application
        if (!app_->init())
		{
            std::cerr << "Couldn't initialize application" << std::endl;
            return false;
        }

        // register a message handler callback for messages sent to our service
        app_->register_message_handler(service_id, service_instance_id,
                vsomeip::ANY_METHOD,
                std::bind(&saic_service::on_message_cbk, this,
                        std::placeholders::_1));

        // register a state handler to get called back after registration at the
        // runtime was successful
        app_->register_state_handler(
                std::bind(&saic_service::on_state_cbk, this,
                        std::placeholders::_1));

		std::set<vsomeip::eventgroup_t> its_groups;
        its_groups.insert(SAMPLE_EVENTGROUP_ID);

        app_->offer_event(
                service_id,
                service_instance_id,
                (SAMPLE_EVENT_ID_20ms | 0x8000),
                its_groups,
                true);

		app_->offer_event(
				service_id,
				service_instance_id,
				(SAMPLE_EVENT_ID_50ms | 0x8000),
				its_groups,
				true);

        payload_ = vsomeip::runtime::get()->create_payload();

        return true;
    }

    void start()
    {
        // start the application and wait for the on_event callback to be called
        // this method only returns when app_->stop() is called
        app_->start();
    }

    void stop()
    {
        std::unique_lock<std::mutex> its_lock(mutex_);
        while(!stop_)
		{
            condition_.wait(its_lock);
        }
        std::this_thread::sleep_for(std::chrono::seconds(5));
        // Stop offering the service
        app_->stop_offer_service(service_id, service_instance_id);
        // unregister the state handler
        app_->unregister_state_handler();
        // unregister the message handler
        app_->unregister_message_handler(service_id, service_instance_id,
                vsomeip::ANY_METHOD);
        // shutdown the application
        app_->stop();
    }

    void terminate()
	{
        std::lock_guard<std::mutex> its_lock(mutex_);
        stop_ = true;
        condition_.notify_one();
    }

    void on_state_cbk(vsomeip::state_type_e _state)
    {
        if(_state == vsomeip::state_type_e::ST_REGISTERED)
        {
            // we are registered at the runtime and can offer our service
            app_->offer_service(service_id, service_instance_id,0x01,0x01);

			is_offered_ = true;
        }
    }

		struct data_RDA_0ms
	{
		bool wake_network_RDAsecinfo;
		bool wake_network_RDAsecinfo_Ubit;
		bool isUpdated;
		vsomeip::byte_t PaddingGap8_1;
	};

	struct data_RDA_100ms
	{
		bool keep_network_RDAsecinfo;
		bool keep_network_RDAsecinfo_Ubit;
		bool isUpdated;
		vsomeip::byte_t PaddingGap8_1;
	};

	struct data_RDA_20ms
	{
		vsomeip::byte_t BSDSelStssecinfo;
		vsomeip::byte_t LCASelStssecinfo;
		vsomeip::byte_t RDASwStssecinfo;
		bool isUpdated;
	};

	struct data_RDA_50ms
	{
		bool isUpdated;
		vsomeip::byte_t DOWSelStssecinfo;
		vsomeip::byte_t LBSDAndLCAWrnngsecinfo;
		vsomeip::byte_t LDOWWrnngsecinfo;
		vsomeip::byte_t LRCTAWrnngsecinfo;
		vsomeip::byte_t RBSDAndLCAWrnngsecinfo;
		vsomeip::byte_t RCTASelStssecinfo;
		vsomeip::byte_t RDASysStasecinfo;
		vsomeip::byte_t RDOWWrnngsecinfo;
		vsomeip::byte_t RRCTAWrnngsecinfo;
		unsigned short PaddingGap16_1;
	};

	struct data_RDAObs_50ms
	{
		float dx;
		float dy;
		float wObstacle;
		float Vx;
		vsomeip::byte_t ID;
		vsomeip::byte_t PaddingGap8_1;
		unsigned short PaddingGap16_2;
		float wExist;
		vsomeip::byte_t Sync;
		bool isUpdated;
		unsigned short PaddingGap16_3;
		float Vy;
	};

	int Com_SecInfo_RDA_0ms(struct data_RDA_0ms tmp_)
	{
		int ret = 0;

		std::cout << "enter server func:Com_SecInfo_RDA_0ms" << std::endl;

		return ret;
	}

	int Com_SecInfo_RDA_100ms(struct data_RDA_100ms tmp_)
	{
		int ret = 0;

		std::cout << "enter server func:Com_SecInfo_RDA_100ms" << std::endl;

		return ret;
	}

	int Com_SecInfo_RDA_20ms(struct data_RDA_20ms tmp_)
	{
		int ret = 0;

		std::cout << "enter server func:Com_SecInfo_RDA_20ms" << std::endl;

		return ret;
	}

	int Com_SecInfo_RDA_50ms(struct data_RDA_50ms tmp_)
	{
		int ret = 0;
		std::cout << "enter server func:Com_SecInfo_RDA_50ms" << std::endl;
		return ret;
	}

	int Com_SecInfo_RDAObs_50ms(struct data_RDAObs_50ms tmp_)
	{
		int ret = 0;
		std::cout << "enter server func:Com_SecInfo_RDAObs_50ms" << std::endl;
		return ret;
	}

    void on_message_cbk(const std::shared_ptr<vsomeip::message> &_request)
    {
		/*
		std::shared_ptr<vsomeip::payload> pl = _request->get_payload();
        std::string resp = std::string(
                reinterpret_cast<const char*>(pl->get_data()), 0,
                pl->get_length());
        std::cout << "Received: " << resp << std::endl;
		*/
		int mth_id = _request->get_method();

		std::cout<<"method_id 66666666666666666666666666666 : "<<mth_id<<std::endl;

		switch(mth_id)
		{
		case RDA_0ms_method_id:
			{
				std::cout << "enter server func:Com_SecInfo_RDA_0ms" << std::endl;
			}
			break;
		case RDA_100ms_method_id:
			{
				std::cout << "enter server func:Com_SecInfo_RDA_100ms" << std::endl;
			}
			break;
		case RDA_20ms_method_id:
			{
				std::cout << "enter server func:Com_SecInfo_RDA_20ms" << std::endl;
			}
			break;
		case RDA_50ms_method_id:
			{
				std::cout << "enter server func:Com_SecInfo_RDA_50ms" << std::endl;
			}
			break;
		case RDAObs_50ms_method_id:
			{
				std::cout << "enter server func:Com_SecInfo_RDAObs_50ms" << std::endl;
			}
			break;
		default:
			{
				std::cout << "enter server func:default" << std::endl;
			}
			break;
		}
    }

	int MwrProcess_CAN4_RDA_20ms()
	{
		int ret = 0;

		vsomeip::byte_t its_data[4];

        uint32_t its_size = 4;

		its_data[0] = 1;
		its_data[1] = (RDASwStsHSC4_++) % 256;
		its_data[2] = 3;
		its_data[3] = 4;

		payload_->set_data(its_data, its_size);

		std::cout << "Setting event MwrProcess_CAN4_RDA_20ms (Length=" << std::dec << its_size << ")." << std::endl;
		app_->notify(service_id, service_instance_id, (SAMPLE_EVENT_ID_20ms | 0x8000), payload_);

		return ret;
	}

	int MwrProcess_CAN4_RDA_50ms()
	{
		int ret = 0;

		vsomeip::byte_t its_data[12];

        uint32_t its_size = 12;

		its_data[0] = 1;
		its_data[1] = (DOWSelStsHSC4_++) % 256;
		its_data[2] = 3;
		its_data[3] = 4;
		its_data[4] = 5;
		its_data[5] = 6;
		its_data[6] = 7;
		its_data[7] = 8;
		its_data[8] = 9;
		its_data[9] = 10;
		its_data[10] = 11;
		its_data[11] = 12;

		payload_->set_data(its_data, its_size);

		std::cout << "Setting event MwrProcess_CAN4_RDA_50ms (Length=" << std::dec << its_size << ")." << std::endl;
		app_->notify(service_id, service_instance_id, (SAMPLE_EVENT_ID_50ms | 0x8000), payload_);

		return ret;
	}

	void notify()
	{
		static int count = 0;
        while(true)
		{
			if(true == is_offered_)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));////set 1000 to 10

				count++;

				if(0==(count % 2))
				{
					MwrProcess_CAN4_RDA_20ms();
				}

				if(0==(count % 5))
				{
					MwrProcess_CAN4_RDA_50ms();
				}
			}
        }
    }

private:
    std::shared_ptr<vsomeip::runtime> rtm_;
    std::shared_ptr<vsomeip::application> app_;
    bool stop_;
    std::mutex mutex_;
    std::condition_variable condition_;
    std::thread stop_thread_;
	std::thread notify_thread_;

	std::shared_ptr<vsomeip::payload> payload_;
	std::mutex notify_mutex_;
	bool is_offered_;

	vsomeip::byte_t RDASwStsHSC4_;
	vsomeip::byte_t DOWSelStsHSC4_;
};

int main(int argc, char **argv)
{
	printf("changed event id 0x8000 555555555555555555555555555555555555555555555\n");

    saic_service hw_srv;

    if(hw_srv.init())
	{
        hw_srv.start();
        return 0;
    }
	else
	{
        return 1;
    }
}
