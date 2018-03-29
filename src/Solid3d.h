#ifndef SOLID3D
#define SOLID3D

#include <vector>
#include "Vertex3d_List.h"
#include "Edge3d_List.h"
#include "Face3d_List.h"
#include "Projection2d.h"

using namespace std;


/**
 A 3D solid is defined by :-
 1) A list of vertices. Here they are of the form coordinate3d.
 2) A list of edges. Here they are of the form edge3d.
 3) A list of faces. Here they are of the form face3d.

**/
class Solid3d{
	public:
	// list of vertices
	Vertex3d_List V;
	// list of edges
	Edge3d_List E;
	// list of faces
	Face3d_List F;
	//empty constructor
 	Solid3d ();
	//constructor
 	Solid3d (Vertex3d_List vertices, Edge3d_List edges, Face3d_List faces);
	// gives the front projection of 3d solid
	Projection2d make_front_projections();
	// gives the top projection of 3d solid
	Projection2d make_top_projections();
	// gives the side projection of 3d solid
	Projection2d make_side_projections();
	// combines the result of above 3 functions and gives all the views in final projection 
	Projection make_projections();

};

#endif