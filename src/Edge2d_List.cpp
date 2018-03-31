#include "../include/Edge2d_List.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Edge2d class

//constructor for 2d Edge
Edge2d::Edge2d(Vertex2d vertex1,Vertex2d vertex2){

	this->v1 = vertex1;
	this->v2 = vertex2;
	this->hidden = false;
	
}

//function to make edge hidden
void Edge2d::make_hidden(){
	this->hidden = true;
}

//function to make edge visible
void Edge2d::make_visible(){
	this->hidden = false;
}

//function to check if point lies inside the edge
bool Edge2d::check_inside(Vertex2d vertex){
	int x1=this->v1.x;
	int x2=this->v2.x;
	int y1=this->v1.y;
	int y2=this->v2.y;
	int x_min = min(x1,x2);
	int x_max = max(x1,x2);
	int y_min = min(y1,y2);
	int y_max = max(y1,y2);

	bool x_bound = (x_min<=vertex.x)&&(vertex.x<=x_max);;
	bool y_bound = (y_min<=vertex.y)&&(vertex.y<=y_max);;
	return (x_bound&&y_bound);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Normal2d class
//construction to construct a normal

Normal2d::Normal2d(Vertex2d vertex1, Vertex2d vertex2){
	this->i=vertex1.x-vertex2.x;
	this->j=vertex1.y-vertex2.y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Line2d class

//construction for creating 2dline from two vertices
Line2d::Line2d(Vertex2d vertex1,Vertex2d vertex2){
	this->direction = Normal2d(vertex1,vertex2);
	this->point = vertex1;
}

//construction for creating 2dline from normal and a vertex
Line2d::Line2d(Normal2d normal,Vertex2d vertex){
	this->direction = normal;
	this->point = vertex;
}

//construction for creating 2dline from an edge
Line2d::Line2d(Edge2d edge){
	this->direction = Normal2d(edge.v1,edge.v2);
	this->point = edge.v1;
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
	this->E.push_back(e);
}

//function to check presence of an Edge in a Edgelist
bool Edge2d_List::check_equalEdge(Edge2d e){
	bool result=false;
	if(equal_2dVertex(e.v1,e.v2)){
		result = true;
	}
	for(int i=0;i<this->E.size();i++){
		if(equal_2dEdge(this->E[i], e)){
			result=true;
		}
	}
	return result;
}

//function to check presence of a parallel Edge in a Edgelist
bool Edge2d_List::check_parallelEdge(Edge2d e){
	bool result=false;
	for(int i=0;i<this->E.size();i++){
		if(parallel_2dEdge(this->E[i], e)){
			result=true;
		}
	}
	return result;
}

//function to delete an Edge from an Edgelist
void Edge2d_List::removeEdge(Edge2d e){
	if(check_equalEdge(e)){
		for(int i=0;i<this->E.size();i++){
			if(equal_2dEdge(this->E[i], e)){
				this->E.erase(this->E.begin()+i);
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
	return (parallel_2dline(Line2d(e1),Line2d(e2)));
}

//function to check if two lines are equal
bool equal_2dline(Line2d line1,Line2d line2){
	bool temp = (product_of_normal_vertex_in2d(line1.direction,line1.point)-product_of_normal_vertex_in2d(line1.direction,line1.point)==DELTA);
	return (parallel_2dline(line1,line2)&&temp);
}

//function to check if two lines are parallel
bool parallel_2dline(Line2d line1,Line2d line2){
	return (equal_direction(line1.direction,line2.direction));
}

//function to check if two directions are equal
bool equal_direction(Normal2d normal1,Normal2d normal2){
	return ((normal1.i/normal2.i)==(normal1.j/normal2.j));
}

//gives intersection of 2d lines
Vertex2d intersection_of_2dlines(Line2d line1,Line2d line2){
	int a1 = line1.direction.i;
	int b1 = line1.direction.j;
	int c1 = product_of_normal_vertex_in2d(line1.direction,line1.point);
	int a2 = line2.direction.i;
	int b2 = line2.direction.j;
	int c2 = product_of_normal_vertex_in2d(line2.direction,line2.point);
	int x = (c1*b2-c2*b1)/(a1*b2-a2*b1);
	int y = (c1*a2-c2*a1)/(b1*a2-b2*a1);
	return Vertex2d(x,y);
}

//function to take union of two parallel edges//need a bool to check first
Edge2d union_of_two_edges(Edge2d edge2d1,Edge2d edge2d2){
	Edge2d temp;
	if(edge2d1.Edge2d::check_inside(edge2d2.v1)&&edge2d1.Edge2d::check_inside(edge2d2.v2))
		temp = edge2d1;
	else if(edge2d2.Edge2d::check_inside(edge2d1.v1)&&edge2d2.Edge2d::check_inside(edge2d1.v2))
		temp = edge2d2;
	else if(edge2d1.Edge2d::check_inside(edge2d2.v1)&&edge2d2.Edge2d::check_inside(edge2d1.v1)){
		temp.v1 = edge2d2.v1;
		temp.v2 = edge2d1.v1;
	}else if(edge2d1.Edge2d::check_inside(edge2d2.v1)&&edge2d2.Edge2d::check_inside(edge2d1.v2)){
		temp.v1 = edge2d2.v1;
		temp.v2 = edge2d1.v2;
	}else if(edge2d1.Edge2d::check_inside(edge2d2.v2)&&edge2d2.Edge2d::check_inside(edge2d1.v1)){
		temp.v1 = edge2d2.v2;
		temp.v2 = edge2d1.v1;
	}else if(edge2d1.Edge2d::check_inside(edge2d2.v2)&&edge2d2.Edge2d::check_inside(edge2d1.v2)){
		temp.v1 = edge2d2.v2;
		temp.v2 = edge2d1.v2;
	}

	return temp;

}

//ax + by  for a normal and vertex
int product_of_normal_vertex_in2d(Normal2d normal,Vertex2d vertex){
	return ((normal.i*vertex.x)+(normal.j*vertex.y));
}

int min(int a,int b){
	if (a<b)
		return a;
	else
		return b;
}

int max(int a,int b){
	if (a>b)
		return a;
	else
		return b;
}
