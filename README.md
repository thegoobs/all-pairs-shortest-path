# Dijkstra's Algorithm and Floyd-Warshall Algorithm Time Analysis Program
#### Written by Guthrie Schoolar

### Description
This is a term project for the University of North Texas College of Engineering Algorithms Course (CSCE 4110).
Written in C++, this program runs a cost matrix for a complete directed graph through an implementation of Dijkstra's and Floyd-Warshall Algorithm for the all-pairs shortest path problem.
Both algorithms run in O(n^3) time, but Dijkstra's is greedy and Floyd-Warshall is a classical dynamic programming algorithm.

### Included Files
  - alg_script.sh
  - main.cpp
  - time_analysis.cpp
  - graph.cpp
  - dijkstras.cpp
  - floydwarshall.cpp

### Usage
Run `./alg_script.sh` in a LINUX terminal. There are multiple different use cases that can be used:

  - `./alg_script.sh` will generate a single randomly generated cost_matrix, and runs it through both algorithms. The output matrices will be written to `dijkstras_output.txt` and `floyd_output.txt`, respectively.
  - `./alg_script.sh [your_file_here].txt` will read in the TEXT file of your choice that stores a cost matrix, and runs it through both algorithms. The output matrices will be written to `dijkstras_output.txt` and `floyd_output.txt`, respectively.
    * The text file must hold a complete, directed graph with all positive edge values.
    * The cost matrix must be delimited by spaces for each entry, and each row be separated by newlines.
    * The cross section of the cost matrix (where column == row) must equal 0.
  - Optional: `./alg_script.sh -t` will run 30 randomly generated graphs through the algorithms and write the size and execution time to `time_output.txt`.

#### Example Cost Matrix File
	0 1 2 3 4 5
	1 0 2 3 4 5
	1 2 0 3 4 5
	1 2 3 0 5 6
	1 2 3 4 0 6
	1 2 3 4 5 0

###Procedure
  1. Open Terminal at repository
  2. run `alg_script.sh` based on diffferent use cases in *usage* section above.
  3. View output graphs in the designated output files