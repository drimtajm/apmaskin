#!/bin/sh
FILESYSTEM=`readlink -m ../filesystem/`
CFLAGS="-I$FILESYSTEM/include -I$FILESYSTEM/include/dbus-1.0 -I$FILESYSTEM/lib/dbus-1.0/include"
LDFLAGS="-L$FILESYSTEM/lib"
PKG_CONFIG_PATH=$FILESYSTEM/lib/pkgconfig

cd expat-2.0.1
#./configure --host=arm-unknown-linux-gnu --prefix=/
#make -j DESTDIR=$FILESYSTEM 
#make install DESTDIR=$FILESYSTEM 
cd -

cd dbus-1.6.0
#./autogen.sh
#./configure  --host=arm-unknown-linux-gnu ac_cv_have_abstract_sockets=yes --disable-dnotify --prefix=/  --with-x=no "CFLAGS=$CFLAGS" "LDFLAGS=$LDFLAGS"
#make -j DESTDIR=$FILESYSTEM 
#make install DESTDIR=$FILESYSTEM 
cd -

cd bluez-libs-3.36
#./configure --host=arm-unknown-linux-gnu --disable-glib  --prefix=/  "CFLAGS=$CFLAGS" "LDFLAGS=$LDFLAGS" 
#make -j DESTDIR=$FILESYSTEM 
#make install DESTDIR=$FILESYSTEM 
cd -

cd bluez-utils-3.36
./configure --host=arm-unknown-linux-gnu --disable-glib --disable-pie --prefix=/ "CFLAGS=$CFLAGS" "LDFLAGS=$LDFLAGS" "PKG_CONFIG_PATH=$PKG_CONFIG_PATH"
make -j DESTDIR=$FILESYSTEM 
make install DESTDIR=$FILESYSTEM 
cd -
