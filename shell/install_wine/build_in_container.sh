#!/bin/sh

###################### IN CONTAINER ####################################
# The wine source should be set in the host machine
# before runing this script, you should have executed the install_wine.sh
# Author: Clython
# Date: 2016-10-26

# set base dir before runing
SOURCE_DIR=/home/ubuntu/repo
WINE32=$SOURCE_DIR/wine32
WINE64=$SOURCE_DIR/wine64
WINE32_TOOLS=$SOURCE_DIR/wine32-tools

# DEBUG=1 ## comment using debug, else delete comment

if [ -n "$DEBUG" ];then
        apt-get -y update
        apt-get -y upgrade
        apt-get -y install python-software-properties git-core
        apt-get -y build-dep wine
        apt-get update
fi
# build wine tools, just get the tools
if [ -d $WINE32_TOOLS ];then
	cd $WINE32_TOOLS
	chmod +x configure
	./configure
	make -j8
fi
if [ $? -eq 0 ];then
	# build wine32 
        mkdir $WINE32/build
	cd $WINE32/build
	. ../configure --with-wine64=$WINE64 --with-wine-tools=$WINE32_TOOLS
	make -j8
	if [ $? -eq 0 ];then
		# Add authority of execute shell script
		chmod -R +x $WINE32/tools
		make install
	fi
	if [ $? -eq 0 ]; then
		sudo shutdown -h now
	fi
else
	echo "Ooh, build failed!"
fi
