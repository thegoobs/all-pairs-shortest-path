#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

#include "graph.cpp"

int main(int argc, char* argv[]) {
	cost_matrix g = generate_graph(10, 10);
	// print_graph(g);

	cost_matrix	g2 = read_graph_from_file("example.txt");
	print_graph(g2);
}