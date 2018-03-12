#ifndef VERTEX2D_LIST
#define VERTEX2D_LIST

#include <vector>
#include "Common_functions.h"

using namespace std;

/** Vertex :-  2d coordinate for projections**/
class Vertex2d{
	// X cordinate
	int x;
	// Y cordinate
	int y;

	//constructor
 	Vertex2d (int x,int y);

};

/** VertexList :- a list of vertices **/
class Vertex2d_List{
	vector<Vertex2d> E;

	//construction to create vertex2d_list
	Vertex2d_List();

	//function for adding an vertex to vertexlist
	void addVertex (Vertex2d vertex_to_add);

	//function to delete an vertex from an vertexlist
	void removeVertex (Vertex2d vertex_to_remove);

	//function to check presence of a vertex in a vertexlist
	bool checkVertex(Vertex2d vertex_to_check);
};

//function to check if two 2d_cordinates are equal
bool equal_2dvertex(Vertex2d vertex2d1,Vertex2d vertex2d2);

#endif