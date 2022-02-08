#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
 
int main (void)
{
    /*  Socket to talk to clients */
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5555");
    int rc1 = zmq_bind (responder, "tcp://*:6666");
    assert (rc == 0);
 
    while (1) {
        char buffer [10];
	    memset(buffer, 0x00, sizeof(buffer));
        rc = zmq_recv (responder, buffer, 10, 0);
        //buffer[rc]=0;
        printf ("server Received [%s]rc[%d]\n", buffer, rc);
        sleep (1);          //  Do some 'work'
        zmq_send (responder, "World1234", 9, 0);
        printf("server send [world]\n");
    }
    return 0;
}
