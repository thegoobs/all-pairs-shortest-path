#!/bin/bash

#first parameter: single random cost matrix
if [[ $1 == "" ]]; then
	g++ main.cpp -std=c++11 -o random_test.exe
	./random_test.exe
elif [[ $1 == "-t" ]]; then
	g++ time_analysis.cpp -std=c++11 -o time_analysis.exe
	./time_analysis.exe
else
	g++ main.cpp -std=c++11 -o file_test.exe
	./file_test.exe $1
fi

rm *.exe