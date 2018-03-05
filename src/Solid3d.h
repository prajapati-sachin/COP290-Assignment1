#ifndef Solid3d
#define Solid3d

#include <vector>
#include Solid_struct
#include VertexList
#include EdgeList

using namespace std;


/** a 3D solid is defined by :-
 1) A list of vertices. Here they are of the form coordinate3d.
 2) A list of edges. Here they are of the form edge3d.
 3) A list of faces. Here they are of the form face3d.

**/
class solid3d{
	// list of vertices
	VertexList V;
	// list of edges
	EdgeList E;
	// list of faces
	FaceList F;
};
