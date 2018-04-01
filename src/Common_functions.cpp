#include "../include/Common_functions.h"

using namespace std;


void print_Vertex2d(Vertex2d v){
	cout << v.x << " " << v.y <<"/n";
}

void print_Vertex2d_List(Vertex2d_List v_list){
	for(int i=0;i<v_list.V.size();i++){
		print_Vertex2d(v_list.V[i]);
	}
}