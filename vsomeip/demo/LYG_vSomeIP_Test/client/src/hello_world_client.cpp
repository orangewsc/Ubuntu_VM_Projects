#ifndef VSOMEIP_ENABLE_SIGNAL_HANDLING
#include <csignal>
#endif
#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include <thread>

static vsomeip::service_t service_id = 0x4001;
static vsomeip::instance_t service_instance_id = 0x4e21;

static vsomeip::method_t RDA_0ms_method_id = 0x1001;
static vsomeip::method_t RDA_100ms_method_id = 0x1002;
static vsomeip::method_t RDA_20ms_method_id = 0x1003;
static vsomeip::method_t RDA_50ms_method_id = 0x1004;
static vsomeip::method_t RDAObs_50ms_method_id = 0x1005;

#define SAMPLE_EVENTGROUP_ID	0xa
#define SAMPLE_EVENT_ID_20ms	0x1007
#define SAMPLE_EVENT_ID_50ms	0x1008

class saic_client
{
public:
    // Get the vSomeIP runtime and
    // create a application via the runtime, we could pass the application name
    // here otherwise the name supplied via the VSOMEIP_APPLICATION_NAME
    // environment variable is used
    saic_client() :
                    rtm_(vsomeip::runtime::get()),
                    app_(rtm_->create_application()),
					ffsend_(std::bind(&saic_client::send, this))
    {
		availability_ = false;
    }

    bool init(){
        // init the application
        if (!app_->init())
		{
            std::cerr << "Couldn't initialize application" << std::endl;
            return false;
        }

        // register a state handler to get called back after registration at the
        // runtime was successful
        app_->register_state_handler(
                std::bind(&saic_client::on_state_cbk, this,
                        std::placeholders::_1));

        // register a callback for responses from the service
        app_->register_message_handler(vsomeip::ANY_SERVICE,
                service_instance_id, vsomeip::ANY_METHOD,
                std::bind(&saic_client::on_message_cbk, this,
                        std::placeholders::_1));

        // register a callback which is called as soon as the service is available
        app_->register_availability_handler(service_id, service_instance_id,
                std::bind(&saic_client::on_availability_cbk, this,
                        std::placeholders::_1, std::placeholders::_2,
                        std::placeholders::_3));

		std::set<vsomeip::eventgroup_t> its_groups;
        its_groups.insert(SAMPLE_EVENTGROUP_ID);
        app_->request_event(
                service_id,
                service_instance_id,
                SAMPLE_EVENT_ID_20ms,
                its_groups,
                true);

		app_->request_event(
				service_id,
				service_instance_id,
				SAMPLE_EVENT_ID_50ms,
				its_groups,
				true);

        app_->subscribe(service_id, service_instance_id, SAMPLE_EVENTGROUP_ID);

        return true;
    }

    void start()
    {
        // start the application and wait for the on_event callback to be called
        // this method only returns when app_->stop() is called
        app_->start();
    }

    void on_state_cbk(vsomeip::state_type_e _state)
    {
        if(_state == vsomeip::state_type_e::ST_REGISTERED)
        {
            // we are registered at the runtime now we can request the service
            // and wait for the on_availability callback to be called
            app_->request_service(service_id, service_instance_id);

			std::cout << "on_state_cbk 11111111111"<<std::endl;
        }
    }

    void on_availability_cbk(vsomeip::service_t _service,
            vsomeip::instance_t _instance, bool _is_available)
    {
        // Check if the available service is the the hello world service
        if(service_id == _service && service_instance_id == _instance
                && _is_available)
        {
			availability_ = true;

			std::cout << "on_availability_cbk 2222222222222222"<<std::endl;
        }
    }

    void on_message_cbk(const std::shared_ptr<vsomeip::message> &_response)
    {
		int svc_id = _response->get_service();
		int ins_id = _response->get_instance();
		int mth_id = _response->get_method();


		// Get the payload and print it
		if(service_instance_id == _response->get_instance())
		{
			std::cout << "on_message_cbk 888888888888888888888  "<<svc_id<<std::endl<<ins_id<<std::endl<<mth_id<<std::endl;

			std::shared_ptr<vsomeip::payload> pl = _response->get_payload();
//			std::string resp = std::string(
//					reinterpret_cast<const char*>(pl->get_data()), 0,
//					pl->get_length());
			int len = pl->get_length();
			std::cout << "Received: " << len << std::endl;
		}

		/*
        if(service_id == _response->get_service()
                && service_instance_id == _response->get_instance()
                && vsomeip::message_type_e::MT_RESPONSE
                        == _response->get_message_type()
                && vsomeip::return_code_e::E_OK == _response->get_return_code())
        {
            // Get the payload and print it
            std::shared_ptr<vsomeip::payload> pl = _response->get_payload();
            std::string resp = std::string(
                    reinterpret_cast<const char*>(pl->get_data()), 0,
                    pl->get_length());
            std::cout << "Received: " << resp << std::endl;
        }
		*/
    }

    void stop()
    {
        // unregister the state handler
        app_->unregister_state_handler();
        // unregister the message handler
        app_->unregister_message_handler(vsomeip::ANY_SERVICE,
                service_instance_id, vsomeip::ANY_METHOD);
        // alternatively unregister all registered handlers at once
        app_->clear_all_handler();
        // release the service
        app_->release_service(service_id, service_instance_id);
        // shutdown the application
        app_->stop();
    }

