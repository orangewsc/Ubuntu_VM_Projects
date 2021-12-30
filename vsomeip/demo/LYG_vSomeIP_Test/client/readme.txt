
export LD_LIBRARY_PATH=/home/root/client
export VSOMEIP_CONFIGURATION=client.json
export VSOMEIP_APPLICATION_NAME=Hello
route add -net 224.0.0.0 netmask 240.0.0.0 dev eth0

./client
