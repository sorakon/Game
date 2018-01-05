#include <iostream>
#include <stdlib.h>

using namespace std; 

int main(const int argc, const char* const argv[]) 
{ 
	double vi; //initial velocity =vi
	double d; //distance to obstacle =d

	double a; //minimum deceleration = a
	double t; //maximum stopping time = t
	//vf=0

	vi = atof(argv[1]);
	d = atof(argv[2]);

	a = ((vi * vi) / (2*d));
	t = (vi/a); 

	cout << "Initial velocity: " << vi << "m/s" << endl; 

	cout << "Distance to obstacle: " << d << "m/s" << endl; 

	cout << "Minimum deceleration: " << a << "m/s/s" << endl; 

	cout << "Maximum stopping time: " << t << "s" << endl; 

return(0);

}