	int Com_SecInfo_RDA_0ms()
	{
		int ret = 0;

		static vsomeip::byte_t comInfo_RDA_0ms = 0;

		vsomeip::byte_t its_data[4];

        uint32_t its_size = 4;

		for(int i = 0;i< its_size;i++)
		{
			its_data[i] = 1;
		}

		std::shared_ptr<vsomeip::message> rq = rtm_->create_request();

		// Set the hello world service as target of the request
		rq->set_service(service_id);
		rq->set_instance(service_instance_id);
		rq->set_method(RDA_0ms_method_id);

		// Create a payload which will be sent to the service
		std::shared_ptr<vsomeip::payload> payload_ = rtm_->create_payload();

		payload_->set_data(its_data, its_size);

		rq->set_payload(payload_);

		std::cout << "Sending: " << "Com_SecInfo_RDA_0ms" << std::endl;

		app_->send(rq, true);

		return ret;
	}

	int Com_SecInfo_RDA_100ms()
	{
		int ret = 0;

		static vsomeip::byte_t comInfo_RDA_100ms = 0;

		vsomeip::byte_t its_data[4];

        uint32_t its_size = 4;

		for(int i = 0;i< its_size;i++)
		{
			its_data[i] = 1;
		}

		std::shared_ptr<vsomeip::message> rq = rtm_->create_request();

		// Set the hello world service as target of the request
		rq->set_service(service_id);
		rq->set_instance(service_instance_id);
		rq->set_method(RDA_100ms_method_id);

		// Create a payload which will be sent to the service
		std::shared_ptr<vsomeip::payload> payload_ = rtm_->create_payload();

		payload_->set_data(its_data, its_size);

		rq->set_payload(payload_);

		std::cout << "Sending: " << "Com_SecInfo_RDA_100ms" << std::endl;

		app_->send(rq, true);

		return ret;
	}

	int Com_SecInfo_RDA_20ms()
	{
		int ret = 0;

		static vsomeip::byte_t comInfo_RDA_20ms = 0;

		vsomeip::byte_t its_data[4];

        uint32_t its_size = 4;

		for(int i = 0;i< its_size;i++)
		{
			its_data[i] = 1;
		}

		std::shared_ptr<vsomeip::message> rq = rtm_->create_request();

		// Set the hello world service as target of the request
		rq->set_service(service_id);
		rq->set_instance(service_instance_id);
		rq->set_method(RDA_20ms_method_id);

		// Create a payload which will be sent to the service
		std::shared_ptr<vsomeip::payload> payload_ = rtm_->create_payload();

		payload_->set_data(its_data, its_size);

		rq->set_payload(payload_);

		std::cout << "Sending: " << "Com_SecInfo_RDA_20ms" << std::endl;

		app_->send(rq, true);

		return ret;
	}

	int Com_SecInfo_RDA_50ms()
	{
		int ret = 0;

		static vsomeip::byte_t comInfo_RDA_50ms = 0;

		vsomeip::byte_t its_data[12];

        uint32_t its_size = 12;

		for(int i = 0;i< its_size;i++)
		{
			its_data[i] = 1;
		}

		std::shared_ptr<vsomeip::message> rq = rtm_->create_request();

		// Set the hello world service as target of the request
		rq->set_service(service_id);
		rq->set_instance(service_instance_id);
		rq->set_method(RDA_50ms_method_id);

		// Create a payload which will be sent to the service
		std::shared_ptr<vsomeip::payload> payload_ = rtm_->create_payload();

		payload_->set_data(its_data, its_size);

		rq->set_payload(payload_);

		std::cout << "Sending: " << "Com_SecInfo_RDA_50ms" << std::endl;

		app_->send(rq, true);

		return ret;
	}

	int Com_SecInfo_RDAObs_50ms()
	{
		int ret = 0;

		static vsomeip::byte_t comInfo_RDAObs_50ms = 0;

		vsomeip::byte_t its_data[32];

        uint32_t its_size = 32;

		for(int i = 0;i< its_size;i++)
		{
			its_data[i] = 1;
		}

		std::shared_ptr<vsomeip::message> rq = rtm_->create_request();

		// Set the hello world service as target of the request
		rq->set_service(service_id);
		rq->set_instance(service_instance_id);
		rq->set_method(RDA_50ms_method_id);

		// Create a payload which will be sent to the service
		std::shared_ptr<vsomeip::payload> payload_ = rtm_->create_payload();

		payload_->set_data(its_data, its_size);

		rq->set_payload(payload_);

		std::cout << "Sending: " << "Com_SecInfo_RDAObs_50ms" << std::endl;

		app_->send(rq, true);

		return ret;
	}

	void send()
	{
		static int count = 0;
        while(true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));////set 1000ms to 10ms

			count++;

			if(true == availability_)
			{
				if((count % 2) == 0)
				{
					Com_SecInfo_RDA_20ms();
				}

				if((count % 5) == 0)
				{
					Com_SecInfo_RDA_50ms();
					Com_SecInfo_RDAObs_50ms();
				}

				if((count % 10) == 0)
				{
					Com_SecInfo_RDA_100ms();
				}
			}
        }
    }

private:
    std::shared_ptr<vsomeip::runtime> rtm_;
    std::shared_ptr<vsomeip::application> app_;

	std::thread ffsend_;
	bool availability_;
};

int main(int argc, char **argv)
{
    saic_client hw_cl;

    if (hw_cl.init())
	{
        hw_cl.start();
        return 0;
    }
	else
	{
        return 1;
    }
}
