#ifndef HIDDEN_LINE
#define HIDDEN_LINE

#include <vector>
#include "Vertex2d_List.h"
#include "Edge2d_List.h"
#include "Vertex3d_List.h"
#include "Edge3d_List.h"
#include "Surface3d_List.h"
#include "Face3d_List.h"

namespace Hidden_line_functions{

//marks the hidden 2d egde in the given 2d edge list  hidden or not
Edge2d_List mark_hidden(Edge2d_List 2dEdgelist ,Edge3d_List 3dEdgelist,Face3d_List 3dFacelist);

//check if a given 2dedge will be hidden or not
bool check_hidden(Edge2d 2dEdge ,Edge3d_List 3dEdgelist, Face3d_List 3dFacelist);

//for a given 3d edgelist the function returns corresponding 3d edge list of a 2dedge i.e whose projection in 2d front plane gives these as a 2d edge
Edge3d_List corresponding_3dEdgelist_front(Edge2d 2dEdge, Edge3d_List 3dEdgelist);

//for a given 3d edgelist the function returns corresponding 3d edge list of a 2dedge i.e whose projection in 2d top plane gives these as a 2d edge
Edge3d_List corresponding_3dEdgelist_top(Edge2d 2dEdge, Edge3d_List 3dEdgelist);

//for a given 3d edgelist the function returns corresponding 3d edge list of a 2dedge i.e whose projection in 2d side plane gives these as a 2d edge
Edge3d_List corresponding_3dEdgelist_side(Edge2d 2dEdge, Edge3d_List 3dEdgelist);

//image of the vertex in the front plane
Vertex3d front_image(Vertex3d vertex);

//image of the vertex in the top plane
Vertex3d top_image(Vertex3d vertex);

//image of the vertex in the side plane
Vertex3d side_image(Vertex3d vertex);

//checks if the vertices lie on the same side of surface.
bool check_on_same_side_of_surface(Surface3d surface,Vertex3d vertex1,Vertex3d vertex2);

//the function returns a 2d projection list in front plane for given 3d facelist 
Face2d_List projection_of_face_on_front(Face3d_List 3dFacelist);

//the function returns a 2d projection list in top plane for given 3d facelist 
Face2d_List projection_of_face_on_top(Face3d_List 3dFacelist);

//the function returns a 2d projection list in side plane for given 3d facelist 
Face2d_List projection_of_face_on_side(Face3d_List 3dFacelist);

//check if a point is inside the polygon by  crossing number method
bool check_inside_a_2dface(Vertex2d 2dVertex, Face2d 2dFace);


}










