#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <time.h>
using namespace std;

#include "graph.cpp"

int main(int argc, char* argv[]) {
	srand(time(NULL));
	int size = rand() % 20;

	cost_matrix g = generate_graph(size, size);
	print_graph(g);

	write_graph_to_file("example2.txt", g);

	cout << endl << endl;

	cost_matrix	g2 = read_graph_from_file("example2.txt");
	print_graph(g2);
}