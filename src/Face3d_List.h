#ifndef FACE3D_LIST
#define FACE3D_LIST

#include <vector>
#include "Common_functions.h"
#include "Edge3d_List.h"
#include "Vertex3d_List.h"
#include "Surface3d_List.h"

using namespace std;

//a face in 2d solid is a vector of 2d edges in which first and last is same
class face2d{
	//vector of a continous loop of 2D edges which contain a face.
	vector<Edge2d> v;

	face2d();
};

//a face in 3d solid is a vector of edges in which first and last is same
class face3d{
	//vector of a continous loop of 3D edges which contain a face.
	vector<Edge3d> loop;

	//constructor for creating a face
	face3d();

	//constructor to create a face from a surface list, edge list and vertex list
	face3d(Surface3d surface, Edge3d_List edge3dList,Vertex3d_List vertexlist);

};


/** FaceList :- a list of faces **/
class Face3d_List{
	vector<face3d> F;

	//constructor to create a face list from a surface list, edge list and vertex list
	Face3d_List(Surface_List surfacelist,Edge3d_List edge3dList,Vertex3d_List vertexlist);
	
	//function for adding an face to facelist
	void addFace(face3d face_to_add);

	//function to delete a face from an facelist
	void removeFace(face3d face_to_remove);



};

#endif