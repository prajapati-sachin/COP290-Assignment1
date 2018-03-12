#ifndef EDGE2D_LIST
#define EDGE2D_LIST

#include <vector>
#include "Common_functions.h"
#include "Vertex2d_List.h"
#include "Vertex2d_List.h"


using namespace std;

/** Edge2d :- an edges for 2d  **/
class Edge2d{
	//first end point
	Vertex2d x;
	//second end point
	Vertex2d y;

	//constructors
	Edge2d(Vertex2d x,Vertex2d y);


};

/** EdgeList :- a list of edges **/
class Edge2d_List{
	
	vector<Edge2d> E;

	//function for adding an edge to edgelist
	void addEdge(Edge2d edge_to_add);

	//function to delete an edge from an edgelist
	void removeEdge(Edge2d edge_to_remove);

	//function to check presence of an edge in an edgelist
	bool checkEdge(Edge2d edge_to_check);
};

//function to check if two 2d_edges are equal
bool equal_2dedge(Edge2d edge2d1,Edge2d edge2d2);

#endif