using namespace std;

cost_matrix dijkstras(cost_matrix);

cost_matrix dijkstras(cost_matrix cm) {
	//initialize cost matrix to store all pairs shortest path values
	cost_matrix result = generate_graph(cm.size(), cm.size(), false);

	//initialize array to store visited nodes
	//if a node is visited, visited_node[node] = true
	bool visited_nodes[cm.size()];
	for (int i = 0; i < cm.size(); i++) {
		visited_nodes[i] = false;
	}

	//initialize an array that holds the distance from visited nodes
	//if array cannot be visited (no edge connects) then distance = -1
	int distance[cm.size()];
	int start, end;
	for (int i = 0; i < cm.size(); i++) {
		for (int j = 0; j < cm.size(); j++) {
			start = i;
			end = j;

			// DIJKSTRA'S FOR PAIR STARTS HERE
			//initialize algorithm for this pair start, end
			visited_nodes[i] = true; //visit start node

			//loop until end node is visited
			while (!visited_nodes[end]) {
				visited_nodes[end] = true;
			}

			//DIJKSTRA'S FOR PAIR ENDS HERE
			//done with dijkstra's for this pair, move on
			result[start][end] = 1;
		}
	}


	//finally, return the cost matrix of all shortest paths
	return result;
}