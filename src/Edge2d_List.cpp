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
	direction = Normal2d::Normal2d(vertex1,vertex2);
	point = vertex1;
}

//construction for creating 2dline from normal and a vertex
Line2d::Line2d(Normal2d normal,Vertex2d vertex){
	direction = normal;
	point = vertex;
}

//construction for creating 2dline from an edge
Line2d::Line2d(Edge2d edge){
	direction = Normal2d::Normal2d(edge.v1,edge.v2);
	point = edge.v1;
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

//function for adding an Edge to Edgelist
void Edge2d_List::addEdge(Edge2d e){
	E.push_back(e);
}

//function to check presence of an Edge in a Edgelist
bool Edge2d_List::check_equalEdge(Edge2d e){
	bool result=false;
	for(int i=0;i<E.size();i++){
		if(equal_2dedge(E[i], e)){
			result=true;
		}
	}
	return result;
}

//function to check presence of a parallel Edge in a Edgelist
bool Edge2d_List::check_parallelEdge(Edge2d e){
	bool result=false;
	for(int i=0;i<E.size();i++){
		if(parallel_2dEdge(E[i], e)){
			result=true;
		}
	}
	return result;
}

//function to delete an Edge from an Edgelist
void Edge2d_List::removeEdge(Edge2d e){
	if(check_equalEdge(e)){
		for(int i=0;i<E.size();i++){
			if(equal_2dEdge(E[i], e)){
				E.erase(E.begin()+i);
			}
		}
	}
}

//////////////////////////////////////////////////////////////
//Other functions
//function to check if two 2d_edges are equal
bool equal_2dEdge(Edge2d e1,Edge2d e2){
	return ((equal_2dVertex(e1.v1,e2.v1)&&equal_2dVertex(e1.v2,e2.v2))||(equal_2dVertex(e1.v2,e2.v1)&&equal_2dVertex(e1.v1,e2.v2)));
}

//function to check if two edges are parallel
bool parallel_2dEdge(Edge2d e1,Edge2d e2){
	return (parallel_2dline(Line2d::Line2d(e1),Line2d::Line2d(e2)));
}

//function to check if two lines are equal
bool equal_2dline(Line2d line1,Line2d line2){
	bool temp = (product_of_normal_vertex_in2d(line1.direction,line1.point)-product_of_normal_vertex_in2d(line1.direction,line1.point)==DELTA);
	return (parallel_2dline(line1,line2)&&temp);
}

//function to check if two lines are parallel
bool parallel_2dline(Line2d line1,Line2d line2){
	return ((line1.direction,line2.direction));
}

//function to check if two directions are equal
bool equal_direction(Normal2d normal1,Normal2d normal2){
	return ((normal1.i/normal2.i)==(normal1.j/normal2.j));
}

//gives intersection of 2d lines
Vertex2d intersection_of_2dlines(Line2d line1,Line2d line2){
	
}

//function to take union of two parallel edges
Edge2d union_of_two_edges(Edge2d edge2d1,Edge2d edge2d2){

}

//ax + by  for a normal and vertex
int product_of_normal_vertex_in2d(Normal2d normal,Vertex2d vertex){
	return ((normal.i*vertex.x)+(normal.j*vertex.y));
}
