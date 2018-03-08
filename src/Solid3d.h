#ifndef Solid3d
#define Solid3d

#include <vector>
#include "Vertex3d_List.h"
#include "Edge3d_List.h"
#include "Face3d_List.h"


using namespace std;


/**
 A 3D solid is defined by :-
 1) A list of vertices. Here they are of the form coordinate3d.
 2) A list of edges. Here they are of the form edge3d.
 3) A list of faces. Here they are of the form face3d.

**/
class Solid3d{
	// list of vertices
	Vertex3d_List V;
	// list of edges
	Edge3d_List E;
	// list of faces
	Face3d_List F;
};

#endif