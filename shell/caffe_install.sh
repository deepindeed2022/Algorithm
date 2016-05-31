# install caffe with no GPU
cd /caffe
sudo cp Makefile.config.example Makefile.config
mkdir build
cd build
sudo apt-get install cmake -y
cmake ..
make all -j2
make install 
make runtest
