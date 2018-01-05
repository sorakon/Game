#include <iostream>
#include <stdlib.h>

using namespace std; 

int main (const int argc, const char* const argv[])
{

	if (argc < 3) {
		cerr << "Error: Unable to compute GCD and/or LCM because you have to input two integers." << endl; 
		return 1; 
	}

	if (argc > 3) {
		cerr<< "Warning: Entered more than two integers, additional ones ignored." << endl; 
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]); 

	if (a <= 0 || b <= 0) {
		cerr<<"Error: Unable to compute GCD and/or LCM because of invalid input."<<endl;
		return 1;
	}


	int aCopy = a;
	int bCopy = b;
	int gcd; 
	int lcm; 
	int quo; 

	if (a>b) {
		aCopy = b;
		bCopy = a; 
	}

	while (b != 0 ){
		quo = b;
		b = a % b; 
		a = quo; 
	}

	gcd = a;
	lcm = (aCopy/gcd)*bCopy; 


	cout << "GCD(" << aCopy << ", " << bCopy << ") = " << gcd <<endl; 
	cout << "LCM(" << aCopy << ", " << bCopy << ") = " << lcm <<endl; 
	return 0;
}
