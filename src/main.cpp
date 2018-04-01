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
//	cout << "Hello World!\n";

	Vertex3d_List V;
	Edge3d_List E;
	Face3d_List F;
	// Vertex3d v1 = Vertex3d(1,1,1);
	// Vertex3d v2 = Vertex3d(1,1,2);
	// Vertex3d v3 = Vertex3d(1,2,1);
	// Vertex3d v4 = Vertex3d(1,2,2);
	// Vertex3d v5 = Vertex3d(2,1,1);
	// Vertex3d v6 = Vertex3d(2,1,2);
	// Vertex3d v7 = Vertex3d(2,2,1);
	// Vertex3d v8 = Vertex3d(2,2,2);

	Vertex3d v1(1,1,1);
	Vertex3d v2(1,1,2);
	Vertex3d v3(1,2,1);
	Vertex3d v4(1,2,2);
	Vertex3d v5(2,1,1);
	Vertex3d v6(2,1,2);
	Vertex3d v7(2,2,1);
	Vertex3d v8(2,2,2);



	V.addVertex(v1);
	V.addVertex(v2);
	V.addVertex(v3);
	V.addVertex(v4);
	V.addVertex(v5);
	V.addVertex(v6);
	V.addVertex(v7);
	V.addVertex(v8);

	V.print_Vertex3d_List();

	Edge3d e1(v1,v2);
	Edge3d e2(v1,v3);
	Edge3d e3(v1,v5);
	Edge3d e4(v2,v4);
	Edge3d e5(v2,v6);
	Edge3d e6(v3,v4);
	Edge3d e7(v3,v7);
	Edge3d e8(v4,v8);
	Edge3d e9(v5,v6);
	Edge3d e10(v5,v7);
	Edge3d e11(v6,v8);
	Edge3d e12(v7,v8);



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
	
	E.print_Edge3d_List();

	Solid3d solid(V,E,F);

	Projection2d front_projection = solid.make_front_projections();

	cout << "Hello World!\n";

	(front_projection.V).print_Vertex2d_List();

	(front_projection.E).print_Edge2d_List();	

	return 0;
}