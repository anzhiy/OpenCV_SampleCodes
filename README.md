OpenCV_SampleCodes
==================

Here You Will find Sample Codes of OpenCV written by me.

To compile This code use following guidelines :

1) For Debian Os / Ubuntu
  
	gcc `pkg-config --cflags opencv` filename.cpp -o outputFileName `pkg-config --libs opencv`

2) For Raspberry Pi 

	g++ -O3 -mcpu=arm1176jzf-s -mfpu=vfp -mfloat-abi=hard `pkg-config --cflags opencv` filename.cpp -o outputFileName `pkg-config --libs opencv`
