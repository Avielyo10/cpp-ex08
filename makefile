CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all:Board.o square.o compileMain 

test:Board.o square.o compileTest runTest
	
Board.o: 
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

square.o:
	$(CXX) $(CXXFLAGS) -c square.cpp -o square.o

compileMain:
	$(CXX) $(CXXFLAGS) main.cpp *.o

compileTest:
	$(CXX) $(CXXFLAGS) test.cpp *.o

runTest:
	./a.out < board3.txt
	./a.out < board6.txt
	rm *.o a.out 

clean:
	rm *.ppm
