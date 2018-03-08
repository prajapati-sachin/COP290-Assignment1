#ifndef EDGE2D_LIST
#define EDGE2D_LIST

#include <vector>
#include "2dstruct.h"

using namespace std;

/** EdgeList :- a list of edges **/
class Edge2d_List{
	
	vector<edge2d> E;

	//function for adding an edge to edgelist
	void addEdge(edge2d edge_to_add);

	//function to delete an edge from an edgelist
	void removeEdge(edge2d edge_to_remove);
};

#endif