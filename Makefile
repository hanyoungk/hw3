CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test heap-test valgrind

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec.o llrec-test.cpp
	$(CXX) $(CXXFLAGS) -o $@ llrec.o llrec-test.cpp

heap-test: heap.o heap-test.cpp
	$(CXX) $(CXXFLAGS) -o $@ heap.o heap-test.cpp

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -o $@ -c heap.cpp

valgrind: llrec-test
	$(VALGRIND) ./llrec-test llrec-test1.in

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 