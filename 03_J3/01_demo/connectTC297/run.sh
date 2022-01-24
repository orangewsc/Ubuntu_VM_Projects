#!/bin/sh

export LD_LIBRARY_PATH=/userdata/wsc/J3_3thPart_lib/boost/boost_1.65/lib:/userdata/wsc/J3_3thPart_lib/boost/boost_1.74/lib:/userdata/wsc/J3_3thPart_lib/vsomeip/vsomeip2/lib:/userdata/wsc/J3_3thPart_lib/vsomeip/vsomeip3/lib
export VSOMEIP_CONFIGURATION=./client-local.json
export VSOMEIP_APPLICATION_NAME=hello
ifconfig eth0 multicast
route add -net 224.0.0.0 netmask 240.0.0.0 dev eth0
./connectTC297
