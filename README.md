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
