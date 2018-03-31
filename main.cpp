#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "graph.cpp"
#include "dijkstras.cpp"

using namespace std;

int main(int argc, char* argv[]) {
	//check if file was written in terminal command
	if (argc == 2) {
		//seed randomizer
		srand(time(NULL));
		int size = 1 + rand() % 20;

		cost_matrix g = read_graph_from_file(argv[1]);
		// print_graph(g);
		cout << endl;
		print_graph(dijkstras(g));
	}

	else {
		cout << "Usage: ./a.out [file_name.txt]\n";
	}
}