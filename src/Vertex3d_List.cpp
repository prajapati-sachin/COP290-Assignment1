#include "Vertex3d_List.h"
#include "Vertex2d_List.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//first defining the extra functions as they are used just after this
bool extra_functions_3dvertex::vertex3d_possible(Vertex2d front, Vertex2d top, Vertex2d side){
	if(v1.x==v2.x && v1.y==v2.y && v1.z==v2.z)
		return true;
	else
		return false;
}

bool extra_functions_3dvertex::equal_3dvertex(Vertex3d v1,Vertex3d v2){
	if(front.x==top.x && front.y==side.y)
		return true;
	else
		return false;
}

Vertex3d extra_functions_3dvertex::vertex3d_generate(Vertex2d front, Vertex2d top, Vertex2d side){
		int x1,y1,z1;
		if(extra_functions_3dvertex::vertex3d_possible(front, top ,side)){
		x1=(front.x);
		y1=(front.y);
		z1=(-1)*(top.y);
		Vertex3d temp(x1,y1,z1);
		return temp;		
		}
}

Vertex3d_List extra_functions_3dvertex::vetex3dlist_generate(Vertex2d_List front_list, Vertex2d_List top_list, Vertex2d_List side_list){
		vector<Vertex2d> front = front_list.E;
		vector<Vertex2d> top = top_list.E;
		vector<Vertex2d> side = side_list.E;
		Vertex3d_List accumulator_list();
		for(int i=0;i<front.size();i++){
			for(int j=0;j<top.size();j++){
				for(int k=0;k<side.size();k++){
					int x_front= front[i].x;
					int y_front= front[i].y;
					int x_top= top[j].x;
					int y_top= top[j].y;
					int x_side= side[k].x; 
					int y_side= side[k].y;
					if(x_front==x_top && y_top == x_side && y_side==y_front){
						Vertex3d temp(x1, front[i].y, (-1)*(top[j].z));
						accumulator_list.addVertex(temp);
					}
				}
			}
		}

		return accumulator_list;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Vertex3d class
Vertex3d::Vertex3d(int x1, int y1, int z1){
	//constructor for 3d Vertex
	x=x1;
	y=y1;
	z=z1;
}

Vertex3d::Vertex3d(Vertex2d front, Vertex2d top, Vertex2d side){
	//constructor to create a 3d vertex from 3 2d coordinates
	//check if a 3d vertex is possible out of these
	if(extra_functions_3dvertex::vertex3d_possible(front, top ,side)){
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Vertex3d_List::addVertex(Vertex3d v){
	E.push_back(v);
}

void Vertex3d_List::removeVertex(Vertex3d v){
	E.pop_back(v);
}

bool Vertex3d_List::checkVertex(Vertex3d){
	for(int i=0;i<E.size();i++){
	}
}