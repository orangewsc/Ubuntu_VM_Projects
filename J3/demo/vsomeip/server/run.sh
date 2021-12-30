#!/bin/sh
export VSOMEIP_CONFIGURATION=../server-local.json
export VSOMEIP_APPLICATION_NAME=world
sudo ifconfig ens33 multicast
sudo route add -net 224.0.0.0 netmask 240.0.0.0 dev ens33
cd bin/ && ./J3_SOMEIP_Server_Demo
