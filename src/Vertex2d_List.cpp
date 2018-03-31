#include "../include/Vertex2d_List.h"

using namespace std;

int DELTA = 0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Vertex2d class
//constructor for 2d Vertex
Vertex2d::Vertex2d(int x, int y){
	
	this->x=x;
	this->y=y;
}

Vertex2d::Vertex2d(){};
// Vertex2d::Vertex2d(){
	
// 	this->x=0;
// 	this->y=0;
// }

/////////////////////////////////////////////////////////////
//Implementation of Vertex2d_List class
Vertex2d_List::Vertex2d_List(){};

//function for adding an vertex to vertexlist
void Vertex2d_List::addVertex(Vertex2d v){
	V.push_back(v);
}

//function to check presence of a vertex in a vertexlist
bool Vertex2d_List::checkVertex(Vertex2d v){
	bool result=false;
	for(int i=0;i<V.size();i++){
		if(equal_2dVertex(V[i], v)){
			result=true;
		}
	}
	return result;
}

//function to delete a vertex from a vertexlist
void Vertex2d_List::removeVertex(Vertex2d v){
	if(checkVertex(v)){
		for(int i=0;i<V.size();i++){
			if(equal_2dVertex(V[i], v)){
				V.erase(V.begin()+i);
			}
		}
	}
}

////////////////////////////////////////////////////////////
//other functions

//function to check if two 2d_cordinates are equal
bool equal_2dVertex(Vertex2d v1,Vertex2d v2){
	return (((v1.x-v2.x)==DELTA)&&((v1.y-v2.y)==DELTA));
}