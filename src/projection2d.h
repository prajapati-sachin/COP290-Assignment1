#ifndef PROJECTION_2D
#define PROJECTION_2D

#include <vector>
using namespace std;

// 2d point
struct coordinate2d{
	// X cordinate
	int x;
	// Y cordinate
	int y;
};

//an line of 2d projection
struct edge2d{
	//first end point
	coordinate2d x;
	//second end point
	coordinate2d y;
	bool hidden;
};
/**
 A particular view of a 3D solid consist of a 2D drawing.
 1) It will contain some 2d points on a plane that is we should have a vector of 2d points
 2) Also it will have a list of 2D edges as in which points are joined together and also each such edge will have a bool which shows this edge is hidden
    or visible in that view.
**/
struct view{
	vector<coordinate2d> points;
	vector<edge2d> lines;
};



/** a 2D projection of a 3D solid is defined by :-
 1) 3 views, that are Front, Top and Side View.

**/
class projection2d{
	// Top View
	view top;
	// Front View
	view front;
	// Side View
	view side;
	
};

#endif