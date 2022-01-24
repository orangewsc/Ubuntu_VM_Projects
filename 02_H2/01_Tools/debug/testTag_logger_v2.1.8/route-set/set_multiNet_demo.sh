#!/bin/bash


sudo route del default gw 192.168.8.1
#sudo route del default dev enp0s25

#sudo ifconfig enp0s25  MULTICAST

sudo route add -net 224.0.0.0 netmask 240.0.0.0 dev enp0s25


exit 0

#------

sudo route add -net 192.168.8.0/24 gw 192.168.8.1 dev enp0s25 

sudo route del default gw 192.168.43.1
sudo route add default gw 192.168.43.1


测试服务器：

http://106.14.92.22:8890


https://atd-idevops.fin-shine.com



Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
0.0.0.0         192.168.43.1    0.0.0.0         UG    600    0        0 wlo1
169.254.0.0     0.0.0.0         255.255.0.0     U     1000   0        0 wlo1
192.168.8.0     0.0.0.0         255.255.255.0   U     100    0        0 enp0s25
192.168.43.0    0.0.0.0         255.255.255.0   U     600    0        0 wlo1


0.0.0.0         192.168.43.1    0.0.0.0         UG    600    0        0 wlo1
169.254.0.0     0.0.0.0         255.255.0.0     U     1000   0        0 wlo1
192.168.8.0     0.0.0.0         255.255.255.0   U     100    0        0 enp0s25
192.168.43.0    0.0.0.0         255.255.255.0   U     600    0        0 wlo1
224.0.0.0       0.0.0.0         240.0.0.0       U     0      0        0 enp0s25

先设外网，再设内网



