testProg: main.o myTree.o
	g++ -o testProg myTree.o main.o -std=c++11
	
myTree.o: myTree.cpp myTree.h
	g++ -c myTree.cpp -std=c++11
	
main.o: main.cpp myTree.o
	g++ -c main.cpp -std=c++11
	
clean:
	rm testProg *.o