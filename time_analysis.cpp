#include "header.h"

#define NUM_ITER 30

using namespace std;


void write_to_file(float* arr_d, float* arr_f, int* arr_size) {
	//open file with ostream and get a backup of the cout buffer
	ofstream fp("time_output.txt", ofstream::out);
	streambuf* backup = cout.rdbuf();

	//if the file is opened
	if (fp.is_open()) {
		//change cout to write directly to file
		cout.rdbuf(fp.rdbuf());
		//print graph now writes to file_name
		cout << "SIZE:\tDIJKSTRA'S:\tFLOYD:" << endl <<
				"-----\t-----------\t------" << endl;
		for (int i = 0; i < NUM_ITER; i++) {
			cout << arr_size[i] << "\t\t" << arr_d[i] << "\t\t" << arr_f[i] << endl;
		}
	}

	cout.rdbuf(backup); //remember to put cout back!
	fp.close();

	return;
}

int main() {
	//initialize clock arrays
	clock_t t_d;
	clock_t t_f;

	float f_d[NUM_ITER];
	float f_f[NUM_ITER];
	int arr_size[NUM_ITER];

	//random seed
	srand(time(NULL));
	//random size
	int size;

	for (int i = 0; i < NUM_ITER; i++) {
		size = 50 + (rand() % (1000 - 50));
		cout << "Graph: " << i << "\tSize: " << size << endl;
		cost_matrix g = generate_graph(size);

		// run dijkstra's
		t_d = clock();
		dijkstras(g);
		t_d = clock() - t_d;

		//run floyd
		t_f = clock();
		floydwarshall(g);
		t_f = clock() - t_f;

		f_d[i] = time_in_mil(t_d);
		f_f[i] = time_in_mil(t_f);
		arr_size[i] = size;
	}

	write_to_file(f_d, f_f, arr_size);
	return 0;
}