typedef vector<vector <int> > cost_matrix;

cost_matrix generate_graph(int rows, int columns) {
	cost_matrix g(columns);

	for (int i = 0; i < rows; i++) {
		g[i] = vector<int>(columns);
		for (int j = 0; j < columns; j++) {
			g[i][j] = i * j;
		}
	}
	return g;
}

void print_graph(cost_matrix graph) {
	int rows = graph.size();
	int columns = graph[0].size();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << graph[i][j] << "\t";
		}
		cout << endl;
	}
}

void write_graph() {

	return;
}

void read_graph() {
	
	return;
}