#include <J3_SOMEIP_Server_Demo.h>


int main()
{
    app=vsomeip::runtime::get()->create_application("world");
    const vsomeip::byte_t its_data[] = {0x10,0x20,0x30,0x40,0x50};
    std::shared_ptr<vsomeip::payload> its_payload = vsomeip::runtime::get()->create_payload();
    its_payload->set_data(its_data,sizeof(its_data));
    std::set<vsomeip::eventgroup_t> its_groups;
    its_groups.insert(SAMPLE_EVENTGROUP_ID);


    app->init();
    //app->register_message_handler(SAMPLE_SERVICE_ID,SAMPLE_INSTANCE_ID,SAMPLE_EVENT_ID,on_message);
    app->offer_service(SAMPLE_SERVICE_ID,SAMPLE_INSTANCE_ID);
    app->offer_event(SAMPLE_SERVICE_ID,SAMPLE_INSTANCE_ID,SAMPLE_EVENT_ID,its_groups);

    std::thread sender(run,its_payload);

    app->start();
}