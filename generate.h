#ifndef GENERATE_H
#define GENERATE_H

void generate_graph();
#include <vector>
#include <fstream>
void generate_graph(const std::vector<int>& values, std::ofstream& output);
#endif

//it will take vector int and it will take file pointe where it needs to print bargraph