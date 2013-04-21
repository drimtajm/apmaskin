#!/bin/bash

if [ "$APMASKIN_IP" != "" ] && [ "APMASKIN_USERNAME" != "" ]; then
  echo "Apmaskin IP is: $APMASKIN_IP, pinging..."
  ping -c 1 -W 1 $APMASKIN_IP

  if [ $? != 0 ]; then
    echo "No Apmaskin!"
  else
    echo "Apmaskin is available! Transferring..."
    scp debug/bin/HelloRaspberry $APMASKIN_USERNAME@$APMASKIN_IP:/home/$APMASKIN_USERNAME/apmaskin
  fi
else
  echo "Shell variables 'APMASKIN_IP' and 'APMASKIN_USERNAME' must be set for this to work!"
fi
