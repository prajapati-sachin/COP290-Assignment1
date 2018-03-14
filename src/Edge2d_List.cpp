#include "Edge2d_List.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Edge2d class

//constructor for ed Edge
Edge2d::Edge2d(Vertex2d vertex1, Vertex2d vertex2){
	v1 = vertex1;
	v2 = vertex2;
	hidden = false;
	
}

//function to make edge hidden
Edge2d::make_hidden(){
	hidden = true;
}

//function to make edge visible
Edge2d::make_visible(){
	hidden = false;
}

//function to check if point lies inside the edge
bool Edge2d::check_inside(Vertex2d 2dvertex){
	bool x_bounded = (((v1.x<2dvertex.x)&&(2dvertex.x<v2.x))||((v1.x>2dvertex.x)&&(2dvertex.x>v2.x)));
	bool y_bounded = (((v1.y<2dvertex.y)&&(2dvertex.y<v2.y))||((v1.y>2dvertex.y)&&(2dvertex.y>v2.y)));
	return (x_bounded&&y_bounded);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Normal2d class
//construction to construct a normal

Normal2d::Normal2d(Vertex2d vertex1, Vertex2d vertex2){
	i=vertex1.x-vertex2.x;
	j=vertex1.y-vertex2.y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Line2d class

//construction for creating 2dline from two vertices
Line2d::Line2d(Vertex2d vertex1,Vertex2d vertex2){
	direction = Normal2d::Normal2d(vertex1.vertex2);
	point = vertex1;
}

//construction for creating 2dline from normal and a vertex
Line2d::Line2d(Normal2d normal,Vertex2d vertex){
	direction = normal;
	point = vertex;
}

//function to check if point lies on the line
bool Line2d::check_vertex2d_in_line(Vertex2d vertex){
	return (product_of_normal_vertex_in2d(direction,vertex)==product_of_normal_vertex_in2d(direction,point));
}

//function to check if edge lies on the line
bool Line2d::check_edge2d_in_line(Edge2d edge){
	return (Line2d::check_vertex2d_in_line(edge.v1)&&Line2d::check_vertex2d_in_line(edge.v2));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Edge2d_List class





return ((normal.i*vertex.x)+(normal.j*vertex.y)+(normal.k*vertex.z));