#include "Edge3d_List.h"
#include "Vertex3d_List.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////////
//Implementation of class Edge3d
Edge3d::Edge3d(Vertex3d v1, Vetrtex3d v2){
	x=v1;
	y=v2;
}

Edge3d::Edge2d_frontview(){
	Edge2d first;
	Edge2d second;
	first = x.point2d_front();
	second = y.point2d_front();
	Edge2d result = Edge2d(first,second);
	return result;
}

Edge3d::Edge2d_topview(){
	Edge2d first;
	Edge2d second;
	first = x.point2d_top();
	second = y.point2d_top();
	Edge2d result = Edge2d(first,second);
	return result;
}

Edge3d::Edge2d_sideview(){
	Edge2d first;
	Edge2d second;
	first = x.point2d_side();
	second = y.point2d_side();
	Edge2d result = Edge2d(first,second);
	return result;
}
////////////////////////////////////////////////////////////////////////////////////
//Implementaion of class Edge3d List