# The Fastest Pedetrian Detector in the West (FPDW)
This is my version of the Fastest Pedestrian Detector in the West based on the paper:
* P. Dollár, S. Belongie and P. Perona "_The Fastest Pedestrian Detector in the West_", BMVC 2010.

This version implements only the detection part. The training part is the one developed in the P. Dollàr toolbox ([link](https://github.com/pdollar/toolbox/tree/master/detector)).

##Requirements
* OpenCv
* OpenMP
* SSE
* Boost

## How to build

FPDW works under Linux and Mac Os environments. I recommend a so-called out of source build 
which can be achieved by the following command sequence:

* mkdir build
* cd build
* cmake ../
* make -j\<number-of-cores+1\>

