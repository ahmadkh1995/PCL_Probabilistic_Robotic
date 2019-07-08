
 Project Title: **Find that object**

Goal: **Find the transformation that aligns the globe on the scene**


  <p align="center">
  <img width="300" height="250"  src="https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/blob/master/Globe%20in%20Scene.png">
  <img width="300" height="250" style="margin-left=10px;" src="https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/blob/master/Globe.png">
  
</p>


**Description:**
We have 2 point clouds acquired with a very accurate depth sensor.

The point cloud: globe-in-scene.txt contains all 3D points of a scene that contains our object.

The point cloud: globe.txt contains only the 3D points of the object we want to find (in a different coordinate frame!).

The dataset consists of two txt files:

	globe.txt contains the [x y z] 3D points of the globe object.
  
	globe-in-scene.txt contains the [x y z] 3D points of a scene containing the globe object.
  
**Expected output:** Position of the object in the scene


### Prequirements: 

PCL Library , 

### PCL Library:
 <p align="center">
  <img width="200" height="100"  src="https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/blob/master/Tools_Logo/Point_Cloud.png">
  
</p>
 
Download the stable release of PCL Library from [here](https://github.com/PointCloudLibrary/pcl/releases) .

In this project I use version 1.9.1 .

Installing PCL:

     $ tar xvfj pcl-pcl-1.9.1.tar.gz
     $ cd pcl-pcl-1.9.1 
     $ mkdir build && cd build
     $ cmake ..
     $ cmake -DCMAKE_BUILD_TYPE=Release ..
     $ make -j2
     $ sudo make -j2 install
     
     
 For using PCl we need some other Libraries to install as dependency :
 
  <p align="center">
  <img width="190" height="100"  src="https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/blob/master/Tools_Logo/Boost.jpeg">
  <img width="90" height="90" style="margin-left=10px;" src="https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/blob/master/Tools_Logo/Eigen.png">
  <img width="120" height="110" style="margin-left=20px;" src="https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/blob/master/Tools_Logo/VTK.png">
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
		       

### VTK Library
Download the source from [here](https://vtk.org/download/).
Installation:

    $ tar xvzf /path/to/VTK-8.2.0.tar.gz -C /path/to/somedirectory      // Extract file in specific Directory
    $ cd VTK-8.2.0
    $ mkdir build
    $ cd build
    $ cmake -DCMAKE_BUILD_TYPE=Release ..
    $ make 
    $ sudo make install
 

### Eigen Library
In order to use Eigen,we just need to download and extract Eigen's source code from [here](http://eigen.tuxfamily.org/index.php?title=Main_Page#Download). 
In fact, the header files in the Eigen subdirectory are the only files required to compile programs using Eigen. The header files are the same for all platforms. It is not necessary to use CMake or install anything.

### FLANN Library
Download the source from [here](https://www.cs.ubc.ca/research/flann/).
First extract(Unzip) "flann-1.8.4-src.zip" file .

Installation: (we can also use this [pdf Guide](https://www.cs.ubc.ca/research/flann/uploads/FLANN/flann_manual-1.8.4.pdf):)
           
     $ cd flann-1.8.4-src
     $ mkdir build
     $ cd build
     $ cmake -DCMAKE_BUILD_TYPE=Release ..
     $ make
     $ sudo make install


### My project
  Linking :
 There are two main challenges associated with linking:    
 - Tool configuration, e.g. choosing command-line options or IDE build settings.
 - Identifying the library binary, among all the build variants, whose compile configuration is compatible with the rest of your project.
 
I use CMake to compile and build this project.
Inside the folder [PCL_Robotic](https://github.com/ahmadkh1995/PCL_Probabilistic_Robotic/tree/master/PCL_Robotic)
for connecting the .cpp file to PCL library we should create a CMakeLists.txt and add these lines to it:


      cmake_minimum_required(VERSION 3.0.0)
      project(PCL_Robotic VERSION 0.1 LANGUAGES CXX)
      set(CMAKE_INCLUDE_CURRENT_DIR ON)
      set(CMAKE_AUTOMOC ON)
      find_package(Qt5Core)
      find_package(PCL 1.2 REQUIRED)              //* find PCL package
      include_directories(${PCL_INCLUDE_DIRS})    //* include PCL Directories
      link_directories(${PCL_LIBRARY_DIRS})       //* Link PCL Directories
      add_definitions(${PCL_DEFINITIONS})        //* add PCL definitions
      add_executable(${PROJECT_NAME} "main.cpp")    // add executable "PROJECT_NAME"
      target_link_libraries(${PROJECT_NAME} Qt5::Core)
      target_link_libraries (${PROJECT_NAME} ${PCL_LIBRARIES})    //target link libraries to this project "PROJECT_NAME"
      
then we should create a new folder inside the project folder named "build" :

      $ mkdir build
      $ cd build
      $ cmake -DCMAKE_BUILD_TYPE=Release ..
      $ make
      
 Now we should create PCD files out of give .txt files , so after changing the .txt type to .pcd we should add these header lines to help PCL recognize the pcd files:
 
     # .PCD v.6 - Point Cloud Data file format
     
     VERSION .6
     FIELDS x y z      #in this txt we only have x ,y,z coordinates
     SIZE 4 4 4 
     TYPE F F F 
     COUNT 1 1 1
     WIDTH 17551
     HEIGHT 1
     VIEWPOINT 0 0 0 1 0 0 0
     POINTS 17551         #number of points
     DATA ascii
     
 for run the project (inside the build folder):
 
      $ ./PCL_Robotic


I use ICP to find the transformation between two clouds.

### Iterative closest point (ICP):
(Source : WikiPedia)
- ICP is an algorithm employed to minimize the difference between two clouds of points. ICP is often used to reconstruct 2D or 3D surfaces from different scans, to localize robots and achieve optimal path planning (especially when wheel odometry is unreliable due to slippery terrain), to co-register bone models, etc. 

**Inputs:** reference and source point clouds, initial estimation of the transformation to align the source to the reference (optional), criteria for stopping the iterations.

**Output:** refined transformation.

Essentially, the algorithm steps are:

- For each point (from the whole set of vertices usually referred to as dense or a selection 
    of pairs of vertices from each  model) in the source point cloud, Match the closest point 
    in the reference point cloud (or a selected set).
- Estimate the combination of rotation and translation using a root mean square point to point
    distance metric minimization technique which will best align each source point to its match 
    found in the previous step. This step may also involve weighting points and rejecting outliers 
    prior to alignment.
- Transform the source points using the obtained transformation.
- Iterate (re-associate the points, and so on).

