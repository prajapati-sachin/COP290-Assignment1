#ifndef EDGE2D_LIST
#define EDGE2D_LIST

#include <vector>
#include "Common_functions.h"
#include "Vertex2d_List.h"



using namespace std;

/** Edge2d :- an edges for 2d  **/
class Edge2d{
	//first end point
	Vertex2d x;
	//second end point
	Vertex2d y;
	//hidden or not
	bool hidden;

	//constructors
	Edge2d(Vertex2d x,Vertex2d y);


};

/** Normal2d :- a normal(direction) for 2d line  **/
class Normal2d{
	//i direction
	int i;
	//j direction
	int j;
	
	//construction to construct a normal
	Normal2d(Edge2d edge1,Edge2d edge2);

};

class Line2d{
	//direction of the line or slope
	Normal2d direction;
	//point on the line
	Vertex2d point;

	//construction for creating 2dline from two vertices
	Line2d(Vertex2d vertex1,Vertex2d vertex2);

	//construction for creating 2dline from normal and a vertex
	Line2d(Normal2d direction,Vertex2d vertex);

	//function to check if point lies on the line
	bool check_vertex2d_in_line(Vertex2d vertex);

	//function to check if edge lies on the line
	bool check_edge2d_in_line(Edge2d edge);	

};

/** EdgeList :- a list of edges **/
class Edge2d_List{
	
	vector<Edge2d> E;

	//constructor for an empty edgeList
	Edge2d_List();

	//function for adding an edge to edgelist
	void addEdge(Edge2d edge_to_add);

	//function to delete an edge from an edgelist
	void removeEdge(Edge2d edge_to_remove);

	//function to check presence of an edge in an edgelist
	bool check_equalEdge(Edge2d edge_to_check);

	//function to check presence of a parallel edge in an edgelist
	bool check_parallelEdge(Edge2d edge_to_check);
};

//function to check if two 2d_edges are equal
bool equal_2dedge(Edge2d edge2d1,Edge2d edge2d2);

//function to check if two edges are parallel
bool parallel_2dedge(Edge2d edge2d1,Edge2d edge2d2);

//function to check if two lines are equal
bool equal_2dline(Line2d line1,Line2d line2);

//function to take union of two parallel edges
Edge2d union_of_two_edges(Edge2d edge2d1,Edge2d edge2d2);

#endif