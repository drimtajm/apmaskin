#!/bin/bash

if [ "$APMASKIN_IP" != "" ]; then
  echo "Apmaskin IP is: $APMASKIN_IP, pinging..."
  ping -c 1 -W 1 $APMASKIN_IP

  if [ $? != 0 ]; then
    echo "No Apmaskin!"
  else
    echo "Apmaskin is available! Transferring..."
    scp debug/bin/HelloRaspberry pi@$APMASKIN_IP:/home/pi/apmaskin
  fi
else
  echo "Shell variable 'APMASKIN_IP' must be set for this to work!"
fi
