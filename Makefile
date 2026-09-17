CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

lib: generate.cpp
	$(CXX) $(CXXFLAGS) -c generate.cpp -o generate.o

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp generate.o -o main

run: main lib
	./main

clean:
	rm -f main generate.o