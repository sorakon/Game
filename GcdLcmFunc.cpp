#include <iostream>
#include <stdlib.h>

using namespace std; 

int greatestCommonDenominator(const int a, const int b){ //10 5 

	int aCopy = a; //10 
	int bCopy = b; //5
	if (a>b) {
		aCopy = b; //5
		bCopy = a; //10
	}
	while (bCopy != 0 ){
		int quo = bCopy; //quo = 10 5
		bCopy = aCopy % bCopy; //10 = 5/10 = 0 '5 1
		aCopy = quo; //acopy=10  5
	}
	int gcd=aCopy;
	return gcd; 
}

int leastCommonMultiple(const int a, const int b){
	int aCopy = a;
	int bCopy = b; 
	int gcd; 
	int lcm = (aCopy/gcd)*bCopy; 
	return lcm;
}

// int main(const int argc, const char* const argv[])
// {	
// 	if (argc < 3) {
// 	// cerr << "Error: Unable to compute GCD and/or LCM because you have to input two integers." << endl; 
// 	return -1; 
// 	}

// 	if (argc > 3) {
// 	// cerr<< "Warning: Entered more than two integers, additional ones ignored." << endl; 
// 	return -1;
// 	}

	

// 	int a = atoi(argv[1]);
// 	int b = atoi(argv[2]); 
// 	int gcd = greatestCommonDenominator(a,b);
// 	int lcm = leastCommonMultiple(a,b); 

// 	if (a <= 0 || b <= 0) {
// 	// cerr<<"Error: Unable to compute GCD and/or LCM because of invalid input."<<endl;
// 	return -1;
// 	}


// 	// gcd = a;
// 	// lcm = (aCopy/gcd)*bCopy; 


// 	cout << "GCD(" << a << ", " << b << ") = " << gcd <<endl; 
// 	cout << "LCM(" << a << ", " << b << ") = " << lcm <<endl; 
// 	return 0;
// }
