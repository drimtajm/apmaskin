#!/bin/bash
COMPILER=arm-unknown-linux-gnu-
make -j2 arch=arm CROSS_COMPILE=$COMPILER
make -j2 modules arch=arm CROSS_COMPILE=$COMPILER
sudo make CROSS_COMPILE=$COMPILER INSTALL_MOD_PATH=../filesystem arch=arm  modules_install
mkdir -p ../filesystem/boot
mkdir -p ../filesystem/proc
sudo cp arch/arm/boot/zImage ../filesystem/boot/Image
sudo cp ../bootloader/* ../filesystem/boot/
