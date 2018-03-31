#ifndef PROJECTION2D
#define PROJECTION2D

#include <vector>
#include "Vertex2d_List.h"
#include "Edge2d_List.h"

using namespace std;


/**
 A 2D solid is defined by :-
 1) A list of 2d vertices. Here they are of the form coordinate2d.
 2) A list of edges. Here they are of the form edge2d.

**/

class Projection2d{
	public:
	// list of vertices
	Vertex2d_List V;
	// list of edges
	Edge2d_List E;
	//empty constructor
 	Projection2d();
	//constructor
 	Projection2d(Vertex2d_List vertices, Edge2d_List edges);
};

//Triplet 
class Projection{
	public:
	
	Projection();

	//front-view
	Projection2d front;
	//top-view
	Projection2d top;
	//side-view
	Projection2d side;
	//constructor
 	Projection(Projection2d f,Projection2d t, Projection2d s);
};

#endif