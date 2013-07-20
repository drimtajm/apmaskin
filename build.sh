#!/bin/bash

make VARIANT=DEBUG all && make VARIANT=RELEASE all && make VARIANT=UNIT_TEST all

