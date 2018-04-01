#ifndef EDGE2D_LIST
#define EDGE2D_LIST

#include <vector>
#include <iostream>
#include "Vertex2d_List.h"



using namespace std;

/** Edge2d :- an edges for 2d  **/
class Edge2d{
public:
	//first end point
	Vertex2d v1;
	//second end point
	Vertex2d v2;
	//hidden or not
	bool hidden;

	//constructorss
	Edge2d();

	Edge2d(Vertex2d vertex1,Vertex2d vertex2);

	//function to make edge hidden
	void make_hidden();

	//function to make edge visible
	void make_visible();

	//function to check if point lies inside the edge
	bool check_inside(Vertex2d vertex);

	void print_Edge2d();


};

/** Normal2d :- a normal(direction) for 2d line  **/
class Normal2d{
public:
	//i direction
	int i;
	//j direction
	int j;
	
	//construction to construct a normal
	Normal2d();

	Normal2d(Vertex2d vertex1, Vertex2d vertex2);

};

class Line2d{
public:
	//direction of the line or slope
	Normal2d direction;
	//point on the line
	Vertex2d point;

	Line2d();

	//construction for creating 2dline from two vertices
	Line2d(Vertex2d vertex1,Vertex2d vertex2);

	//construction for creating 2dline from normal and a vertex
	Line2d(Normal2d normal,Vertex2d vertex);

	//construction for creating 2dline from an edge
	Line2d(Edge2d edge);

	//function to check if point lies on the line
	bool check_vertex2d_in_line(Vertex2d vertex);

	//function to check if edge lies on the line
	bool check_edge2d_in_line(Edge2d edge);	


};

/** EdgeList :- a list of edges **/
class Edge2d_List{
public:
	//List	
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

	void print_Edge2d_List();
};

//function to check if two 2d_edges are equal
bool equal_2dEdge(Edge2d e1,Edge2d e2);

//function to check if two edges are parallel
bool parallel_2dEdge(Edge2d e1,Edge2d e2);

//function to check if two lines are equal
bool equal_2dline(Line2d line1,Line2d line2);

//function to check if two lines are parallel
bool parallel_2dline(Line2d line1,Line2d line2);

//function to check if two directions/normal2d are equal
bool equal_direction(Normal2d normal1,Normal2d normal2);

//gives intersection of 2d lines
Vertex2d intersection_of_2dlines(Line2d line1,Line2d line2);

//function to take union of two parallel edges
Edge2d union_of_two_edges(Edge2d edge2d1,Edge2d edge2d2);

//ax + by  for a normal and vertex
int product_of_normal_vertex_in2d(Normal2d normal,Vertex2d vertex);

int min(int a,int b);

int max(int a,int b);



#endif