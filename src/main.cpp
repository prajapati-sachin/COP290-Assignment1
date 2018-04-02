#include <iostream>
#include "../include/Edge3d_List.h"
#include "../include/Edge2d_List.h"
#include "../include/HiddenLines.h"
#include "../include/Projection2d.h"
#include "../include/Solid3d.h"
#include "../include/Surface3d_List.h"
#include "../include/Vertex2d_List.h"
#include "../include/Vertex3d_List.h"
#include <math.h>
#include <QtCore>
#include <QtGui>
#include <stdlib.h>
#include <GL/glut.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glu.h>



#define PI 3.1415926536
#define SIZE 200
#define FACTOR 100

const float STEP = 2*PI/SIZE;

using namespace std;
void init(void);
void display(void);
Edge3d_List ex;


int main(int argc, char *argv[]){
//	cout << "Hello World!\n";
	cout << "Enter the mode: 1 for 3d-2d and 2 for 2d-3d\n";
	int mode;
	cin >> mode;
	if(mode==1){
		QApplication a(argc, argv);
	    QLabel l;
	    QPicture pi;
	    QPainter p(&pi);
		Vertex3d_List V;
		Edge3d_List E;
		Face3d_List F;
		// Vertex3d v1 = Vertex3d(1,1,1);
		// Vertex3d v2 = Vertex3d(1,1,2);
		// Vertex3d v3 = Vertex3d(1,2,1);
		// Vertex3d v4 = Vertex3d(1,2,2);
		// Vertex3d v5 = Vertex3d(2,1,1);
		// Vertex3d v6 = Vertex3d(2,1,2);
		// Vertex3d v7 = Vertex3d(2,2,1);
		// Vertex3d v8 = Vertex3d(2,2,2);

	// 	Vertex3d v1(1,1,1);
	// 	Vertex3d v2(1,1,2);
	// 	Vertex3d v3(1,2,1);
	// 	Vertex3d v4(1,2,2);
	// 	Vertex3d v5(2,1,1);
	// 	Vertex3d v6(2,1,2);
	// 	Vertex3d v7(2,2,1);
	// 	Vertex3d v8(2,2,2);



	// 	V.addVertex(v1);
	// 	V.addVertex(v2);
	// 	V.addVertex(v3);
	// 	V.addVertex(v4);
	// 	V.addVertex(v5);
	// 	V.addVertex(v6);
	// 	V.addVertex(v7);
	// 	V.addVertex(v8);

	// //	V.print_Vertex3d_List();


	// 	Edge3d e1(v1,v2);
	// 	Edge3d e2(v1,v3);
	// 	Edge3d e3(v1,v5);
	// 	Edge3d e4(v2,v4);
	// 	Edge3d e5(v2,v6);
	// 	Edge3d e6(v3,v4);
	// 	Edge3d e7(v3,v7);
	// 	Edge3d e8(v4,v8);
	// 	Edge3d e9(v5,v6);
	// 	Edge3d e10(v5,v7);
	// 	Edge3d e11(v6,v8);
	// 	Edge3d e12(v7,v8);



	// 	E.addEdge(e1);
	// 	E.addEdge(e2);
	// 	E.addEdge(e3);
	// 	E.addEdge(e4);
	// 	E.addEdge(e5);
	// 	E.addEdge(e6);
	// 	E.addEdge(e7);
	// 	E.addEdge(e8);
	// 	E.addEdge(e9);
	// 	E.addEdge(e10);
	// 	E.addEdge(e11);
	// 	E.addEdge(e12);
		
	//	E.print_Edge3d_List();


	FILE * file = fopen("examples/pyramid.obj", "r");
	if( file == NULL ){
	    printf("Impossible to open the file !\n");
	    return false;
	}

	while(1){

	    char lineHeader[128];
	    // read the first word of the line
	    int res = fscanf(file, "%s", lineHeader);
	    if (res == EOF)
	        break; // EOF = End Of File. Quit the loop.
	    // else : parse lineHeader
	    else{
	    	if ( strcmp( lineHeader, "v" ) == 0 ){
		    	int x,y,z;
		    	fscanf(file, "%d %d %d\n", &x, &y, &z );
		    	Vertex3d v(x,y,z);
		    	V.addVertex(v);
		    }
	    	else if ( strcmp( lineHeader, "f" ) == 0 ){
			    int x,y,z;
			    fscanf(file, "%d %d %d\n", &x, &y, &z);
					
				Edge3d e1(V.V[x-1],V.V[y-1]);	
				Edge3d e2(V.V[y-1],V.V[z-1]);
				Edge3d e3(V.V[x-1],V.V[z-1]);
				E.addEdge(e1);
				E.addEdge(e2);
				E.addEdge(e3);
			}
	    }
	    
	}

		V.print_Vertex3d_List();
		E.print_Edge3d_List();

		Solid3d solid(V,E,F);

		Projection2d front_projection = solid.make_front_projections();

		Projection2d top_projection = solid.make_top_projections();

		Projection2d side_projection = solid.make_side_projections();

		// (front_projection.V).print_Vertex2d_List();

		// (front_projection.E).print_Edge2d_List();	
		
		// (top_projection.V).print_Vertex2d_List();
		
		// front_projection.V.print_Vertex2d_List();

		// front_projection.E.print_Edge2d_List();	

		// top_projection.V.print_Vertex2d_List();

		// top_projection.E.print_Edge2d_List();	

		// side_projection.V.print_Vertex2d_List();

		// side_projection.E.print_Edge2d_List();	

		// Projection projections(front_projection, top_projection, side_projeciton);

		// Solid3d solid1(projections);

		// solid1.V.print_Vertex3d_List();

		// solid1.E.print_Edge3d_List();

		// (top_projection.E).print_Edge2d_List();	
		
		// (side_projection.V).print_Vertex2d_List();

		// (side_projection.E).print_Edge2d_List();	
		p.setRenderHint(QPainter::Antialiasing);
		p.setPen(QPen(Qt::black, 0.02, Qt::SolidLine, Qt::SquareCap));
		for(int i=0;i<((front_projection.E).E).size();i++){
	   		 p.drawLine((((((front_projection.E).E)[i]).v1).x)+1,(((((front_projection.E).E)[i]).v1).y)+1, (((((front_projection.E).E)[i]).v2).x)+1, (((((front_projection.E).E)[i]).v2).y)+1);
	   	}

		for(int i=0;i<((top_projection.E).E).size();i++){
	   		 p.drawLine((((((top_projection.E).E)[i]).v1).x)+1,(((((top_projection.E).E)[i]).v1).y)-1, (((((top_projection.E).E)[i]).v2).x)+1, (((((top_projection.E).E)[i]).v2).y)-1);
	   	}

	   	for(int i=0;i<((side_projection.E).E).size();i++){
	   		 p.drawLine((((((side_projection.E).E)[i]).v1).x)-1,(((((side_projection.E).E)[i]).v1).y)+1, (((((side_projection.E).E)[i]).v2).x)-1, (((((side_projection.E).E)[i]).v2).y)+1);
	   	}
	   	// for(int i=0;i<((front_projection.V).V).size();i++){
	   	// 	 p.drawPoint((((front_projection.V).V[i]).x),(((front_projection.V).V[i]).y));
	   	// }

	   	// for(int i=0;i<((top_projection.V).V).size();i++){
	   	// 	 p.drawPoint((((top_projection.V).V[i]).x),(((top_projection.V).V[i]).y));
	   	// }

	   	// for(int i=0;i<((side_projection.V).V).size();i++){
	   	// 	 p.drawPoint((((side_projection.V).V[i]).x),(((side_projection.V).V[i]).y));
	   	// }

	   	p.drawLine(0,0,5,0);
	   	p.drawLine(0,0,-5,0);
		p.drawLine(0,0,0,5);
	   	p.drawLine(0,0,0,-5);

	//   	p.drawPoint(-1,1);

	   	p.end(); // Don't forget this line!
	   	l.setPicture(pi);
	   	l.show();
	   	l.setScaledContents(true);
	   	
	   	return a.exec();

	}

    if(mode==2){
  		Vertex3d_List V;
		Edge3d_List E;
		Face3d_List F;


		Vertex3d v1(1,1,1);
		Vertex3d v2(1,1,2);
		Vertex3d v3(1,2,1);
		Vertex3d v4(1,2,2);
		Vertex3d v5(2,1,1);
		Vertex3d v6(2,1,2);
		Vertex3d v7(2,2,1);
		Vertex3d v8(2,2,2);



		V.addVertex(v1);
		V.addVertex(v2);
		V.addVertex(v3);
		V.addVertex(v4);
		V.addVertex(v5);
		V.addVertex(v6);
		V.addVertex(v7);
		V.addVertex(v8);

		//V.print_Vertex3d_List();


		Edge3d e1(v1,v2);
		Edge3d e2(v1,v3);
		Edge3d e3(v1,v5);
		Edge3d e4(v2,v4);
		Edge3d e5(v2,v6);
		Edge3d e6(v3,v4);
		Edge3d e7(v3,v7);
		Edge3d e8(v4,v8);
		Edge3d e9(v5,v6);
		Edge3d e10(v5,v7);
		Edge3d e11(v6,v8);
		Edge3d e12(v7,v8);



		E.addEdge(e1);
		E.addEdge(e2);
		E.addEdge(e3);
		E.addEdge(e4);
		E.addEdge(e5);
		E.addEdge(e6);
		E.addEdge(e7);
		E.addEdge(e8);
		E.addEdge(e9);
		E.addEdge(e10);
		E.addEdge(e11);
		E.addEdge(e12);
		

		// FILE * file = fopen("examples/cube.txt", "r");
		// if( file == NULL ){
		//     printf("Impossible to open the file !\n");
		//     return false;
		// }

		// Vertex2d_List front_vertices;
		// Edge2d_List front_edges;

		// Vertex2d_List top_vertices;
		// Edge2d_List top_edges;

		// Vertex2d_List side_vertices;
		// Edge2d_List side_edges;

		// while(1){
		//     char lineHeader[128];
		//     // read the first word of the line
		//     int res = fscanf(file, "%s", lineHeader);
		//     if (res == EOF)
		//         break; // EOF = End Of File. Quit the loop.
		//     // else : parse lineHeader
		//     else{
		//     	//vertex of front projection
		//     	if ( strcmp( lineHeader, "fv" ) == 0 ){
		// 	    	int x,y;
		// 	    	fscanf(file, "%d %d\n", &x, &y);
		// 	    	Vertex2d v(x,y);
		// 	    	front_vertices.addVertex(v);
		// 	    }
		//     	//vertex of top projection
		//     	else if ( strcmp( lineHeader, "tv" ) == 0 ){
		// 	    	int x,y;
		// 	    	fscanf(file, "%d %d\n", &x, &y);
		// 	    	Vertex2d v(x,y);
		// 	    	top_vertices.addVertex(v);
		// 	    }
		// 	    //vertex of side projection
		// 	    else if ( strcmp( lineHeader, "sv" ) == 0 ){
		// 	    	int x,y;
		// 	    	fscanf(file, "%d %d\n", &x, &y);
		// 	    	Vertex2d v(x,y);
		// 	    	side_vertices.addVertex(v);
		// 	    }
		//     	//edge of front projection
		//     	else if ( strcmp( lineHeader, "fe" ) == 0 ){
		// 		    int x,y;
		// 		    fscanf(file, "%d %d\n", &x, &y);
						
		// 			Edge2d e(front_vertices.V[x], front_vertices.V[y]);	
		// 			front_edges.addEdge(e);
		// 		}
		//     	//edge of top projection
		//     	else if ( strcmp( lineHeader, "te" ) == 0 ){
		// 		    int x,y;
		// 		    fscanf(file, "%d %d\n", &x, &y);
						
		// 			Edge2d e(top_vertices.V[x], top_vertices.V[y]);	
		// 			top_edges.addEdge(e);
		// 		}
		// 		//edge of side projection
		//     	else if ( strcmp( lineHeader, "se" ) == 0 ){
		// 		    int x,y;
		// 		    fscanf(file, "%d %d\n", &x, &y);
						
		// 			Edge2d e(side_vertices.V[x], side_vertices.V[y]);	
		// 			side_edges.addEdge(e);
		// 		}
		//     }
		    
		// }


		// Projection2d front_projection(front_vertices, front_edges);

		// Projection2d top_projection(top_vertices, top_edges);

		// Projection2d side_projection(side_vertices, side_edges);















		//E.print_Edge3d_List();

		Solid3d solid(V,E,F);

		Projection2d front_projection = solid.make_front_projections();

		Projection2d top_projection = solid.make_top_projections();

		Projection2d side_projection = solid.make_side_projections();


	//	(front_projection.V).print_Vertex2d_List();

	//	(front_projection.E).print_Edge2d_List();
 
//		(top_projection.V).print_Vertex2d_List();

//		(top_projection.E).print_Edge2d_List();	

		// (side_projection.V).print_Vertex2d_List();

		// (side_projection.E).print_Edge2d_List();	

		Projection projections(front_projection, top_projection, side_projection);

		Solid3d solid1(projections);

		solid1.V.print_Vertex3d_List();

		solid1.E.print_Edge3d_List();   

		ex=solid1.E;
    
		 
		
		  glutInit(&argc, argv);
		  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		  glutInitWindowSize(300, 300);
		  glutInitWindowPosition(400, 400);
		  glutCreateWindow("Solid Model");
		  init();
		  glutDisplayFunc(display);
		  glutMainLoop();
		  return 0;
		


   }

}

		void init(void)
		{
		  glClearColor(0.0, 0.0, 1.0, 0.0);
		  glMatrixMode(GL_PROJECTION);
		  glLoadIdentity();
		  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
		}
		 
	
		void display(void)
		{
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			/* use this length so that camera is 1 unit away from origin */
			double dist = sqrt(7 / 3.0);

			gluLookAt(dist, dist, dist,  /* position of camera */
			          -1.0,  0.0, 0.0,   /* where camera is pointing at*/  
			          0.0,  1.0,  0.0);  /* which direction is up */
			 glMatrixMode(GL_MODELVIEW);

			glBegin(GL_LINES);

			for(int i=0;i<ex.E.size();i++){
				// glColor3f(1.0, 0.0, 0.0);
				// glVertex3f(1.0, 1.0, 1.0);
				// glVertex3f(1.0, 1.0, 2.0);

				// glColor3f(1.0, 0.0, 0.0);
				// glVertex3f(1.0, 1.0, 1.0);
				// glVertex3f(1.0, 2.0, 2.0);

				// glColor3f(1.0, 0.0, 0.0);
				// glVertex3f(1.0, 1.0, 1.0);
				// glVertex3f(2.0, 1.0, 1.0);

				// glColor3f(1.0, 0.0, 0.0);
				// glVertex3f(1.0, 1.0, 1.0);
				// glVertex3f(2.0, 1.0, 2.0);

				//   glColor3f(1.0, 1.0, 0.0);
				//   glVertex3f(1.0, 2.0, 2.0);
				//   glVertex3f(2.0, 2.0, 2.0);

				//   glColor3f(1.0, 0.0, 1.0);
				//   glVertex3f(2.0, 1.0, 1.0);
				//   glVertex3f(1.0, 1.0, 1.0);

				//   glColor3f(1.0, 1.0, 0.0);
				//   glVertex3f(2.0, 1.0, 1.0);
				//   glVertex3f(2.0, 1.0, 2.0);

				//   glColor3f(1.0, 0.0, 0.0);
				//   glVertex3f(2.0, 1.0, 1.0);
				//   glVertex3f(2.0, 2.0, 2.0);

				//   glColor3f(1.0, 0.0, 0.0);
				//   glVertex3f(2.0, 1.0, 2.0);
				//   glVertex3f(1.0, 1.0, 2.0);

				  glColor3f(1.0, 0.0, 0.0);
				  glVertex3f((((ex).E[i]).x).x, (((ex).E[i]).x).y,(((ex).E[i]).x).z);
				  glVertex3f((((ex).E[i]).y).x, (((ex).E[i]).y).y, (((ex).E[i]).y).z);

			}
			glEnd();

			glFlush();

		}