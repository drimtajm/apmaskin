#!/bin/bash

# Installs Apmaskin in specified filesystem directory's "opt" directory
# Execute in "apmaskin/utils" and give Apmaskin's root filesystem folder as first and only argument

if [ $# -eq 1 ] && [ -d $1 ]; then
    sudo mkdir -p $1/opt/apmaskin
    sudo cp -v ../bin/gcc-arm/debug/apmaskin $1/opt/apmaskin
    sudo chown -R root:root $1/opt/apmaskin
fi
