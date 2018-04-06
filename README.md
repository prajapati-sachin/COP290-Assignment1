# Module for Engineering Drawing
This module can be used to:-
1) Generate 2D projections from an OBJ (.obj) file.
![Projections](/doc/3d-2d.png?raw=true "Projections")
2) Regenerate Isometric View of Object from orthographic projections.
![Isometric view of object](/doc/2d-3d.png?raw=true "Isometric view of object")

### Installing

	The GUI folder contains an standalone executable named "app" which can run on Linux systems. 
	Make the app executable by running 

	chmod a+x app

	in the GUI folder.
	
	
#### Terminal based application ####
```
make
./main "path_to_file"

```

## Input Format
1) Input for 3D-2D is a OBJ (.obj) file (with only vertices and faces specified and no other specifications), some demos are in examples folder.
2) Input for 2D-3D is a text file which contains the information about projections in 3 views (front, top, side views). The text file contains the position of vertices and edges for each projection. Some demo files are in the examples folder.


fv 1 0 -> denotes a vertex (1,0) in front projection and similarly for tv and sv which denote vertex in top and side view respectively.  


fe 2 3 -> denotes an edge between 2nd and 3rd vertex in front projection and similarly for te and se which denote edges in top and side view respectively.

## Authors

* **[Sachin Kumar Prajapati](https://github.com/prajapati-sachin)**
* **[Pranav Bhagat](https://github.com/pranavbhagat5)**
