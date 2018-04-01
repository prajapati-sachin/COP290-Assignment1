#include <iostream>
#include "../include/Edge3d_List.h"
#include "../include/Edge2d_List.h"
#include "../include/HiddenLines.h"
#include "../include/Projection2d.h"
#include "../include/Solid3d.h"
#include "../include/Surface3d_List.h"
#include "../include/Vertex2d_List.h"
#include "../include/Vertex3d_List.h"

using namespace std;

int main(){
	int a=2;
	int b=3;
	int c;
	c=a+b;
	cout << c <<"\n";
//	cout << "Hello World!\n";

	Vertex3d_List V;
	Edge3d_List E;
	Face3d_List F;

	Vertex3d v1 = Vertex3d(1,1,1);
	Vertex3d v2 = Vertex3d(1,1,2);
	Vertex3d v3 = Vertex3d(1,2,1);
	Vertex3d v4 = Vertex3d(1,2,2);
	Vertex3d v5 = Vertex3d(2,1,1);
	Vertex3d v6 = Vertex3d(2,1,2);
	Vertex3d v7 = Vertex3d(2,2,1);
	Vertex3d v8 = Vertex3d(2,2,2);

	V.addVertex(v1);
	V.addVertex(v2);
	V.addVertex(v3);
	V.addVertex(v4);
	V.addVertex(v5);
	V.addVertex(v6);
	V.addVertex(v7);
	V.addVertex(v8);

	Edge3d e1 = Edge3d(v1,v2);
	Edge3d e2 = Edge3d(v1,v3);
	Edge3d e3 = Edge3d(v1,v5);
	Edge3d e4 = Edge3d(v2,v4);
	Edge3d e5 = Edge3d(v2,v6);
	Edge3d e6 = Edge3d(v3,v4);
	Edge3d e7 = Edge3d(v3,v7);
	Edge3d e8 = Edge3d(v4,v8);
	Edge3d e9 = Edge3d(v5,v6);
	Edge3d e10 = Edge3d(v5,v7);
	Edge3d e11 = Edge3d(v6,v8);
	Edge3d e12 = Edge3d(v7,v8);

	E.addEdge(e1);
	E.addEdge(e2);
	E.addEdge(e3);
	E.addEdge(e4);
	E.addEdge(e5);
	E.addEdge(e6);
	E.addEdge(e7);
	E.addEdge(e8);
	E.addEdge(e9);
	E.addEdge(e10);
	E.addEdge(e11);
	E.addEdge(e12);

	Solid3d solid = Solid3d(V,E,F);

	Projection2d front_projection = solidmake_front_projections();
	return 0;
}