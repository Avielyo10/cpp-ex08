CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all:Board.o square.o compileMain 
	
Board.o: 
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o
square.o:
	$(CXX) $(CXXFLAGS) -c square.cpp -o square.o
compileMain:
	$(CXX) $(CXXFLAGS) main.cpp *.o

clean:
	rm *.o a.out *.ppm
