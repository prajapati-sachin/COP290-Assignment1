#ifndef FACE3D_LIST
#define FACE3D_LIST

#include <vector>
#include "Edge3d_List.h"
#include "Vertex3d_List.h"
#include "Surface3d_List.h"

using namespace std;

//a face in 2d solid is a vector of 2d edges in which first and last is same
class face2d{
	public:
	//vector of a continous loop of 2D edges which contain a face.
	vector<Edge2d> v;
	//empty constructor
	face2d();
};

/** FaceList :- a list of 2dfaces **/
class Face2d_List{
	public:
	vector<face2d> F;

	//constructor to create a face list from a surface list, edge list and vertex list
	Face2d_List();
	
	//functio2 for adding an face to facelist
	void addFace(face2d face_to_add);

	//function to delete a face from an facelist
	void removeFace(face2d face_to_remove);

	//function to check a face in a facelist
	bool checkFace(face2d face_to_chexk);


};

//a face in 3d solid is a vector of edges in which first and last is same
class face3d{
	public:
	//vector of a continous loop of 3D edges which contain a face.
	vector<Edge3d> loop;

	//constructor for creating a face
	face3d();

	//constructor to create a face from a surface list, edge list and vertex list
	face3d(Surface3d surface, Edge3d_List edge3dList,Vertex3d_List vertexlist);

	//gives the surface of the 3d face
	Surface3d correspondin_surface();

	//the function returns a 2d projection of a face in front plane
	face2d front_projection();

	//the function returns a 2d projection of a face in top plane
	face2d top_projection();

	//the function returns a 2d projection of a face in side plane
	face2d side_projection();

};


/** FaceList :- a list of faces **/
class Face3d_List{
	public:
	vector<face3d> F;
	//constructor to create a face list from a surface list, edge list and vertex list
	Face3d_List();
	
	Face3d_List(Surface_List surfacelist,Edge3d_List edge3dList,Vertex3d_List vertexlist);
	
	//function for adding an face to facelist
	void addFace(face3d face_to_add);

	//function to delete a face from an facelist
	void removeFace(face3d face_to_remove);

	//function to check a face in a facelist
	bool checkFace(face3d face_to_chexk);
};


#endif