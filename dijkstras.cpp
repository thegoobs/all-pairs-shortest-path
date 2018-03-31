using namespace std;

cost_matrix dijkstras(cost_matrix);

//checks whether or not dijkstras is done
inline bool all_visited(bool* visited_nodes) {
	for (int i = 0; i < sizeof(visited_nodes) / sizeof(int); i++) {
		if (!visited_nodes[i]) {
			return false;
		}
	}

	return true;
}

inline int find_minimum(int* distance, bool* visited) {
	int min = -1;
	int min_index = -1;
	for (int i = 0; i < sizeof(distance) / sizeof(int); i++) {
		if ((min > distance[i] || min == -1) && visited[i] == false) {
			min = distance[i];
			min_index = i;
		}
	}

	return min_index;
}

//function that puts array into vector given the size of the array
inline vector<int> push_result(int* result_array, int size) {
	vector<int> resulting_vector;
	for (int i = 0; i < size; i++) {
		resulting_vector.push_back(result_array[i]);
	}

	return resulting_vector;
}

cost_matrix dijkstras(cost_matrix cm) {
	//initialize cost matrix to store all pairs shortest path values
	cost_matrix result = generate_graph(cm.size(), cm.size(), false);

	//initialize array to store visited nodes
	//if a node is visited, visited_node[node] = true
	bool visited_nodes[cm.size()];

	//initialize an array that holds the distance from visited nodes
	//if array cannot be visited (no edge connects) then distance = -1
	int distance[cm.size()];
	int start, end, minimum;
	for (int i = 0; i < cm.size(); i++) {
		start = i; //start node


		// DIJKSTRA'S FOR PAIR STARTS HERE
		//initialize algorithm for this pair start
		for (int i = 0; i < cm.size(); i++) {
			visited_nodes[i] = false;
			distance[i] = cm[start][i];
		}

		visited_nodes[start] = true; //visit start node
		distance[i] = 0; //can't go to self

		//loop until end node is visited
		while (!all_visited(visited_nodes)) {
			minimum = find_minimum(distance, visited_nodes);
			visited_nodes[minimum] = true;

			//
			for (int i = 0; i < cm.size(); i++) {
				if (visited_nodes[i] == false && distance[i] > distance[minimum] + cm[minimum][i]) {
					distance[i] = distance[minimum] + cm[minimum][i];
				}
			}
		}

		//DIJKSTRA'S FOR PAIR ENDS HERE
		//done with dijkstra's for this pair, move on
		result[start] = push_result(distance, cm.size());
	}


	//finally, return the cost matrix of all shortest paths
	return result;
}