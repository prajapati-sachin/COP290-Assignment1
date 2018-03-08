#ifndef Edge3d_List
#define Edge3d_List

#include <vector>
#include "3dstruct.h"

using namespace std;

/** EdgeList :- a list of edges **/
class Edge3d_List{
	vector<edge3d> E;

	//function for adding an edge to edgelist
	void addEdge(edge3d edge_to_add);

	//function to delete an edge from an edgelist
	void removeEdge(edge3d edge_to_remove);
}

#endif