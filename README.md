## Probabilistic Robotic course project

Project Title: Find that object

### Description: 
We have 2 point clouds acquired with a very accurate depth sensor.

The point cloud: globe-in-scene.txt contains all 3D points of a scene that contains our object.

The point cloud: globe.txt contains only the 3D points of the object we want to find (in a different coordinate frame!).

We want to find the transformation that aligns the globe on the scene.
Make sure to visualize both of the point clouds before starting
and optionally try to perform the alignment manually.

The dataset consists of two txt files:

	globe.txt contains the [x y z] 3D points of the globe object.
  
	globe-in-scene.txt contains the [x y z] 3D points of a scene containing the globe object.
  
Expected output:

Position of the object in the scene


### Prequirements: 
PCL Library , 

### PCL Library:
 <p align="center">
  <img width="200" height="100"  src="https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/blob/master/Tools_Logo/Point_Cloud.png">
  
</p>
 
Download the desired stable version of PCL source from [here](https://github.com/PointCloudLibrary/pcl/releases) .

In this project I use version 1.9.1 .

Installing PCL:

     $ tar xvfj pcl-pcl-1.9.1.tar.gz
     $ cd pcl-pcl-1.7.2 && mkdir build && cd build
     $ cmake ..
     $ ccmake ..
     $ cmake -DCMAKE_BUILD_TYPE=Release ..
     $ make -j2
     $ make -j2 install
     $ sudo make -j2 install
     $ cd pcl-pcl-1.7.2 && mkdir build && cd build
     $ cmake -DCMAKE_BUILD_TYPE=Release ..
     $ make -j2
     $ sudo make -j2 install
     
 For using PCl we need some other Libraries to install as dependency :
 
  <p align="center">
  <img width="150" height="70"  src="https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/blob/master/Tools_Logo/Boost.jpeg">
  <img width="100" height="75" style="margin-left=10px;" src="https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/blob/master/Tools_Logo/Eigen.png">
  <img width="100" height="100" style="margin-left=20px;" src="https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/blob/master/Tools_Logo/VTK.png">
</p>
 
 - [Boost](https://www.boost.org/) -> is a set of libraries that provide support for tasks and structures  such as linear algebra, pseudorandom number generation, multithreading, image processing, regular expressions, and unit testing.
 
 - [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) -> is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.
 
 - [FLANN](https://www.cs.ubc.ca/research/flann/) -> is a library for performing fast approximate nearest neighbor searches in high dimensional spaces.
 
 - [VTK](https://vtk.org/) -> The Visualization Toolkit (VTK) is open source software for manipulating and displaying scientific data.
 
### BOOST Library
Download the source from [here](https://www.boost.org/users/download/).
Installation:

    $ tar xvzf /path/to/boost_1_70_0.tar.gz -C /path/to/somedirectory      // Extract file in specific Directory
    $ cd path/to/boost_1_70_0  // CD inside the extracted file
    $ ./bootstrap.sh --help      // If you need more help to build or compile
    $ ./bootstrap.sh --prefix=path/to/installation/prefix       // Install in specific directory
    $ ./bootstrap.sh              // or Install in current directory
    $ ./b2                 // Build Everything
		       
             
 
 
