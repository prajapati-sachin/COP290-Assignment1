	#include "../include/Projection2d.h"

using namespace std;

Projection2d::Projection2d(Vertex2d_List vertices, Edge2d_List edges){
	V= vertices;
	E= edges;
}

Projection2d::Projection2d(){}

Projection::Projection(Projection2d f,Projection2d t, Projection2d s){
	front=f;
	top=t;
	side=s;
}

Projection::Projection(){}
