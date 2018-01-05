//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits.h> 

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
  return 3.2*x*x*x - 2.1*x - 23.0;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize
		      ... );
float bisection(const float left, const float right,
		const float precision, const float minIntervalSize);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//
float absolute (float value){
	if (value < 0){
		return value*(-1); 
	} else {
		return value; 
	}
}


float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize,
		      int counter){
 	if ( precision <= 0 || (right-left) <= 0 || minIntervalSize <= 0 || f(right) == f(left) || f(right)*(f(left)) > 0
    || counter > 2333 || f(left) != f(left) || f(right) != f(right)) {
 		return std::numeric_limits<float>::quiet_NaN();
 	}

	float midpoint = (left+right)/2; 
    if (absolute(f(left))<precision) {
    	return left;
    } else if (absolute(f(right))<precision) {
     	return right;
    }else if (absolute(f(midpoint))<=precision||(right-left)<minIntervalSize){
      	return midpoint;
    }

    if ((f(midpoint)*f(left))>0){
      	return bisectionHelper(midpoint, right, precision, minIntervalSize, counter+1);
    } else if ((f(midpoint)*f(right))>0) {
     	return bisectionHelper(left, midpoint, precision, minIntervalSize, counter+1);
    } else {
    	return -1; 
    }
}

float bisection(const float left, const float right,
		const float precision, const float minIntervalSize){
      int counter = 0;
      float result = bisectionHelper(left,right,precision,minIntervalSize,counter);
      return result;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  float left = atof(argv[1]);
  float right = atof(argv[2]);
  float precision = atof(argv[3]); 
  float minIntervalSize = atof(argv[4]); 
  float midpoint = bisection(left, right, precision, minIntervalSize);
  cout << midpoint << endl; 

  return 0;
}

#endif
