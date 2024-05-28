#!/bin/bash
uname -a
grep "physical id" /proc/cpuinfo | wc -l
grep processor /proc/cpuinfo | wc -l
free --mega | awk '$1 == "Mem:" {print $3}'
free --mega | awk '$1 == "Mem:" {print $2}'
free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}'
df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_use += $3} END {print memory_use}'
-m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {total += $2} END {printf("(%d%%)\n"), use/total*100}'
vmstat 1 4 | tail -1 | awk '{print $15}'
who -b | awk '$1 == "system" {print $3 " " $4}'
if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi
ss -ta | grep ESTAB | wc -l
users | wc -w
ip link | grep "link/ether" | awk '{print $2}'
journalctl _COMM=sudo | grep COMMAND | wc -l)
