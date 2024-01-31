#!/bin/bash

printf "#Architecture : " && uname -a

printf "#CPU physical : " && nproc

printf "#vCPU :" && cat /proc/cpuinfo | grep processor | wc -l

printf "#Memory Usage : " && free -m | grep Mem | awk '{printf("%s/%sMB (%.2f%%)\n"), $3, $2, $3*100/$2}'

printf "#Disk Usage: " && df -Bm | grep /dev/ | grep -v /boot | awk '{fd += $2} {ud += $3} END {printf("%d/%dGb (%d%%)\n", ud, fd/1000, ud*100/fd)}'

printf "#CPU Load: " && top -bn1 | grep '%Cpu' | awk '{printf("%.1f%%\n", $2 + $4)}'

printf "#Last boot: " && who -b | awk '{printf("%s %s\n",$3,$4)}'

printf "#LVM use: " && if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then printf 'no\n'; else printf 'yes\n'; fi

printf "#Connexions TCP: $(ss | grep tcp | grep ESTAB | wc -l) ESTABLISHED\n"

printf "#User log: $(w -h | wc -l)\n"

printf "#Network: IP " && hostname -I | tr -d '\n'  && printf "($(ip link show | grep link/ether | awk '{print $2}'))\n"

printf "#Sudo: $(journalctl | grep COMMAND | wc -l) cmd\n"
