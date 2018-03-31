#ifndef SURFACE3d_LIST
#define SURFACE3d_LIST

#include <vector>
#include "Common_functions.h"
#include "Edge3d_List.h"
#include "Vertex3d_List.h"

//normal vector of a plane
class Normal3d{
	public:
	//i direction
	int i;
	//j direction
	int j;
	//k direction
	int k;

	//emty constructor
	Normal3d();

	//constructor to create normal from given edges
	Normal3d (Edge3d edge3d);

	//constructor to create normal from given three vertices
	Normal3d(Vertex3d vertex3d1,Vertex3d vertex3d2,Vertex3d vertex3d3);	

	//constructor to create normal by taking cross product of two normals
	Normal3d(Normal3d normal1,Normal3d normal2);
};

//a surface in 3d solid is a classified by having a normal vector and a vertex
class Surface3d{
	public:
	//normal vector for the surface	
	Normal3d normal_vector;
	//coordinate in the surface
	Vertex3d surface_vertex; 

	//emty constructor
	Surface3d();

	//constructor to create a surface from given pair of edges and vertex
	Surface3d(Edge3d edge3d1,Edge3d edge3d2,Vertex3d vertex);

	//check if given vertex lies on the given surface
	bool check_vertex_on_surface(Vertex3d vertex);

	//check if given vertex lies on the given surface
	bool check_edge3d_on_surface(Edge3d edge);

};

class Surface_List{
	public:
	vector<Surface3d> S;

	//constructor for creating surface list for given edge_lists and vertex_list
	Surface_List(Edge3d_List edge3dList1,Edge3d_List edge3dList2,Vertex3d_List vertexlist);

	//emty constructor
	Surface_List();

	//function for adding a surface to surfacelist
	void addSurface(Surface3d surface_to_add);

	//function to delete a surface from a surfacelist
	void removeSurface(Surface3d surface_to_remove);

	//function to check presence of a surface in a surfacelist
	bool checkSurface(Surface3d surface_to_check);


};

//function to check if two normals are equal
bool equal_normals(Normal3d normal1,Normal3d normal2);

//function to check if two 3d_surfaces are equal
bool equal_3dsurface(Surface3d surface1, Surface3d surface2);

//dot_product of two normals
int dot_product_of_normals(Normal3d normal,Normal3d normal2);

//ax + by +cz for a normal and vertex
int product_of_normal_vertex_in3d(Normal3d normal,Vertex3d vertex);

#endif