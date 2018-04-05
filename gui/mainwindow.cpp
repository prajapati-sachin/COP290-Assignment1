#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QtCore>
#include <QtGui>
#include <stdlib.h>
#include "Edge3d_List.h"
#include "Edge2d_List.h"
#include "HiddenLines.h"
#include "Projection2d.h"
#include "Solid3d.h"
#include "Surface3d_List.h"
#include "Vertex2d_List.h"
#include "Vertex3d_List.h"

using namespace std;
QString filename2;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename1 = QFileDialog::getOpenFileName(this, tr("Choose OBJ file"), "", tr("OBJ Files (*.obj *.OBJ)"));
    //QString filename1;
    //QApplication a(argc, argv);
    string text = filename1.toUtf8().constData();
//    cout << text;
    const char * c = text.c_str();
//    cout << c;
    QLabel l;
    QPicture pi;
    QPainter p(&pi);
    Vertex3d_List V;
    Edge3d_List E;
    Face3d_List F;

    FILE * file = fopen(c, "r");
    if( file == NULL ){
        printf("Impossible to open the file !\n");
      //  return false;
    }
    int EndFile =0;
    while(1){
        int u=1;
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
                int x,y,first;
                //cout << "f ";
                //cout << "1";

                //fscanf(file, "%d %d %d\n", &x, &y, &z);

                // Edge3d e1(V.V[x-1],V.V[y-1]);
                // Edge3d e2(V.V[y-1],V.V[z-1]);
                // Edge3d e3(V.V[x-1],V.V[z-1]);
                // E.addEdge(e1);
                // E.addEdge(e2);
                // E.addEdge(e3);
                /////////////////////////////////////
                fscanf(file, "%d", &x);
                //cout << x;
                //cout << "2";
                first=x;

                while(1){
                    char c;
                    fscanf(file, "%c" , &c);
                    if(c==' '){
                    //	cout << "3";
                    //	 cout << ' ';
                    //	cout << "I am the bug";
                    }
                    else if(c == EOF){
                        EndFile =1;
                        Edge3d e1(V.V[x-1],V.V[first-1]);
                        E.addEdge(e1);
                        break;
                    }
                    else if(c=='\n'){
                    //	cout << '\n';
                    //	cout << "4";
                        Edge3d e1(V.V[x-1],V.V[first-1]);
                        E.addEdge(e1);
                        break;
                    }
                    fscanf(file, "%d", &y);
                        //	cout <<u;
                    //	cout << y;
                        //cout << "5";
                        Edge3d e1(V.V[x-1],V.V[y-1]);
                        E.addEdge(e1);
                        x=y;

                }
                u++;
                if(EndFile ==1){
                    break;
                }

            }
        }

    }
// OBJ Parder reference from - https://github.com/saranshiitd/cop_assignment1
   // V.print_Vertex3d_List();
    //E.print_Edge3d_List();

    Solid3d solid(V,E,F);

    Projection2d front_projection = solid.make_front_projections();

    Projection2d top_projection = solid.make_top_projections();

    Projection2d side_projection = solid.make_side_projections();

    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap));
    for(int i=0;i<((front_projection.E).E).size();i++){
         p.drawLine(((((((front_projection.E).E)[i]).v1).x)+1)*100,((((((front_projection.E).E)[i]).v1).y)+4)*100, ((((((front_projection.E).E)[i]).v2).x)+1)*100, ((((((front_projection.E).E)[i]).v2).y)+4)*100);
    }

    for(int i=0;i<((top_projection.E).E).size();i++){
         p.drawLine(((((((top_projection.E).E)[i]).v1).x)+1)*100,((((((top_projection.E).E)[i]).v1).y)-1)*100, ((((((top_projection.E).E)[i]).v2).x)+1)*100, ((((((top_projection.E).E)[i]).v2).y)-1)*100);
    }

    for(int i=0;i<((side_projection.E).E).size();i++){
         p.drawLine(((((((side_projection.E).E)[i]).v1).x)-1)*100,((((((side_projection.E).E)[i]).v1).y)+4)*100, ((((((side_projection.E).E)[i]).v2).x)-1)*100, ((((((side_projection.E).E)[i]).v2).y)+4)*100);
    }

    p.drawLine(700,0,-700,0);
    p.drawLine(0,600,0,-600);
//    p.translate(width()/2, height()/2);
//    p.drawLine(width()/2,0,-width()/2,0);
//    p.drawLine(0,height()/2,0,-height()/2);

