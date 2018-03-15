#include "HiddenLines.h"

namespace Hidden_line_functions{

//marks the hidden 2d egde in the given 2d edge list  hidden or not
Edge2d_List mark_hidden(Edge2d_List 2dEdgelist ,Edge3d_List 3dEdgelist,Face3d_List 3dFacelist){
	vector<Edge2d> list = 2dEdgelist.E
	for(int i=0;i<list.size();i++){
		if(check_hidden(list[i],3dEdgelist,3dFacelist))
			list[i].Edge2d::make_hidden();
	}
}