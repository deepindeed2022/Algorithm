#! /bin/sh

sudo apt-get install python-numpy python-scipy python-dev python-pip python-nose g++ libblas-dev git
pip install --upgrade --no-deps git+git://github.com/Theano/Theano.git --user  # Need Theano 0.8(not yet released) or more recent

python -c "import numpy; numpy.test()"
python -c "import scipy; scipy.test()"
# test theano
# python -c "import theano; theano.test()"