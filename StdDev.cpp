#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <float.h>

using namespace std; 

int main(const int argc, const char* const argv[]) {
	
	if (argc == 1) 
	{ 
		cerr << "Error: Unable to compute statistics over data set because there is no arguments." << endl; 
		return 1;
	}

	int numFloats = argc-1; 
	//find minimum 
	//output number of floating points number
	// int i = 1;
	float min = atof(argv[1]);
	float max = atof(argv[1]);
	float sum = 0;
	float value = 0; 
	float ave; 
	float psd = 0; 
	float ssd = 0; 
	float var = 0; 
	float num = argc-1; 
	int k; 
	float val[k];

	for(int k=0; k<argc-1; k++){
            val[k]=atof(argv[k+1]);
            sum += val[k];
        }

	for (int i = 1; i < argc; ++i) { 
		value = atof(argv[i]); 
		if ( value < min) min = value; 
		if ( value > max) max = value; 
	}   

	ave = sum /numFloats;

	cout<<"Number of floating-point numbers: "<< numFloats <<endl;
	cout<<"Minimum floating-point number: "<<min<<endl;
	cout<<"Average floating-point number: "<<ave<<endl;
	cout<<"Maximum floating-point number: "<<max<<endl;

	for (int i = 1; i < numFloats; ++i) {
	var += (val[k] - ave) * (val[k] - ave);
	}

	ssd = sqrt((1/num) * var); 
	psd = sqrt((1/(num-1) * var)); 

	cout<<"Population standard deviation: ";
	if (argc==2)
	cout << "infinity" << endl;
	else cout << psd << endl; 

	cout<<"Sample standard deviation: "<<ssd<<endl;
	return 0; 
}