//    p.drawText(25,-15,"Isometric view");
    p.drawText(25,25,"Front view");
    p.drawText(25,-15,"Top view");
    p.drawText(-100,25,"Side view");

    p.end(); // Don't forget this line!
    ui->label->setPicture(pi);
    ui->label->setScaledContents(true);
    //l.setPicture(pi);
    //l.show();
    //l.setScaledContents(true);

    //cout << "I'm done";
}

void MainWindow::on_pushButton_2_clicked()
{
    //filename2 = ui->lineEdit_2->text();
//    Vertex3d_List V;
//    Edge3d_List E;
//    Face3d_List F;
    //QApplication a(argc, argv);
    //QLabel l;
    QPicture pi;
    QPainter p(&pi);
//////////////////////
    QString filename1 = QFileDialog::getOpenFileName(this, tr("Choose text file"), "", tr("OBJ Files (*.txt *.OBJ)"));
    string text = filename1.toUtf8().constData();
     const char * c = text.c_str();
/////////////////////
/////////////////////////////////////////////////////
//CUBE
//    Vertex3d v1(1,1,1);
//    Vertex3d v2(1,1,2);
//    Vertex3d v3(1,2,1);
//    Vertex3d v4(1,2,2);
//    Vertex3d v5(2,1,1);
//    Vertex3d v6(2,1,2);
//    Vertex3d v7(2,2,1);
//    Vertex3d v8(2,2,2);
//    Vertex3d v6(2,1,2);
//    Vertex3d v7(2,2,1);
//    Vertex3d v8(2,2,2);



//    V.addVertex(v1);
//    V.addVertex(v2);
//    V.addVertex(v3);
//    V.addVertex(v4);
//    V.addVertex(v5);
//    V.addVertex(v6);
//    V.addVertex(v7);
//    V.addVertex(v8);

//    Edge3d e1(v1,v2);
//    Edge3d e2(v1,v3);
//    Edge3d e3(v1,v5);
//    Edge3d e4(v2,v4);
//    Edge3d e5(v2,v6);
//    Edge3d e6(v3,v4);
//    Edge3d e7(v3,v7);
//    Edge3d e8(v4,v8);
//    Edge3d e9(v5,v6);
//    Edge3d e10(v5,v7);
//    Edge3d e11(v6,v8);
//    Edge3d e12(v7,v8);



//    E.addEdge(e1);
//    E.addEdge(e2);
//    E.addEdge(e3);
//    E.addEdge(e4);
//    E.addEdge(e5);
//    E.addEdge(e6);
//    E.addEdge(e7);
//    E.addEdge(e8);
//    E.addEdge(e9);
//    E.addEdge(e10);
//    E.addEdge(e11);
//    E.addEdge(e12);
//////////////////////////////////////////////////////////////////////////////////
//Pyramid
//     Vertex3d v1(0,0,0);
//     Vertex3d v2(2,0,0);
//     Vertex3d v3(2,0,2);
//     Vertex3d v4(0,0,2);
//     Vertex3d v5(-3,-3,-3);



//     V.addVertex(v1);
//     V.addVertex(v2);
//     V.addVertex(v3);
//     V.addVertex(v4);
//     V.addVertex(v5);

//    // V.print_Vertex3d_List();



//     Edge3d e1(v1,v2);
//     Edge3d e2(v2,v3);
//     Edge3d e3(v3,v4);
//     Edge3d e4(v4,v1);
//     Edge3d e5(v2,v5);
//     Edge3d e6(v3,v5);
//     Edge3d e7(v1,v5);
//     Edge3d e8(v4,v5);



//     E.addEdge(e1);
//     E.addEdge(e2);
//     E.addEdge(e3);
//     E.addEdge(e4);
//     E.addEdge(e5);
//     E.addEdge(e6);
//     E.addEdge(e7);
//     E.addEdge(e8);

//    //E.print_Edge3d_List();

//    Solid3d solid(V,E,F);

//    Projection2d front_projection = solid.make_front_projections();

//    Projection2d top_projection = solid.make_top_projections();

//    Projection2d side_projection = solid.make_side_projections();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     Vertex2d_List front_vertices;
     Edge2d_List front_edges;

     Vertex2d_List top_vertices;
     Edge2d_List top_edges;

     Vertex2d_List side_vertices;
     Edge2d_List side_edges;

     FILE * file = fopen(c, "r");
     if( file == NULL ){
         printf("Impossible to open the file !\n");
       //  return false;
     }

     while(1){
         char lineHeader[128];
         // read the first word of the line
         int res = fscanf(file, "%s", lineHeader);
         if (res == EOF)
             break; // EOF = End Of File. Quit the loop.
         // else : parse lineHeader
         else{
            //vertex of front projection
            if ( strcmp( lineHeader, "fv" ) == 0 ){
                float x,y;
                fscanf(file, "%f %f\n", &x, &y);
                Vertex2d v(x,y);
                front_vertices.addVertex(v);
            }
            //vertex of top projection
            else if ( strcmp( lineHeader, "tv" ) == 0 ){
                float x,y;
                fscanf(file, "%f %f\n", &x, &y);
                Vertex2d v(x,y);
                top_vertices.addVertex(v);
            }
            //vertex of side projection
            else if ( strcmp( lineHeader, "sv" ) == 0 ){
                float x,y;
                fscanf(file, "%f %f\n", &x, &y);
                Vertex2d v(x,y);
                side_vertices.addVertex(v);
            }
            //edge of front projection
            else if ( strcmp( lineHeader, "fe" ) == 0 ){
                int x,y;
                fscanf(file, "%d %d\n", &x, &y);

                Edge2d e(front_vertices.V[x], front_vertices.V[y]);
                front_edges.addEdge(e);
            }
            //edge of top projection
            else if ( strcmp( lineHeader, "te" ) == 0 ){
                int x,y;
                fscanf(file, "%d %d\n", &x, &y);

                Edge2d e(top_vertices.V[x], top_vertices.V[y]);
                top_edges.addEdge(e);
            }
            //edge of side projection
            else if ( strcmp( lineHeader, "se" ) == 0 ){
                int x,y;
                fscanf(file, "%d %d\n", &x, &y);

                Edge2d e(side_vertices.V[x], side_vertices.V[y]);
                side_edges.addEdge(e);
            }
         }

     }


     Projection2d front_projection(front_vertices, front_edges);

     Projection2d top_projection(top_vertices, top_edges);

     Projection2d side_projection(side_vertices, side_edges);



 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // (front_projection.V).print_Vertex2d_List();

    // (front_projection.E).print_Edge2d_List();

    // (top_projection.V).print_Vertex2d_List();

    // (top_projection.E).print_Edge2d_List();

    // (side_projection.V).print_Vertex2d_List();

    // (side_projection.E).print_Edge2d_List();

    Projection projections(front_projection, top_projection, side_projection);

    Solid3d solid1(projections);

    // solid1.V.print_Vertex3d_List();

    // solid1.E.print_Edge3d_List();
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap));

