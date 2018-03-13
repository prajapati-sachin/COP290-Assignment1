#include "Vertex3d_List.h"
#include "Vertex2d_List.h"

using namespace std;

Vertex3d::Vertex3d(int x1, int y1, int z1){
	//constructor for 3d Vertex
	x=x1;
	y=y1;
	z=z1;
}

Vertex3d::Vertex3d(Vertex2d front, Vertex2d top, Vertex2d side){
	//constructor to create a 3d vertex from 3 2d coordinates
	//check if a 3d vertex is possible out of these
	if(extra_functions::vertex3d_possible(front, top ,side)){
		x=(front.x);
		y=(front.y);
		z=-1*(top.y);
	}
}

Vertex2d Vertex3d::point2d_front(){
	int x1;
	int y1;
	//actual coordinates same as in 3d
	x1=x;
	y1=y;
	Vertex2d temp(x1,y1);
	return temp;
}


Vertex2d Vertex3d::point2d_top(){
	int x1;
	int y1;
	//in this case (x,-z) are the corresponding coordinates in XY plane
	x1=x;
	y1=(-1)*z;
	Vertex2d temp(x1,y1);
	return temp;
}


Vertex2d Vertex3d::point2d_side(){
	int x1;
	int y1;
	//in this case (-z,y) are the corresponding coordinates in XY plane
	x1=(-1)*z;
	y1=y;
	Vertex2d temp(x1,y1);
	return temp;
}
