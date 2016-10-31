#!/bin/sh

# configure the source code path

SOURCE_DIR=/home/iscas/Repo
WINE64=$SOURCE_DIR/wine64
WINE32=$SOURCE_DIR/wine32
WINE32_TOOLS=$SOURCE_DIR/wine32-tools

ubuntu32=ubuntu32bit
# If you want runnig ,del comment before DEBUG=1
# DEBUG=1
# add repository
if [ -n "$DEBUG" ];then
	sudo apt-get -y install g++ vim-gnome 
	sudo apt-get -y install ppa-purge git 
	sudo ppa-purge ppa:ubuntu-wine/ppa
	sudo apt-get -y update

	# install dependencies
	# make sure that the BaseSoftware source is http://archive.ubuntu.com/ubuntu
	# otherwise, the ppa:ubuntu-wine/ppa could work.

	echo "ppa:ubuntu-wine/ppa have enable? Y/N"
	read enable
	if [ "$enable" = "Y" ];then
	  sudo apt-get -y build-dep wine
	  # chang user as sudo mode
	  if [ -d $WINE64 ]; then
		 cd $WINE64
		 chmod +x configure
		 ./configure --enable-win64
		 make -j8
		 cd 
	  fi
	else
	   echo "Please enable ppa install"
	   exit 0
	fi


	############################## Create Container #########################################


	sudo apt-get -y install lxc lxctl lxc-templates

	echo "check wich folder contains your template\n"
	select path in "/usr/share/lxc/templates/" "/etc/lxc/templates/" "NO Create!"; do
		break
	done
	if [ -n "$path" ];then 
	   sudo lxc-create -n $ubuntu32 -t /usr/share/lxc/templates/lxc-download
	elif [ $path -eq "/usr/share/lxc/templates" ]; then
	   sudo lxc-create -n $ubuntu32 -t /usr/share/lxc/templates/lxc-download 
	elif [ $path -eq "/etc/lxc/templates/" ]; then 
	   sudo lxc-create -n $ubuntu32 -t /etc/lxc/templates/lxc-download
	fi
fi
CONTAINER_ROOTFS=/var/lib/lxc/$ubuntu32/rootfs

if [ -n "$DEBUG" ];then
	# lxc-destroy -n containtername
	# I downlaod the image "ubuntu	trusty	i386
	echo "Using host machine configure as $ubuntu32 config"
	sudo cp -R /etc/apt $CONTAINER_ROOTFS/etc 
fi

if [ -d $SOURCE_DIR ];then
#   	sudo su
  	mkdir $CONTAINER_ROOTFS/home/ubuntu/repo
    echo "$CONTAINER_ROOTFS/home/ubuntu/repo to $SOURCE_DIR"
  	mount --bind $SOURCE_DIR $CONTAINER_ROOTFS/home/ubuntu/repo
  	# Start the container and log in with your username and password.
   	echo "start container operation system, and log in"
   	lxc-start -n $ubuntu32
   	lxc-attach -n $ubuntu32
fi

echo "NOW, You could runing script build_in_container.sh in $ubuntu32"

