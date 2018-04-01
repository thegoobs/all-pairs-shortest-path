using namespace std;

cost_matrix floydwarshall(cost_matrix);

cost_matrix floydwarshall(cost_matrix c) {
	t = clock();
	cost_matrix A = c; //generate matrix to return, starts as cost matrix
	for (int k = 0; k < c.size(); k++) {
		for (int i = 0; i < c.size(); i++) {
			for (int j = 0; j < c.size(); j++) {
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
			}
		}
	}

	t = clock() - t;
	return A;
}