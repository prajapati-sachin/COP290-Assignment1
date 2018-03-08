#ifndef Projection2d
#define Projection2d

#include <vector>
#include "VertexList.h"
#include "EdgeList.h"

using namespace std;


/**
 A 2D solid is defined by :-
 1) A list of 2d vertices. Here they are of the form coordinate2d.
 2) A list of edges. Here they are of the form edge2d.

**/
class Projection2d{
	// list of vertices
	Vertex2d_List V;
	// list of edges
	Edge2d_List E;
};

#endif