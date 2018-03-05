#ifndef SOLID_3D
#define SOLID_3D

#include <vector>
using namespace std;
// 3d point
struct coordinate3d{
	// X cordinate
	int x;
	// Y cordinate
	int y;
	// Z cordinate
	int z;
};

//an edge of 3d solid
struct edge3d{
	//first end point
	coordinate3d x;
	//second end point
	coordinate3d y;
};

//a face in 3d solid is a vector of edges in which first and last is same
struct face3d{
	//vector of a continous loop of 3D edges which contain a face.
	vector<edge3d> v;
};


/** a 3D solid is defined by :-
 1) A list of vertices. Here they are of the form coordinate3d.
 2) A list of edges. Here they are of the form edge3d.
 3) A list of faces. Here they are of the form face3d.

**/
class solid3d{
	// list of vertices
	vector<coordinate3d> vertices;
	// list of edges
	vector<edge3d> edges;
	// list of faces
	vector<face3d> faces;
};

#endif