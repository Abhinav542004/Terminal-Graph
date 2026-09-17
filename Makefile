CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

run: main
	./main

clean:
	rm -f main