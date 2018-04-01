#include "../include/Vertex3d_List.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//first defining the extra functions as they are used just after this
namespace extra_functions_3dvertex{
	bool vertex3d_possible(Vertex2d front, Vertex2d top, Vertex2d side){
		if(front.x==top.x && top.y==side.x && side.y==front.y)
			return true;
		else
			return false;
	}

	bool equal_3dvertex(Vertex3d v1,Vertex3d v2){
		if(v1.x==v2.x && v1.y==v2.y && v1.z==v2.z)
			return true;
		else
			return false;
	}


	Vertex3d vertex3d_generate(Vertex2d front, Vertex2d top, Vertex2d side){
		int x1,y1,z1;
		if(extra_functions_3dvertex::vertex3d_possible(front, top ,side)){
		x1=(front.x);
		y1=(front.y);
		z1=(-1)*(top.y);
		Vertex3d temp(x1,y1,z1);
		return temp;		
		}
	}


	vector<Vertex3d> vertex3dlist_generate(Vertex2d_List front_list, Vertex2d_List top_list, Vertex2d_List side_list){
		vector<Vertex2d> front = front_list.V;
		vector<Vertex2d> top = top_list.V;
		vector<Vertex2d> side = side_list.V;
		vector<Vertex3d> accumulator_list;
		for(int i=0;i<front.size();i++){
			for(int j=0;j<top.size();j++){
				for(int k=0;k<side.size();k++){
					 if(extra_functions_3dvertex::vertex3d_possible(front[i],top[j],side[k])){
						accumulator_list.push_back(extra_functions_3dvertex::vertex3d_generate(front[i],top[j],side[k]));
					}
				}
			}
		}

		return accumulator_list;
	}
	
	int vertex_index(vector<Vertex3d> vlist, Vertex3d v){
		int result=-1;
		for(int i=0;i<vlist.size();i++){
			if(equal_3dvertex(vlist[i],v)){
				result=i;
			}
		}
		return result;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Vertex3d class

Vertex3d::Vertex3d(){}


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


void Vertex3d::print_Vertex3d(){
	cout << "{" << x << " " << y << " " << z << "}" <<"\n";	
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of class Vertex3d_List.h
Vertex3d_List::Vertex3d_List(){};

Vertex3d_List::Vertex3d_List(Vertex2d_List top_2dvertexlist, Vertex2d_List front_2dvertexlist, Vertex2d_List side_2dvertexlist){
	V= extra_functions_3dvertex::vertex3dlist_generate(top_2dvertexlist, front_2dvertexlist, side_2dvertexlist);
}


void Vertex3d_List::addVertex(Vertex3d v){
	V.push_back(v);
}

void Vertex3d_List::removeVertex(Vertex3d v){
	if(checkVertex(v)){
		int i = extra_functions_3dvertex::vertex_index(V,v);
		V.erase(V.begin()+i);
	}
}

bool Vertex3d_List::checkVertex(Vertex3d v){
	bool result=false;
	for(int i=0;i<V.size();i++){
		if(extra_functions_3dvertex::equal_3dvertex(V[i], v)){
			result=true;
		}
	}
	return result;
}

Vertex2d_List Vertex3d_List::list_frontview(){
	Vertex2d_List front_projections;
	for(int i=0;i<V.size();i++){
		Vertex3d temp = V[i];
		Vertex2d projection = temp.point2d_front();
		(front_projections.V).push_back(projection);
	}
}

Vertex2d_List Vertex3d_List::list_topview(){
	Vertex2d_List top_projections;
	for(int i=0;i<V.size();i++){
		Vertex3d temp = V[i];
		Vertex2d projection = temp.point2d_top();
		(top_projections.V).push_back(projection);
	}
}



Vertex2d_List Vertex3d_List::list_sideview(){
	Vertex2d_List side_projections;
	for(int i=0;i<V.size();i++){
		Vertex3d temp = V[i];
		Vertex2d projection = temp.point2d_side();
		(side_projections.V).push_back(projection);
	}	
}


void Vertex3d_List::print_Vertex3d_List(){
	cout << "Vertices :  ";
	for(int i=0;i<V.size();i++){
		V[i].print_Vertex3d();
	}	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
