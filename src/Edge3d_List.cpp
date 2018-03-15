#include "Edge3d_List.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////////
//Implementation of class Edge3d
Edge3d::Edge3d(Vertex3d v1, Vertex3d v2){
	x=v1;
	y=v2;
}

Edge2d Edge3d::Edge2d_frontview(){
	Vertex2d first;
	Vertex2d second;
	first = x.point2d_front();
	second = y.point2d_front();
	Edge2d result = Edge2d(first,second);
	return result;
}

Edge2d Edge3d::Edge2d_topview(){
	Vertex2d first;
	Vertex2d second;
	first = x.point2d_top();
	second = y.point2d_top();
	Edge2d result = Edge2d(first,second);
	return result;
}

Edge2d Edge3d::Edge2d_sideview(){
	Vertex2d first;
	Vertex2d second;
	first = x.point2d_side();
	second = y.point2d_side();
	Edge2d result = Edge2d(first,second);
	return result;
}
////////////////////////////////////////////////////////////////////////////////////
//Implementaion of class Edge3d List