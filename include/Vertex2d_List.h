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
	int x;
	// Y cordinate
	int y;

	//constructor
 	Vertex2d();

 	Vertex2d (int x,int y);



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


};

//function to check if two 2d_cordinates are equal
bool equal_2dVertex(Vertex2d v1,Vertex2d v2);

void print_Vertex2d(Vertex2d v);

void print_Vertex2d_List(Vertex2d_List v_list);

#endif