#include "Solid3d.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////
//Implementation of class solid 3d

Solid3d::Solid3d(Vertex3d_List vertices, Edge3d_List edges, Face3d_List faces){
	V=vertices;
	E=edges;
	F=faces;
}

Solid3d::make_front_projections(){
	Vertex2d_List vertices;
	Edge2d_List edges;
	vertices = V.list_frontview();
	edges = E.list_frontview();
	Projection2d view(vertices, edges);
	return view;
}

Solid3d::make_top_projections(){
	Vertex2d_List vertices;
	Edge2d_List edges;
	vertices = V.list_topview();
	edges = E.list_topview();
	Projection2d view(vertices, edges);
	return view;
}

Solid3d::make_side_projections(){
	Vertex2d_List vertices;
	Edge2d_List edges;
	vertices = V.list_sideview();
	edges = E.list_sideview();
	Projection2d view(vertices, edges);
	return view;
}

Solid3d::make_projections(){
	Projection2d front;
	Projection2d top;
	Projection2d side;
	front = make_front_projections();
	top = make_top_projections();
	side = make_side_projections();
	Projection views(front, top, side);
	return views;
}