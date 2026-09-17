#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "generate.h"

using namespace std;

int main()
{
    ifstream input("example.va");
    fstream output("example.av");

    if (!input.is_open()) {
        cout << "Error opening example.va" << endl;
        return 1;
    }

    if (!output.is_open()) {
        cout << "Error creating example.av" << endl;
        return 1;
    }

    string content;
    string line;

    while (getline(input, line)) {
        content += line;
    }

    size_t start = content.find('[');
    size_t end = content.find(']');

    if (start == string::npos || end == string::npos || start >= end) {
        cout << "Invalid format" << endl;
        return 1;
    }

    string numbers = content.substr(start + 1, end - start - 1);

    for (char &c : numbers) {
        if (c == ',')
            c = ' ';
    }

    vector<int> bar_graph;
    stringstream ss(numbers);

    int value;

    while (ss >> value) {
        bar_graph.push_back(value);
    }

    // Pass vector and output file to generate_graph()
    generate_graph(bar_graph, output);

    input.close();
    output.close();

    return 0;
}