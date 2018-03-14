#include "Edge2d_List.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Edge2d class
//constructor for ed Edge

Edge2d::Edge2d(Vertex2d vertex1, Vertex2d vertex2){
	v1 = vertex1;
	v2 = vertex2;
	hidden = false;
	
}

Edge2d::make_hidden(){
	hidden = true;
}

Edge2d::make_visible(){
	hidden = false;
}

bool Edge2d::check_inside(Vertex2d 2dvertex){
	
}