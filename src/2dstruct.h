#ifndef STRUCT_2D
#define STRUCT_2D

#include <vector>
using namespace std;

// 2d point
struct coordinate2d{
	// X cordinate
	int x;
	// Y cordinate
	int y;
};

//an edge of 2d solid
struct edge2d{
	//first end point
	coordinate2d x;
	//second end point
	coordinate2d y;
};

//a face in 2d solid is a vector of 2d edges in which first and last is same
struct face2d{
	//vector of a continous loop of 2D edges which contain a face.
	vector<edge2d> v;
};

#endif