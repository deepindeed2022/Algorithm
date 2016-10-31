#!/bin/bash

# Test the fuchsia kernal magenta in Linux ubuntu 4.4.0-34-generic x86_64 x86_64 x86_64 GNU/Linux for Ubuntu16.04LTS
# BY: Clython
# Date: 2016-9-27

# Prepare dependencies package in ubuntu
sudo apt-get -y update
sudo apt-get install -y texinfo libglib2.0-dev autoconf libtool libsdl-dev build-essential
sudo apt-get install -y bison flex


export SRC=$(pwd)
# clone kernal source 
git clone https://github.com/fuchsia-mirror/magenta.git

cd  $SRC/magenta
# prebuild the toolchain for gcc compiler
./scripts/download-toolchain

# If the prebuilt toolchain binaries do not work for you, there are a set of scripts which 
# will download and build suitable gcc toolchains for building Magenta for ARM32, ARM64, 
# and x86-64 architectures:
# cd $SRC
# git clone https://fuchsia.googlesource.com/third_party/gcc_none_toolchains toolchains
# cd toolchains
# ./doit -a 'arm aarch64 x86_64' -f -j32



# Build Qemu for testing in virtual machine, if you're only testing on actual
# hardware, skit this.
# If you don't want to install in /usr/local (the default), which will require 
# you to be root, add --prefix=/path/to/install (perhaps $HOME/qemu) and then you'll need to add /path/to/install/bin to your PATH.
cd $SRC
git clone https://fuchsia.googlesource.com/third_party/qemu
cd qemu
./configure --target-list=arm-softmmu, aarch64-softmmu, x86_64-softmmu
make -j8
sudo make install

cd $SRC/magenta

export PATH=$PATH:$SRC/toolchains/aarch64-elf-5.3.0-Linux-x86_64/bin
export PATH=$PATH:$SRC/toolchains/x86_64-elf-5.3.0-Linux-x86_64/bin
#build for x86-64
make -j8 magenta-pc-x86-64
# for aarch64
# make -j32 magenta-qemu-arm64
echo "BUILD magenta Success, the mirror file in $(pwd)/build-magenta-pc-x86-64"
cd $SRC

##run magenta
# cd $SRC/magenta 
# ./scripts/run-magenta-x86-64