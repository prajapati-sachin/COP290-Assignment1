#ifndef VERTEX3D_LIST
#define VERTEX3D_LIST

#include <vector>
#include "Vertex2d_List.h"
#include "Common_functions.h"

using namespace std;

/** Vertex :-  3d coordinate for 3d solid **/
class Vertex3d{
	// X cordinate
	int x;
	// Y cordinate
	int y;
	// Z cordinate
	int z;

	//constructor
 	Vertex3d (int x,int y,int z);

 	//constructor to create a vertex from 3 points in respective projections
 	Vertex3d (Vertex2d front_vertex2d, Vertex2d top_vertex2d, Vertex2d side_vertex2d);



};


class Vertex3d_List{
	vector<Vertex3d> E;

	//constructors
	Vertex3d_List();

	//constructor to generate vertex3d list from vertex 2d list
	Vertex3d_List (Vertex2d_List top_2dvertexlist,Vertex2d_List front_2dvertexlist,Vertex2d_List side_2dvertexlist);

	//function for adding an vertex to vertexlist
	void addVertex (Vertex3d vertex_to_add);

	//function to delete an vertex from an vertexlist
	void removeVertex (Vertex3d vertex_to_remove);

	//function to check presence of a vertex in a vertexlist
	bool checkVertex(Vertex3d vertex_to_check);


};

#endif