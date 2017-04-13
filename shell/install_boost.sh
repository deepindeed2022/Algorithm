#!/bin/bash
# INSTALL DEPENDENCE PACKAGES
sudo apt-get update
sudo apt-get install python-dev mpi-default-dev libicu-dev libbz2-dev --force-yes -y

# DOWNLOAD BOOST
if [! -f "boost_1_61_0.tar.gz"];then
wget https://sourceforge.net/projects/boost/files/boost/1.61.0/boost_1_61_0.tar.gz
fi
tar -xzvf boost_1_61_0.tar.gz
cd boost_1_61_0/


# Run the script which prepares Boost's build process
sudo ./bootstrap.sh --prefix=/usr/local --with-libraries=all
 
# Compile the project
sudo ./b2 install
 
# Add the Boost libraries path to the default Ubuntu library search path
sudo /bin/bash -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/boost.conf'
 
# Update the default Ubuntu library search paths
sudo ldconfig
 
# Return to the parent directory
cd ../
# Inform user that Boost 1.55 was successfully installed
echo "Boost 1.60 was successfully installed."
