#!/bin/bash

sudo apt-get -y update
sudo apt-get -y upgrade
sudo apt-get -y dist-upgrade
sudo apt-get -y autoremove


# INSTALL THE DEPENDENCIES
# Build tools:
sudo apt-get install -y build-essential cmake

# INSTALL python science package
sudo apt-get install -y python-dev gfortran
sudo apt-get install -y python-numpy
sudo apt-get install -y python-scipy

# INSTALL OPENCV
sudo apt-get install -y libopencv-* --force-yes
sudo apt-get install -y python-opencv
