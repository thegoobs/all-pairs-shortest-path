#include "header.h"
using namespace std;

int main(int argc, char* argv[]) {
	//clock variables for timing algorithms
	clock_t t_d;
	clock_t t_f;

	//check if file was written in terminal command
	if (argc == 2) {
		cost_matrix g = read_graph_from_file(argv[1]);

		cout << "Dijkstra's and Floyd-Warshall algorithms tested on cost matrix file " << argv[1] << endl <<
				"Number of vertices: " << g.size() << endl;

		t_d = clock();
		cost_matrix g_d = dijkstras(g);
		t_d = clock() - t_d;

		cout << "\nTime to complete Dijkstra's: " << time_in_mil(t_d) << " milliseconds" << endl;

		t_f = clock();
		cost_matrix g_f = floydwarshall(g);
		t_f = clock() - t_f;

		cout << "\nTime to complete Floyd-Warshall: " << time_in_mil(t_f) << " milliseconds" << endl;

		//write output to files
		write_graph_to_file("dijkstras_output.txt", g_d);
		write_graph_to_file("floyd_output.txt", g_f);

		cout << "Resulting cost matrices written to 'dijkstras_output.txt' and 'floyd_output.txt'" << endl;
	}

	else {
		//seed randomizer
		srand(time(NULL));

		//random size for cost matrix if generated random
		int size = 50 + rand() % (1000 - 50);

		cout << "Dijkstra's and Floyd-Warshall algorithms tested on a randomly generated cost matrix.\n" <<
				"Number of vertices: " << size << endl;

		cost_matrix g_r = generate_graph(size);

		//time start
		t_d = clock();
		cost_matrix g_d = dijkstras(g_r);
		t_d = clock() - t_d;

		cout << "\nTime to complete Dijkstra's: " << time_in_mil(t_d) << " milliseconds" << endl;

		t_f = clock();
		cost_matrix g_f = floydwarshall(g_r);
		t_f = clock() - t_f;

		cout << "\nTime to complete Floyd-Warshall: " << time_in_mil(t_f) << " milliseconds\n" << endl;

		//write output to files
		write_graph_to_file("dijkstras_output.txt", g_d);
		write_graph_to_file("floyd_output.txt", g_f);

		cout << "\nResulting cost matrices written to 'dijkstras_output.txt' and 'floyd_output.txt'" << endl;
	}
}