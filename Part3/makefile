all: tdBH

tdBH: testDriver_BH.o BinaryHeap.h Event.o EmptyDataCollectionException.o
	g++ -o tdBH -Wall testDriver_BH.o Event.o EmptyDataCollectionException.o
	
testDriver_BH.o: testDriver_BH.cpp 
	g++ -c -Wall testDriver_BH.cpp
	
Event.o: Event.cpp Event.h
	g++ -c -Wall Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h 
	g++ -c -Wall EmptyDataCollectionException.cpp

clean:	
	rm -f tdBH *.o

