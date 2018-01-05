#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <float.h>
#include <limits.h>

using namespace std;

int main (const int argc, const char* const argv[]) {
	

	if (argc == 1) 
	{ 
		cerr << "Unable to compute statistics over data set because there is no arguments." << endl; 
		return 1;
	}

	int numFloats = argc-1; 
	//find minimum 
	//output number of floating points number
	// int i = 1;
	float min = atof(argv[1]);
	float max = atof(argv[1]);
	float sum = max;

	for (int i = 2; i < argc; ++i) { 
		float value = atof(argv[i]); //find minimum 
		if ( value < min) min = value; 
		if ( value > max) max = value;
		sum += value;  
	}   //end of while ] 

	cout << "Number of floating-point numbers: " << argc - 1 << endl;

	cout << "Minimum floating-point number: " << min << endl;

	float ave; 
	ave = sum / (argc - 1);

	cout << "Average floating-point number: " << ave << endl; 

	cout << "Maximum floating-point number: " << max << endl; 

	return 0; 
}