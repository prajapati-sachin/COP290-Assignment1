#MakeFile
CXX = g++
LFLAGS        = -m64
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES) -Wno-sign-compare
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LIBS          = -L/usr/lib/x86_64-linux-gnu/ -lm -lQtGui
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB

main: main.o Edge2d_List.o Edge3d_List.o HiddenLines.o Projection2d.o Solid3d.o Surface3d_List.o Vertex2d_List.o Vertex3d_List.o Face3d_List.o
	$(CXX) $(LFLAGS) -o main main.o Edge2d_List.o Edge3d_List.o HiddenLines.o Projection2d.o Solid3d.o Surface3d_List.o Vertex2d_List.o Vertex3d_List.o Face3d_List.o $(LIBS)

main.o: src/main.cpp include/Edge2d_List.h include/Edge3d_List.h include/HiddenLines.h include/Projection2d.h include/Solid3d.h include/Surface3d_List.h include/Vertex2d_List.h include/Vertex3d_List.h 
	$(CXX) $(CXXFLAGS) $(INCPATH) -c src/main.cpp

Edge2d_List.o: src/Edge2d_List.cpp include/Edge2d_List.h
	$(CXX) $(CXXFLAGS) $(INCPATH) -c src/Edge2d_List.cpp	

Edge3d_List.o: src/Edge3d_List.cpp include/Edge3d_List.h
	$(CXX) $(CXXFLAGS) $(INCPATH) -c src/Edge3d_List.cpp	

HiddenLines.o: src/HiddenLines.cpp include/HiddenLines.h
	$(CXX) $(CXXFLAGS) $(INCPATH) -c src/HiddenLines.cpp	

Projection2d.o: src/Projection2d.cpp include/Projection2d.h
	$(CXX) $(CXXFLAGS) $(INCPATH) -c src/Projection2d.cpp	

Solid3d.o: src/Solid3d.cpp include/Solid3d.h 
	$(CXX) $(CXXFLAGS) $(INCPATH) -c src/Solid3d.cpp	

Surface3d_List.o: src/Surface3d_List.cpp include/Surface3d_List.h
	$(CXX) $(CXXFLAGS) $(INCPATH) -c src/Surface3d_List.cpp	

Vertex2d_List.o: src/Vertex2d_List.cpp include/Vertex2d_List.h
	$(CXX) $(CXXFLAGS) $(INCPATH) -c src/Vertex2d_List.cpp	

Vertex3d_List.o: src/Vertex3d_List.cpp include/Vertex3d_List.h	
	$(CXX) $(CXXFLAGS) $(INCPATH) -c src/Vertex3d_List.cpp	

Face3d_List.o: src/Face3d_List.cpp include/Face3d_List.h	
	$(CXX) $(CXXFLAGS) $(INCPATH) -c src/Face3d_List.cpp



clean: 
	$(RM) main *.o *~
