#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
 
int main (void)
{
    printf ("Connecting to hello world server\n");
    void* context = zmq_ctx_new();
    void* client = zmq_socket(context, ZMQ_REQ); 
    zmq_connect(client, "tcp://localhost:5555");
    zmq_connect(client, "tcp://localhost:6666");
    
    char buffer[10]={0};
    int request_nbr = 0;
    while(1)
    {
       zmq_send(client, "hello", 9, 0);
       printf("client send [hello]\n");
       memset(buffer, 0x00, 10);
       zmq_recv(client, buffer, 10, 0);
       printf("client recv [%s]\n", buffer); 
    }
    zmq_close(client);
    zmq_ctx_destroy(context);
    
    return 0;
}
