#include <connectTC297.h>


int main()
{
    app=vsomeip::runtime::get()->create_application("hello");
    app->init();
    app->register_availability_handler(SAMPLE_SERVICE_ID,SAMPLE_INSTANCE_ID,on_availability);
    app->request_service(SAMPLE_SERVICE_ID,SAMPLE_INSTANCE_ID);
    // app->register_message_handler(vsomeip::ANY_SERVICE, vsomeip::ANY_INSTANCE, vsomeip::ANY_METHOD, on_message);
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENT_ID, on_message);
    std::thread sender(run);
    app->start();
}
