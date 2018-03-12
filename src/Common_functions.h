#ifndef COMMON_FUNCTIONS
#define COMMON_FUNCTIONS

#include <vector>
#include "Edge2d_List.h"
#include "Edge3d_List.h"
#include "Vertex2d_List.h"
#include "Vertex3d_List.h"
#include "Face3d_List.h"
#include "Surface3d_List.h"


//function to check if two 2d_cordinates are equal
bool equal_2dcoordinate(Vertex2d vertex2d1,Vertex2d vertex2d2);

//function to check if two 3d_cordinates are equal
bool equal_3dcoordinate(Vertex3d vertex3d1,Vertex3d vertex3d2);

//function to check if two 3d_edges are equal
bool equal_3dedge(Edge3d edge3d1,Edge3d edge3d2);

//function to check if two 2d_edges are equal
bool equal_2dedge(Edge2d edge2d1,Edge2d edge2d2);

//function to check if two 3d_surfaces are equal
bool equal_3dsurface(Surface3d surface1, Surface3d surface2);

//function to check if there is a common vertex between two edges
bool check_common_vertex(Edge3d edge1,Edge3d edge2);

//function to find common vertex between two edges
Vertex3d common_vertex(Edge3d edge3d1,Edge3d edge3d2);








#endif

