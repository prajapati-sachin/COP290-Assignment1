#ifndef Vertex2d_List
#define Vertex2d_List

#include <vector>
#include "2dstruct.h"

using namespace std;

/** VertexList :- a list of vertices **/
class Vertex2d_List{
	vector<coordinates2d> E;

	//function for adding an vertex to vertexlist
	void addVertex (coordinate2d vertex_to_add);

	//function to delete an vertex from an vertexlist
	void removeVertex (coordinate2d vertex_to_remove);
}

#endif