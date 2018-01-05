#include <iostream> 
#include <math.h>
#include <stdlib.h>

using namespace std; 

int main(const int argc, const char* const argv[]) 

{ 
	cout << "N: " << argv[1] << endl;

	cout << "S: " << argv[2] << endl;

	int n = atoi(argv[1]);
	int s = atoi(argv[2]);

	int a= n << s;
	int b = n >> s;
	int c = n * (pow(2,s));
	int d = n / (pow(2,s));
	cout << "Left-shift of N by S bits is: " << a << endl; 
	cout << "Right-shift of N by S bits is: " << b << endl; 
	cout << "The equivalent math operation of left-shift N by S bits is: \"N * (2^S)\"" << endl << "And the result of that operation is: " << c << endl;
	cout << "The equivalent math operation of right-shift N by S bits is: \"N / (2^S)\"" << endl << "And the result of that operation is: " << d << endl;

	return(0); 
}