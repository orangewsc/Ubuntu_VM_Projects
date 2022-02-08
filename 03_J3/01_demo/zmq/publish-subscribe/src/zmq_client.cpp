 
//客户端：
#include <iostream>
#include <string>
#include <cstring>
#include <assert.h>
#include <zmq.h>
 
using namespace std;
 
int main (int argc, char *argv [])
{
    //  Socket to talk to server
    printf ("Collecting updates from weather server...\n");
    void *context = zmq_ctx_new ();
    void *subscriber = zmq_socket (context, ZMQ_SUB);
    int rc = zmq_connect (subscriber, "tcp://localhost:5556");
    assert (rc == 0);
 
    char filter1[] = "10001 ";
    char filter2[] = "20002 ";
    rc = zmq_setsockopt (subscriber, ZMQ_SUBSCRIBE,filter1, strlen (filter1));
    assert (rc == 0);
    rc = zmq_setsockopt (subscriber, ZMQ_SUBSCRIBE,filter2, strlen (filter2));
    assert (rc == 0);
 
    //  Process 100 updates
    int size;
    char buffer [256];
    while (1) {
 
        memset(buffer, 0, 256*sizeof(char));
        size = zmq_recv (subscriber, buffer, 255, 0);
        if (size == -1){
            cout<< "receiver error , skip this message"<<endl;
            continue;
        }
        buffer[size] = '\0';
        cout << buffer <<endl;
    }
 
    zmq_close (subscriber);
    zmq_ctx_destroy (context);
    return 0;
}

