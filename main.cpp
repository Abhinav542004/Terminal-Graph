#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream input("example.va");
    ofstream output("example.av");

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

    // Read the complete .va file
    while (getline(input, line)) {
        content += line;
    }

    // Find [ and ]
    size_t start = content.find('[');
    size_t end = content.find(']');

    if (start == string::npos || end == string::npos || start >= end) {
        cout << "Invalid bar_graph format" << endl;
        return 1;
    }

    // Extract numbers between [ and ]
    string numbers = content.substr(start + 1, end - start - 1);

    // Remove commas
    for (char &c : numbers) {
        if (c == ',') {
            c = ' ';
        }
    }

    // Write to example.av
    output << numbers;

    input.close();
    output.close();

    cout << "Successfully generated example.av" << endl;

    return 0;
}