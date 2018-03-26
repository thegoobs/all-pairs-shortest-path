typedef vector<vector <int> > cost_matrix; //nifty way to not type vector so many times

cost_matrix generate_graph(int rows = 1, int columns = 1) {
	cost_matrix g(columns);

	for (int i = 0; i < rows; i++) {
		g[i] = vector<int>(columns);
		for (int j = 0; j < columns; j++) {
			g[i][j] = 1;
		}
	}
	return g;
}

void print_graph(cost_matrix graph) {
	//get dimensions
	int rows = graph.size();
	int columns = graph[0].size();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return;
}

void write_graph_to_file(string file_name, cost_matrix graph) {
	//open file with ostream and get a backup of the cout buffer
	ofstream fp(file_name, ios::out);
	streambuf* backup = cout.rdbuf();

	//if the file is opened
	if (fp.is_open()) {
		//change cout to write directly to file
		cout.rdbuf(fp.rdbuf());
		//print graph now writes to file_name
		print_graph(graph);
	}

	cout.rdbuf(backup); //remember to put cout back!
	fp.close();

	return;
}

cost_matrix read_graph_from_file(string file_name) {
	cost_matrix graph = generate_graph();
	string s;
	//open file for reading and get stream buffer
	ifstream fp(file_name, ios::in);
	streambuf* backup = cin.rdbuf();
	int i = 0, j = 0;

	if (fp.is_open()) {
		cin.rdbuf(fp.rdbuf());

		while (getline(cin, s)) {
			vector<int> row;
			stringstream ss(s);

			graph.push_back(vector<int>(1));

			int value;
			while (ss >> value) {
				graph[i].push_back(value);
			}
			i++;
		}
	}

	cin.rdbuf(backup);
	fp.close();
	return graph;
}