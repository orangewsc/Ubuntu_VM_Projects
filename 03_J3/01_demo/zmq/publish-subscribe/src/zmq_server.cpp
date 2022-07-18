//服务端：
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <zmq.h>

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/tcp.h>
 
using namespace std;

#define PRIORITY 17
int main ()
{
    system("ethtool -K eth0.2 gso off");
    void *context = zmq_ctx_new ();
    void *publisher = zmq_socket (context, ZMQ_PUB);
    int prio=PRIORITY;
    int rc = 0;
    int val=0;
    size_t len_val=sizeof(val);

    rc = zmq_setsockopt(publisher,ZMQ_TOS,&prio,sizeof(prio));
    //rc = zmq_connect (publisher, "tcp://192.168.3.60:5556");
    rc = zmq_bind (publisher, "tcp://*:5556");
    assert (rc == 0);

    if(setsockopt(12,SOL_IP,IP_TOS,&prio,sizeof(prio))<0)
	{
		perror("setsockopt(IP_TOS) failed:");
	}
    
    zmq_getsockopt(publisher,ZMQ_TOS,&val,&len_val);
    
    cout<<"TOS:"<<val<<endl;
    //  Initialize random number generator
    srand(time(0));
    while (1) {
        int zipcode, temperature, relhumidity;
        zipcode     = rand() % 100000;
        temperature = rand() % 215 - 80;
        relhumidity = rand() % 50 + 10;
 
        ostringstream os;
        os << setw(5) << setfill('0')<< zipcode <<" "
           << temperature <<" "<< relhumidity << "\n";
 
        zmq_send(publisher, os.str().c_str(), strlen(os.str().c_str()), 0);
    }
    zmq_close (publisher);
    zmq_ctx_destroy (context);
    return 0;
}