#ifndef VERTEX3D_LIST
#define VERTEX3D_LIST

#include <vector>
#include "Vertex2d_List.h"


using namespace std;

/** Vertex :-  3d coordinate for 3d solid **/
class Vertex3d{
	public:
	// X cordinate
	int x;
	// Y cordinate
	int y;
	// Z cordinate
	int z;

	//constructor
 	Vertex3d (int x1,int y1,int z1);

 	//empty construtor
 	Vertex3d ();

 	//constructor to create a vertex from 3 points in respective projections
 	Vertex3d (Vertex2d front, Vertex2d top, Vertex2d side);

 	Vertex2d point2d_front();

 	Vertex2d point2d_top();

 	Vertex2d point2d_side();



};

class Vertex3d_List{
public:
	vector<Vertex3d> V;
	//constructor not needed in this class
	//empty constructors
	Vertex3d_List();

	//constructor to generate vertex3d list from vertex 2d list
	Vertex3d_List(Vertex2d_List top_2dvertexlist, Vertex2d_List front_2dvertexlist, Vertex2d_List side_2dvertexlist);

	//function for adding an vertex to vertexlist
	void addVertex (Vertex3d v);

	//function to delete an vertex from an vertexlist
	void removeVertex (Vertex3d v);

	//function to check presence of a vertex in a vertexlist
	bool checkVertex(Vertex3d v);
	
	
	//function which gives the corresponding list of 2d vertices in front view 
	Vertex2d_List list_frontview();

	//function which gives the corresponding list of 2d vertices in top view 
	Vertex2d_List list_topview();

	//function which gives the corresponding list of 2d vertices in side view 
	Vertex2d_List list_sideview();


};

namespace extra_functions_3dvertex{
	//function to check if two 3d_cordinates are equal
	bool equal_3dvertex(Vertex3d v1,Vertex3d v2);
	//function which checks given 3 2d coordinated a 3d vertex is possible out of those
	bool vertex3d_possible(Vertex2d front, Vertex2d top, Vertex2d side);
	//function which generates a 3d vertex from 3 2d coordinates
	Vertex3d vertex3d_generate(Vertex2d front, Vertex2d top, Vertex2d side);
	//function which extends the above function to list
	Vertex3d_List vetex3dlist_generate(Vertex2d_List front_list, Vertex2d_List top_list, Vertex2d_List side_list);
	//function which given a 3d vertex vector and a vertex gives the index at which vertex is present
	int vertex_index(vector<Vertex3d> vlist, Vertex3d v);
}


#endif