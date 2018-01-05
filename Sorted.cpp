//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <iostream> 
#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// #defines, enum, and function declarations; do not remove
//

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself
#define NaN std::numeric_limits<float>::quiet_NaN() // (comes from <limits>)

enum sortType { ASCENDING, DESCENDING, UNKNOWN, UNSORTED };

bool isSorted(const float data[], const int currentDataItem, const sortType typeOfSort);
bool sorted(const float data[]);

//////////////////////////////////////////////////////////////
//
// Your code here ...
// 
//

bool isSorted(const float data[], const int currentDataItem, const sortType typeOfSort) {
   if (data[currentDataItem+1] != data[currentDataItem+1]){
    return true;
  }
  // NaN= does not equal to itself,  will be true only if f is NaN, identify if it's the end of array. 

  switch(typeOfSort){
  case UNKNOWN:
   if (data[currentDataItem] < data[currentDataItem+1]){
     return isSorted(data, currentDataItem+1, ASCENDING);
   }
   if (data[currentDataItem] == data[currentDataItem+1]){
     return isSorted(data, currentDataItem+1, UNKNOWN);
   }
   if (data[currentDataItem] > data[currentDataItem+1]){
     return isSorted(data, currentDataItem+1, DESCENDING);
   }
  break;

  case ASCENDING:
    if (data[currentDataItem] <= data[currentDataItem+1]){
      return isSorted(data, currentDataItem+1, ASCENDING);
    }

    else{
      return false;
    }

  case DESCENDING:
    if (data[currentDataItem] >= data[currentDataItem+1]){
      return isSorted(data, currentDataItem+1, DESCENDING);
    }

    else{
      return false;
    }

  case UNSORTED:
    return false;
  }
}



bool sorted(const float data[]) {
  // ...
	if (data == NULL){
		return false;} 
		else {
	return isSorted(data,0,UNKNOWN);}
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

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  float data[] = {1, 2, 4, 5, 9, NaN};

  if (sorted(data))
    cout << "Data is sorted" << endl;
  else
    cout << "Data is not sorted" << endl;
  
  return 0;
}

#endif

