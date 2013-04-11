#!/bin/bash
COMPILER=arm-unknown-linux-gnu-

if [ $# -eq 1 ] && [ -d $1 ]; then
    make -j2 arch=arm CROSS_COMPILE=$COMPILER
	make -j2 modules arch=arm CROSS_COMPILE=$COMPILER
	sudo make CROSS_COMPILE=$COMPILER INSTALL_MOD_PATH=$1 arch=arm  modules_install
	mkdir -p $1/proc
	sudo cp arch/arm/boot/zImage $1/boot/Image
else
	echo "Error: Give target filesystem directory as first and only parameter"
fi
