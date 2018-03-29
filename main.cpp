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
	//seed randomizer
	srand(time(NULL));
	int size = 1 + rand() % 20;

	print_graph(dijkstras(generate_graph(size, size)));
}