/////////////////////////////////////////////////////
    for(int i=0;i<((solid1.E).E).size();i++){
        float x1 =100*((((solid1.E).E)[i]).x).x;
        float y1 =100*((((solid1.E).E)[i]).x).y;
        float z1 =100*((((solid1.E).E)[i]).x).z;
        float x2 =100*((((solid1.E).E)[i]).y).x;
        float y2 =100*((((solid1.E).E)[i]).y).y;
        float z2 =100*((((solid1.E).E)[i]).y).z;

        float ax1 = ((x1-z1)*sqrt(3))/sqrt(2);
        float ay1 = (x1+ (2*y1)+ z1)/sqrt(6);
        float az1 = (x1-y1+z1)/sqrt(3);

        float ax2 = ((x2-z2)*sqrt(3))/sqrt(2);
        float ay2 = (x2+ (2*y2)+ z2)/sqrt(6);
        float az2 = (x2-y2+z2)/sqrt(3);

        Vertex2d v1(ax1, ay1);
        Vertex2d v2(ax2, ay2);
        Edge2d temp(v1,v2);
        p.drawLine(ax1,ay1 ,ax2 ,ay2);
        //ex.addEdge(temp);
    }

 //   	p.drawLine(700,0,-700,0);
 //   	p.drawLine(0,600,0,-600);
 //     p.drawLine(0,0,0,5);
 //   	p.drawLine(0,0,0,-5);
//      p.drawText(-100,25,"Side view");
//     p.drawText(100,100,"Isometric View");
    p.end(); // Don't forget this line!
    ui->label->setPicture(pi);
    ui->label->setScaledContents(true);
//  l.setPicture(pi);
//  l.show();

}


