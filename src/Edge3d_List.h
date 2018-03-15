#ifndef EDGE3D_LIST
#define EDGE3D_LIST

#include <vector>
#include "Edge2d_List.h"
#include "Vertex3d_List.h"

using namespace std;

/** Edge3d :- an edge of 3d solid**/
class Edge3d{
	public:
	//first end point
	Vertex3d x;
	//second end point
	Vertex3d y;

	//constructors
	Edge3d(Vertex3d v1,Vertex3d v2);

	// projection of edge in frontview
	Edge2d edge2d_front();

	// projection of edge in topview
	Edge2d edge2d_top();

	// projection of edge in sideview
	Edge2d edge2d_side();

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
	void addEdge(Edge3d e);

	//function to delete an edge from an edgelist
	void removeEdge(Edge3d e);

	//function to check presence of an edge in an edgelist
	bool checkEdge(Edge3d edge_to_check);

	//function to create edge list from given edgefist in 3d and 2d vertex list in front view
	Edge2d_List list_frontview();

	//function to create edge list from given edgefist in 3d and 2d vertex list in top view
	Edge2d_List list_topview();

	//function to create edge list from given edgefist in 3d and 2d vertex list in side view
	Edge2d_List list_sideview();


};

namespace extra_functions_3dedge{
	//function to check if two 3d_edges are equal
	bool equal_3dedge(Edge3d edge3d1,Edge3d edge3d2);

	//function to check if there is a common vertex between two edges
	bool check_common_vertex(Edge3d edge1,Edge3d edge2);

	//function to find common vertex between two edges
	Vertex3d common_vertex(Edge3d edge3d1,Edge3d edge3d2);

	//function which given a 3d edge vector and a edge gives the index at which edge is present
	int edge_index(vector<Edge3d> elist, Edge3d e);
}
#endif