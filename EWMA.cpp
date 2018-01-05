#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <iomanip>
#include <float.h>

using namespace std;

int main (const int argc, const char* const argv[]) {

	if (argc < 4) { 
	cerr << "Error: Insufficient arguments."<< endl; 
	return 1; 
	}

	float sum = 0;
	float alpha;
	float extremLim;
	float ewm;
	float preEwm;
	float max = FLT_MIN; 
	float min = FLT_MAX; 

	alpha = atof(argv[1]);
	extremLim = atoi(argv[2]);
	int count = 0;

	if ( alpha < 0 || alpha > 1) { 
		cerr << "Error: The value of alpha must be between 0 and 1." << endl;
		return 1;  
	} 
	
	cout << "Sample   Value  Minimum EWMA    Maximum" << endl; 

	for (int i = 3; i < argc; ++i) {
		float val = atof(argv[i]);
		if (i == 3) {
			ewm = preEwm = val;
		} else {
			float temp = ewm;
			ewm = val * alpha + preEwm * (1 - alpha);
			preEwm = ewm; 
		}
		min = val;
		max = val;
		for (int j = 0; j < extremLim && i - j >= 3; ++j) {
			float temp = atof(argv[i-j]);
			if (temp > max) max = temp;
			if (temp < min) min = temp; 
		}

		cout<<left; //line up on the left side 
		cout<<setw(6)<<i - 2<<"   "<<setw(5)<<val<<"  "<<setw(7)<<min<<" ";
		cout<<setw(7)<<ewm<<" "<<setw(7)<<max<<endl;
	}
}