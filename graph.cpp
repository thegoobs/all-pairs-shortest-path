#define MAX_VAL 100
using namespace std;

typedef vector<vector <int> > cost_matrix; //nifty way to not type vector so many times
//function prototypes
cost_matrix generate_graph(int, int, bool);
void print_graph(cost_matrix);
void write_graph_to_file(string, cost_matrix);
cost_matrix read_graph_from_file(string);

cost_matrix generate_graph(int rows = 1, int columns = 1, bool random = true) {
	cost_matrix g(rows);

	for (int i = 0; i < rows; i++) {
		g[i] = vector<int>(columns);
		for (int j = 0; j < columns; j++) {
			if (random) {
				g[i][j] = i == j ? 0 : rand() % MAX_VAL + 1;
			}

			else {
				g[i][j] = 0;
			}
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
	ofstream fp(file_name, ofstream::out);
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
	cost_matrix graph;
	string s;
	//open file for reading and get stream buffer
	ifstream fp(file_name, ifstream::in);
	streambuf* backup = cin.rdbuf();
	int i = 0;

	if (fp.is_open()) {
		cin.rdbuf(fp.rdbuf());

		while (getline(cin, s)) {
			stringstream ss(s);

			graph.push_back(vector<int>(0));

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