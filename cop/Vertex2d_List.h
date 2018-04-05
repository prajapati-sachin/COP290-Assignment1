#ifndef VERTEX2D_LIST
#define VERTEX2D_LIST

#include <vector>
#include <iostream>


using namespace std;

extern int DELTA;
/** Vertex :-  2d coordinate for projections**/
class Vertex2d{
	public:
	// X cordinate
	float x;
	// Y cordinate
	float y;

	//constructor
 	Vertex2d();

 	Vertex2d (float x,float y);

 	void print_Vertex2d();


};

/** VertexList :- a list of vertices **/
class Vertex2d_List{
	public:
	vector<Vertex2d> V;

	// //construction to create vertex2d_list
	Vertex2d_List();

	//function for adding an vertex to vertexlist
	void addVertex (Vertex2d v);

	//function to check presence of a vertex in a vertexlist
	bool checkVertex(Vertex2d v);

	//function to delete a vertex from a vertexlist
	void removeVertex (Vertex2d v);

	void print_Vertex2d_List();

};

//function to check if two 2d_cordinates are equal
bool equal_2dVertex(Vertex2d v1,Vertex2d v2);


#endif