#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

#include "graph.cpp"
#include "dijkstras.cpp"
#include "floydwarshall.cpp"


inline float time_in_mil(clock_t t) {
	return ((float)t/CLOCKS_PER_SEC) * 1000;
}