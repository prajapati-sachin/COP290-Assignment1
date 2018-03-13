#include "Surface3d_List.h"

using namespace std;

///////////////////////////////////////////////////////////
//Implementation of normal3d class

//constructor to create normal from given two edges
Normal3d::Normal3d (Edge3d edge3d){
	i = ((edge3d.x).x) - ((edge3d.y).x);
	j = ((edge3d.x).y) - ((edge3d.y).y);
	k = ((edge3d.x).z) - ((edge3d.y).z);

}

//constructor to create normal from given three vertices
Normal3d::Normal3d (Normal3d normal1,Normal3d normal2){
	i = normal1.j*normal2.k - normal1.k*normal2.j;
	i = normal1.k*normal2.i - normal1.i*normal2.k;
	k = normal1.i*normal2.j - normal1.j*normal2.i;

}
//constructor to create normal from given three vertices
Normal3d::Normal3d(Vertex3d vertex3d1,Vertex3d vertex3d2,Vertex3d vertex3d3){
	Edge3d edge1 = Edge3d::Edge3d(vertex3d1,vertex3d2);
	Edge3d edge2 = Edge3d::Edge3d(vertex3d1,vertex3d3);

	Normal3d normal_edge1 = Normal3d::Normal3d(edge1);
	Normal3d normal_edge2 = Normal3d::Normal3d(edge2); 

	Normal3d normal = Normal3d::Normal3d(normal_edge1,normal_edge2);
	i = normal.i;
	j = normal.j;
	k = normal.k; 
}	