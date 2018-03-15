#include "Edge3d_List.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////////

namespace extra_functions_3dedge{
	




	bool equal_3dedge(Edge3d e1, Edge3d e2){
		if((extra_functions_3dvertex::equal_3dvertex(e1.x, e2.x) && extra_functions_3dvertex::equal_3dvertex(e1.y, e2.y))|| (extra_functions_3dvertex::equal_3dvertex(e1.x, e2.y) && extra_functions_3dvertex::equal_3dvertex(e1.y, e2.x)))
			return true;
		else
			return false;
	}


	int edge_index(vector<Edge3d> elist, Edge3d e){
		int result=-1;
		for(int i=0;i<elist.size();i++){
			if(equal_3dedge(elist[i],e)){
				result=i;
			}
		}
		return result;
	}
}
///////////////////////////////////////////////////////////////////////////////////
//Implementation of class Edge3d
Edge3d::Edge3d(Vertex3d v1, Vertex3d v2){
	x=v1;
	y=v2;
}

Edge2d Edge3d::edge2d_front(){
	Vertex2d first;
	Vertex2d second;
	first = x.point2d_front();
	second = y.point2d_front();
	Edge2d result = Edge2d(first,second);
	return result;
}

Edge2d Edge3d::edge2d_top(){
	Vertex2d first;
	Vertex2d second;
	first = x.point2d_top();
	second = y.point2d_top();
	Edge2d result = Edge2d(first,second);
	return result;
}

Edge2d Edge3d::edge2d_side(){
	Vertex2d first;
	Vertex2d second;
	first = x.point2d_side();
	second = y.point2d_side();
	Edge2d result = Edge2d(first,second);
	return result;
}
////////////////////////////////////////////////////////////////////////////////////
//Implementaion of class Edge3d_List
void Edge3d_List::addEdge(Edge3d e){
	E.push_back(e);
}

void Edge3d_List::removeEdge(Edge3d e){
	if(checkEdge(e)){
		int i = extra_functions_3dedge::edge_index(E,e);
		E.erase(E.begin()+i);
	}
}

bool Edge3d_List::checkEdge(Edge3d e){
	bool result=false;
	for(int i=0;i<E.size();i++){
		if(extra_functions_3dedge::equal_3dedge(E[i], e)){
			result=true;
		}
	}
	return result;
}


Edge2d_List Edge3d_List::list_frontview(){
	Edge2d_List front_projections;
	for(int i=0;i<E.size();i++){
		Edge3d temp = E[i];
		Edge2d projection = temp.edge2d_front();
		(front_projections.E).push_back(projection);
	}
}


Edge2d_List Edge3d_List::list_topview(){
	Edge2d_List top_projections;
	for(int i=0;i<E.size();i++){
		Edge3d temp = E[i];
		Edge2d projection = temp.edge2d_top();
		(top_projections.E).push_back(projection);
	}
}


Edge2d_List Edge3d_List::list_sideview(){
	Edge2d_List side_projections;
	for(int i=0;i<E.size();i++){
		Edge3d temp = E[i];
		Edge2d projection = temp.edge2d_side();
		(side_projections.E).push_back(projection);
	}
}