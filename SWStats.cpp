#include <iostream>
#include <stdlib.h>
#include <float.h>

using namespace std;

int main (const int argc, const char* const argv[]) {
	int windowSize = atoi(argv[1]);

	if (windowSize <= 0) {
		cerr<<"Error: Unable to compute statistics over data set because window size is 0"<<endl;
		return 1;
	}
	if (argc<3){
    	cerr << "Error: Unable to compute statistics over data set because of insufficient arguments; expecting two or more command-line arguments." << endl;
    	return 1;
    }
    if (atoi(argv[1])<=0){
    	cerr << "Error: Unable to compute statistics over data set because the size of the windows is not positive number." << endl;
    	return 1;
    }
    if (atoi(argv[1])>argc-2 || atoi(argv[1])==1){
    	cerr << "Warning: the number of input is smaller than the window size." << endl;
    }
	cout<<"Window Size: "<<windowSize<<endl;
	printf ("Sample Value SWMinimum SWAverage SWMaximum\n");
	
	// Stack-like array, no object allowed, so...
	double valArray[windowSize] = {0};
	int curSize = 0;

	for (int i = 2; i < argc; ++i) {
		double val = atof(argv[i]);

		// Behaive as pop
		if (curSize == windowSize) {
			for (int j = 1; j < windowSize; ++j) {
				valArray[j - 1] = valArray[j];
			}
			curSize--;
		}
		curSize++;
		// Perform push
		valArray[curSize - 1] = val;
		
		double max = FLT_MIN;
		double min = FLT_MAX;
		double sum = 0;

		for(int j = 0; j < curSize; ++j) {
			if (valArray[j] > max) max = valArray[j];
			if (valArray[j] < min) min = valArray[j];
			sum += valArray[j];
		}

		cout <<left;
		cout<<i - 1<<"	"<<val<<"	"<<min<<"	"<<(sum / curSize)<<"	"<<max<<endl;
	}
}

			
			
	
