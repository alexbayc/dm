echo `ifconfig en0 | awk '(NR == 5)' | cut -b 7- | cut -b -15` > ./scripts/rez_whoami.txt
