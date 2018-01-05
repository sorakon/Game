#include <iostream>
#include <stdlib.h>
using namespace std;

// powerOf returns a^b (a to the power of b)
double powerOf (double a, int b) {
	double aCopy = a;
	for (int i = 2; i<=b; ++i){
		a *= aCopy; 
	}
	return a; 
}

// absVal returns the absolute value of a
double absVal (double a) {
	return (a >= 0? a: -a);
} 

int main(int argc, char *argv[]) {
	if (argv[2] <= 0) {
		cerr << "Error: Unable to compute Nth root because positive integer have to be entered."<<endl;
		return 1; 
	}
	if (argc > 4) {
		cerr<<"Warning: Received more argument than needed, ignore those extra."<<endl;
	}
	if (argc < 4) {
		cerr<<"Error: Unable to compute Nth root because more information needed."<<endl;
		return 1;
	}

	double s = atof(argv[1]);
	int n = atoi(argv[2]);
	double p = atof(argv[3]); 
	double percision = atof(argv[3]);
	double result = s / n;
	double error;

	if (n < 2) {
		cerr<<"Error: Unable to compute Nth root because n is smaller than 2"<<endl;
		return 1;
	}
	if ((n % 2 == 0) && s < 0) {
		cerr<<"Error: Unable to compute Nth root because cannot take even number root of a negative number"<<endl;
		return 1;
	}
	if (p <= 0) {
		cerr << "Error: Unable to compute Nth root because invalid inputs; expecting non-negative precision." << endl;
        return 1;
	}
	if (argc > 4){
        cerr << "Warning: Expecting three-command lines arguments; received "<< argc-1 << "; ignoring extraneous arguments." << endl;
        return 1; 
	}
	if (s ==0){
    	cout << "root (" << s << ", "<< n << ") = "<< 0 << endl << "(with precision " << 0 <<")" << endl;
    	return 0;
    }
    if (n>= 2) {
	double sCopy = s;
	int nCopy = n;
	
	while ((error = absVal((s - powerOf(result, n)) / s)) > percision) {
		result = ((double(n) - 1.0) / double(n)) * result + s / (double(n) * (powerOf(result, n - 1)));
		// cout<<"error: "<<error<<" result: "<<result<<endl;
	}

	cout<<"Root ("<<sCopy<<","<<nCopy<<") = "<<result<<endl;
	cout<<"(with precision "<<error<<")"<<endl;
	return 0; }
}


		
