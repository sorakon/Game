//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <limits.h> 

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
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int range(const int dataset[], const int size);
int mode(const int dataset[], const int size, int mode[]);
void selection(int dataset[], int size);
bool sort(int dataset[], const int size);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  Return -1 if there there are any problems with the dataset.
//

int range(const int dataset[], const int size){
  if (size<=0){ //return -1 if cannot compute mode
  return -1;
  }
  int min = INT_MAX; 
  int max = INT_MIN;
  int range; 
  for (int i =0; i < size; i++){
    if (dataset[i]<min)
    min = dataset[i];
    if (dataset[i]>max)
    max = dataset[i];
  }
  range = max - min; 
  if (range < 0) {
    return -1; 
  }
  return range; 
}

int mode(const int dataset[], const int size, int mode[]){
  if (size<=0){ //return -1 if cannot compute mode
    return -1;
  }

  int dataset_copy[size];//make a copy of dataset

  for (int i = 0; i<=size-1; i++)
  {
    dataset_copy[i]=dataset[i];
  }

  sort(dataset_copy,size);
  int count = 1;
  int max = 1;
  int num = 1;
  for (int i = 0; i<size-1; i++){
     count = 1; //reset counter to 1 everytime when it excutes the while loop
    while (dataset_copy[i] == dataset_copy[i+1]){
      count ++;
      i++;
    }
    if (count == max){ 
      mode[num] = dataset_copy[i];
      num ++;
      if (i == size-2 && max == 1){
        mode[num - 1] = dataset_copy[i+1];
      }
    }
    else if (count > max){
      max = count;
      num = 1; // reset number of modes to 1 if the other number appears more than the previous mode
      mode[0] = dataset_copy[i];
    }
  }
  return num; 
}

void selection(int dataset[], int size){
  int max= 0; 
  int temp = 0;
  for (int i = max; i <= size-1; i++) {
      if ( dataset[i] > dataset[max] ) {
          max = i;
      }
  }
  temp = dataset[size-1];
  dataset[size-1] = dataset[max];
  dataset[max] = temp;
  if ( size > 1 ) {
      selection (dataset, --size);
  }
}

bool sort(int dataset[], const int size){
  if (size <=0){
    return false; 
  } else {
    selection(dataset,size);
    return true;
  }
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
  int data[] = {1,2,3,4,5,6,6};
  int size = 6;
  //change this to however many modes you expect to find
  int modedataset[100]={0};
  int rng = range(data, size);
  int modes = mode(data, size, modedataset);
  cout << "range: " << rng << " number of Modes: " << modes << " Modes are this: ";
  for(int i = 0; i<modes;i++){
  	cout<< modedataset[i];
  	if(i<modes-1){
  		cout << ", ";
  	}
  }
  cout<<endl;
  return 0;
}

#endif
