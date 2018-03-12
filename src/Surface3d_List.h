#ifndef SURFACE3d_LIST
#define SURFACE3d_LIST

#include <vector>
#include "Common_functions.h"
#include "Edge3d_List.h"
#include "Vertex3d_List.h"

//normal vector of a plane
class Normal3d{
	//i direction
	int i;
	//j direction
	int j;
	//k direction
	int k;

	//constructor to create normal from given two edges
	Normal3d (Edge3d edge3d1,Edge3d edge3d2);

	//constructor to create normal from given three vertices
	Normal3d(Vertex3d vertex3d1,Vertex3d vertex3d2,Vertex3d vertex3d3);	
};

//a surface in 3d solid is a classified by having a normal vector and a vertex
class Surface3d{
	//normal vector for the surface	
	Normal3d normal_vector;
	//coordinate in the surface
	Vertex3d surface_vertex; 

	//constructor to create a surface from given pair of edges and vertex
	Surface3d(Edge3d edge3d1,Edge3d edge3d2,Vertex3d vertex);

	//check if given vertex lies on the given surface
	bool check_vertex_on_surface(Vertex3d vertex);

	//check if given vertex lies on the given surface
	bool check_edge3d_on_surface(Edge3d edge);

};

class Surface_List{
	vector<Surface3d> S;

	//constructor for creating surface list for given edge_lists and vertex_list
	Surface_List(Edge3d_List edge3dList1,Edge3d_List edge3dList2,Vertex3d_List vertexlist);

	//function for adding a surface to surfacelist
	void addSurface(Surface3d surface_to_add);

	//function to delete a surface from a surfacelist
	void removeSurface(Surface3d surface_to_remove);

	//function to check presence of a surface in a surfacelist
	bool checkSurface(Surface3d surface_to_check);


};

#endif