#MakeFile
CXX = g++
CFLAGS = Wall
vpath src
vpath include 

main: main.o Edge2d_List.o Edge3d_List.o HiddenLines.o Projection2d.o Solid3d.o Surface3d_List.o Vertex2d_List.o Vertex3d_List.o Face3d_List.o
	$(CXX) $(CXXFLAGS) -o main main.o Edge2d_List.o Edge3d_List.o HiddenLines.o Projection2d.o Solid3d.o Surface3d_List.o Vertex2d_List.o Vertex3d_List.o Face3d_List.o 

main.o: src/main.cpp include/Edge2d_List.h include/Edge3d_List.h include/HiddenLines.h include/Projection2d.h include/Solid3d.h include/Surface3d_List.h include/Vertex2d_List.h include/Vertex3d_List.h 
	$(CXX) $(CXXFLAGS) -c src/main.cpp

Edge2d_List.o: src/Edge2d_List.cpp include/Edge2d_List.h
	$(CXX) $(CXXFLAGS) -c src/Edge2d_List.cpp	

Edge3d_List.o: src/Edge3d_List.cpp include/Edge3d_List.h
	$(CXX) $(CXXFLAGS) -c src/Edge3d_List.cpp	

HiddenLines.o: src/HiddenLines.cpp include/HiddenLines.h
	$(CXX) $(CXXFLAGS) -c src/HiddenLines.cpp	

Projection2d.o: src/Projection2d.cpp include/Projection2d.h
	$(CXX) $(CXXFLAGS) -c src/Projection2d.cpp	

Solid3d.o: src/Solid3d.cpp include/Solid3d.h 
	$(CXX) $(CXXFLAGS) -c src/Solid3d.cpp	

Surface3d_List.o: src/Surface3d_List.cpp include/Surface3d_List.h
	$(CXX) $(CXXFLAGS) -c src/Surface3d_List.cpp	

Vertex2d_List.o: src/Vertex2d_List.cpp include/Vertex2d_List.h
	$(CXX) $(CXXFLAGS) -c src/Vertex2d_List.cpp	

Vertex3d_List.o: src/Vertex3d_List.cpp include/Vertex3d_List.h	
	$(CXX) $(CXXFLAGS) -c src/Vertex3d_List.cpp	

Face3d_List.o: src/Face3d_List.cpp include/Face3d_List.h	
	$(CXX) $(CXXFLAGS) -c src/Face3d_List.cpp



clean: 
	$(RM) main *.o *~
