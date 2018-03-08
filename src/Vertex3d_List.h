#ifndef VERTEX3D_LIST
#define VERTEX3D_LIST

#include <vector>
#include "3dstruct.h"

using namespace std;

/** VertexList :- a list of vertices **/
class Vertex3d_List{
	vector<coordinates3d> E;

	//function for adding an vertex to vertexlist
	void addVertex (coordinate3d vertex_to_add);

	//function to delete an vertex from an vertexlist
	void removeVertex (coordinate3d vertex_to_remove);
}

#endif