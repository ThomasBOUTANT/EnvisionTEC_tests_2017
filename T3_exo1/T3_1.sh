#!/bin/bash

# BOUTANT Thomas




# Linux kernel version
kernel_version=`uname -r`
echo -e "=== Linux kernel version ===\n $kernel_version"
echo -e "\n"


# IP machines
echo "=== IP machines ==="
ifconfig | perl -nle 's/dr:(\S+)/print $1/e'
echo -e "\n"


# MAC address of the network card
echo "=== MAC address of the network card 'eno1' ==="
cat /sys/class/net/eno1/address #for me, it's "eno1", but it could be something else ("eth0...). We just have to check in the folder /sys/class/net/ the possible names."
echo -e "\n"


# Defines the number of processor cores and displays the current load of each core
echo "=== Number of CPU cores ==="
grep -c '^processor' /proc/cpuinfo
#cat /proc/cpuinfo | grep "siblings" | sort -u | cut -d: -f2

echo "=== Load of each core ==="
mpstat -P ALL 1 1 #'sudo apt install sysstat' for using mpstat
echo -e "\n"


# Number of free, occupied, shared RAM in GB
echo "=== Number of free, occupied, shared RAM ==="
echo -e "\t- in kB: "
grep MemTotal /proc/meminfo     #in kB
grep MemFree /proc/meminfo      #in kB
grep MemAvailable /proc/meminfo #in kB
echo -e "\t- in GB: "
awk '/MemTotal/ { printf "MemTotal: %.3f GB\n", $2/1024/1024 }' /proc/meminfo
awk '/MemFree/ { printf "MemFree: %.3f GB\n", $2/1024/1024 }' /proc/meminfo
awk '/MemAvailable/ { printf "MemAvailable: %.3f GB\n", $2/1024/1024 }' /proc/meminfo
