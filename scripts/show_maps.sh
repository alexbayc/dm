touch ./scripts/rez_maps.txt
echo `ls -1 ./.net_maps/ | wc -l` > ./scripts/rez_maps.txt
ls -1 ./.net_maps/ >> ./scripts/rez_maps.txt