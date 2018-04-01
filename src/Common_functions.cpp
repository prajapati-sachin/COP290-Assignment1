#include "../include/Common_functions.h"

using namespace std;


void print_Vertex2d(Vertex2d v){
	cout << "{" << v.x << "," << v.y << "}" <<"\n";
}

void print_Vertex2d_List(Vertex2d_List v_list){
	cout << "Vertices :  ";
	for(int i=0;i<v_list.V.size();i++){
		print_Vertex2d(v_list.V[i]);
	}
}

void print_Vertex3d(Vertex3d v){
	cout << "{" << v.x << " " << v.y << " " << v.z << "}" <<"\n";	
}

void print_Vertex3d_List(Vertex3d_List v_list){
	cout << "Vertices :  ";
	for(int i=0;i<v_list.V.size();i++){
		print_Vertex3d(v_list.V[i]);
	}	
}

void print_Edge2d(Edge2d e){
	cout<< "  [v1: ";
	print_Vertex2d(e.v1);
	cout<< "  v2: ";
	print_Vertex2d(e.v2);
	cout<< "]\n";
}

void print_Edge2d_List(Edge2d_List e_list){
	cout << "Edges :  ";
	for(int i=0;i<e_list.E.size();i++){
		print_Edge2d(e_list.E[i]);
	}
}

void print_Edge3d(Edge3d e){
	cout<< "  [v1: ";
	print_Vertex3d(e.x);
	cout<< "  v2: ";
	print_Vertex3d(e.y);
	cout<< "]\n";
}

void print_Edge3d_List(Edge3d_List e_list){
	cout << "Edges :  ";
	for(int i=0;i<e_list.E.size();i++){
		print_Edge3d(e_list.E[i]);
	}
}