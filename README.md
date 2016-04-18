# The Fastest Pedetrian Detector in the West (FPDW)
This is my version of the Fastest Pedestrian Detector in the West based on the paper:
* P. Dollár, S. Belongie and P. Perona "_The Fastest Pedestrian Detector in the West_", BMVC 2010.

This version implements only the detection part. For the training part you have to use the P. Dollàr toolbox ([link](https://github.com/pdollar/toolbox/tree/master/detector)).

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

##How to use

###MATLAB - Training
In the file _acfDemoInria_, after the line:
```matlab
detector = acfTrainIntegral( opts );
```

add this code:
```matlab
filename = 'models/inria_detector.xml';
isTrained = exist(filename,'file');
if( ~isTrained )
    savetoxml(detector, 'models/inria_detector.xml');
end
```

###C++ - Detection
Go to the bin diretory and launch the program with the following command:
```bash
./fpdw ../detector/inria_detector.xml /path/to/the/image.jpg
```
