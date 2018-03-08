#ifndef Face3d_List
#define Face3d_List

#include <vector>
#include "3dstruct.h"

using namespace std;

/** FaceList :- a list of faces **/
class Face3d_List{
	vector<face3d> F;
	
	//function for adding an face to edgelist
	void addFace(face3d face_to_add);

	//function to delete an edge from an edgelist
	void removeFace(face3d face_to_remove);
}

#endif