#ifndef Solid_struct
#define Solid_struct

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








#endif