echo -n "$(cat pas.dat)" | md5sum | awk '{print $1}' > hash.dat
