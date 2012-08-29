#!/bin/bash
target=$1
source="filesystem"
if [ -d "$target" ] 
then
    rm ${target}/dev/* -rf
    mkdir -p ${target}/dev
    sudo mknod ${target}/dev/console c 5 1 
    sudo mknod ${target}/dev/null c 1 3
    sudo mknod ${target}/dev/ttyAM0 c 204 14
    sudo chown root.root ${source}/bin/busybox && sudo chmod +s ${source}/bin/busybox
    sudo rsync -rav ${source}/* ${target}
    sudo rsync -rav /opt/crosstool/gcc-4.0.1-glibc-2.3.5/arm-unknown-linux-gnu/arm-unknown-linux-gnu/lib ${target}
    sudo rsync -rav /opt/crosstool/gcc-4.0.1-glibc-2.3.5/arm-unknown-linux-gnu/arm-unknown-linux-gnu/bin ${target}
    sudo rsync -rav apmaskin/rootfs/* ${target}
else
    echo ERROR! - ${target} is not a directory
fi
