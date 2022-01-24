#!/bin/sh
export LD_LIBRARY_PATH=/userdata/wsc/J3_3thPart_lib/boost/lib:/userdata/wsc/J3_3thPart_lib/vsomeip3/lib
export VSOMEIP_CONFIGURATION=./client-local.json
export VSOMEIP_APPLICATION_NAME=hello
ifconfig eth0 multicast
route add -net 224.0.0.0 netmask 240.0.0.0 dev eth0
./J3_SOMEIP_Client_Demo
