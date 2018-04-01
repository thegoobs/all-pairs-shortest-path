#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

//global time variable
clock_t t;

#include "graph.cpp"
#include "dijkstras.cpp"
#include "floydwarshall.cpp"

using namespace std;

int main(int argc, char* argv[]) {
	//check if file was written in terminal command
	if (argc == 2) {

		cost_matrix g = read_graph_from_file(argv[1]);
		print_graph(dijkstras(g));
		cout << endl;
		print_graph(floydwarshall(g));
	}

	else {
		cout << "WARNING: No file given, random cost matrix generated\n" <<
				"Usage with file: ./a.out [file_name.txt]\n";
		//seed randomizer
		srand(time(NULL));
		//random size for cost matrix if generated random
		int size = 5;//1 + rand() % 20;

		cost_matrix g_r = generate_graph(size);
		
		print_graph(g_r);

		cout << endl;

		print_graph(dijkstras(g_r));

		cout << endl;

		print_graph(floydwarshall(g_r));
	}
}