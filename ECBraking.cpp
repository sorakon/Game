#include <iostream>
#include <stdlib.h> 
#include <math.h> 
#include <float.h>
#include <assert.h>

using namespace std;

int main (const int argc, const char* const argv[]) {
	double vi; 
	double d; 
	double a; 
	double t;
	double vf; // velocity, distance, maximum deceleration
	double aMax;
	
	if (argc < 4) {
		cerr<<"Error: Insufficient arguments; expecting three arguments."<<endl;
		return 1;
	} else if (argc > 4) {
		cerr<<"Warning: Expecting three command-line arguments; received more; ignoring extraneous arguments."<<endl;
		// return 1;
	}

	aMax = atof(argv[3]); 
	vi = atof(argv[1]);
	d = atof(argv[2]);

	assert (aMax >= 0);

	if (d == 0) {
		cout << "Impossible to avoid collision since distance equals to zero." << endl;
		return 0;
	}

	if (vi * d < 0 || vi == 0) {
		cout << "There is no possibility of collision because the car cannot reach the obstacle" << endl;
		return 0;
	}

	double posD = d >= 0? d: -d;
	a = ((vi * vi) / (2 * posD));
	

	// if the maximum braking speed is 10, and you need 15 to stop, then it is not good
	// so you want aMax to be greater than a?
	if (a < aMax) { // or <=?
		double posVi = vi;
		if (vi < 0) {
			posVi = -vi;
		}
		t = posVi / a;
		cout << "Initial velocity: " << vi << "m/s" << endl; 
		cout << "Distance to obstacle: " << d << "m/s" << endl; 
		cout << "Minimum deceleration: " << a << "m/s/s" << endl; 
		cout << "Maximum stopping time: " << t << "s" << endl; 
	} else {
		vf = sqrt((vi * vi) - (2 * aMax * posD));
		if (d < 0) vf = - vf;
		t = (vf - vi) / aMax;
		if (t < 0) t = -t;
		cout << "Crash will occur in " << t << " seconds at velocity " << vf << " m/s" << "; deploying airbags." << endl; 
	}

	// vf = ((vi * vi) / (2* aMax * d));

	return 0; 

}
