#include <iostream>
#include <vector>
using namespace std;

#include "graph.cpp"

int main(int argc, char* argv[]) {
	cost_matrix g = generate_graph(10, 10);
	print_graph(g);
}