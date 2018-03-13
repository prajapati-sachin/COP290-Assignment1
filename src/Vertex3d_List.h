#ifndef VERTEX3D_LIST
#define VERTEX3D_LIST

#include <vector>
#include "Vertex2d_List.h"
#include "Common_functions.h"

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
 	Vertex3d (int x,int y,int z);

 	//constructor to create a vertex from 3 points in respective projections
 	Vertex3d (Vertex2d front_vertex2d, Vertex2d top_vertex2d, Vertex2d side_vertex2d);

 	Vertex2d point2d_front();

 	Vertex2d point2d_top();

 	Vertex2d point2d_side();



};


class Vertex3d_List{
	vector<Vertex3d> E;

	//constructors
	Vertex3d_List();

	//constructor to generate vertex3d list from vertex 2d list
	Vertex3d_List(Vertex2d_List top_2dvertexlist, Vertex2d_List front_2dvertexlist, Vertex2d_List side_2dvertexlist);

	//function for adding an vertex to vertexlist
	void addVertex (Vertex3d vertex_to_add);

	//function to delete an vertex from an vertexlist
	void removeVertex (Vertex3d vertex_to_remove);

	//function to check presence of a vertex in a vertexlist
	bool checkVertex(Vertex3d vertex_to_check);
	
	//function which gives the corresponding list of 2d vertices in top view 
	Vertex2d_List list_top_view();

	//function which gives the corresponding list of 2d vertices in front view 
	Vertex2d_List list_front_view();

	//function which gives the corresponding list of 2d vertices in side view 
	Vertex2d_List list_side_view();


};

namespace extra_functions{
	//function to check if two 3d_cordinates are equal
	bool equal_3dvertex(Vertex3d vertex3d1,Vertex3d vertex3d2);
	//function which checks given 3 2d coordinated a 3d vertex is possible out of those
	bool vertex3d_possible(Vertex2d front, Vertex2d top, Vertex2d side);
}


#endif