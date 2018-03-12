#ifndef EDGE3d_LIST
#define EDGE3d_LIST

#include <vector>
#include "Edge2d_List.h"
#include "Vertex3d_List.h"
#include "Common_functions.h"

using namespace std;

/** Edge3d :- an edge of 3d solid**/
class Edge3d{
	//first end point
	Vertex3d x;
	//second end point
	Vertex3d y;

	//constructors
	Edge3d(Vertex3d x,Vertex3d y);


};

/** EdgeList :- a list of edges **/
class Edge3d_List{
	vector<Edge3d> E;

	//constructors
	Edge3d_List();

	//constructor to create 3d edge list given the 3 edge lists in three progections and 3d vertex list
	Edge3d_List(Edge2d_List top_2dEdgelist,Edge2d_List front_2dEdgelist,Edge2d_List side_2dEdgelist, Vertex3d_List Vertexlist_3d);
	
	//constructor that return edge list connected to the vertex in the given edgelist
	Edge3d_List(Vertex3d vertex,Edge2d_List edgelist) ;

	//function for adding an edge to edgelist
	void addEdge(Edge3d edge_to_add);

	//function to delete an edge from an edgelist
	void removeEdge(Edge3d edge_to_remove);

	//function to check presence of an edge in an edgelist
	bool checkEdge(Edge3d edge_to_check);


};

#endif