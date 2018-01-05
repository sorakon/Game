//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...

#include <fstream>
using namespace std;
#include <iostream>

//
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#include <fstream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int histogram(const char filename[], int histogram[10], 
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return -1 if you cannot compute the histogram for any
// reason;
// Return 0 if the histogram is correct and there are no
// rejections;
// Return the number of rejects if there are rejected
// records from the file
//

int histogram(const char filename[], int histogram[10], 
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects) {



  if(histogram==NULL){
    return -1;
  }

  const int maxLineLength = 100;
  char line[maxLineLength];
  int rejectcount = 0;
  int rejectLineNum = 0;
  rejects = new int[100];
  ifstream infile;
  infile.open(filename);
  if (!infile.is_open()){
      return -1;
  }
    
  if(minAcceptableID > maxAcceptableID){
    return -1;
  }
  for(int i=0; i <10 ; i++){
    histogram[i]=0;
  }

  bool done = false;
  int fileLineNumber = 0;
    

  while (!done){
  ++fileLineNumber;
  if (!infile.getline(line, maxLineLength)){
      if (infile.eof()){
          done = true;
      }
      else {
          return -1;
      }
  }
        
  int studentID = 0;
  int k = 0;
  int value = 0;
  int grade = 0;
  int s = 1;
  
  if (!done){
      while (line[k] != ','){
          if (line[k] >= '0' && line[k] <= '9'){
              value = line[k] - '0';
              studentID = studentID*10 + value;
          }
          else if (line[k] != ' ' && line[k] != '\t'){
              return -1;
          }
          k++;
      }
      k++;
      
      while (line[k]){
          if (line[k] >= '0' && line[k] <= '9'){
              value = line[k] - '0';
              grade = grade*10 + value;
          }
          else if (line[k] == '-'){
              s = -1*s;
          }
          else if (line[k] != ' ' && line[k] != '\t'){
              return -1;
          }
          k++;
      }
      grade = grade*s;
      if (studentID < minAcceptableID || studentID > maxAcceptableID || grade < 0 || grade > 100){
          rejects[rejectcount] = fileLineNumber;
          rejectcount++;
          rejectLineNum++;
      }
      else if((grade >=0 )&&(grade <=9)){
        histogram[0]+=1;
      }
      else if((grade >=10 )&&(grade <=19)){
        histogram[1]+=1;
      }
      else if((grade >=20 )&&(grade <=29)){
        histogram[2]+=1;
      }
      else if((grade >=30 )&&(grade <=39)){
        histogram[3]+=1;
      }
      else if((grade >=40 )&&(grade <=49)){
        histogram[4]+=1;
      }
      else if((grade >=50 )&&(grade <=59)){
        histogram[5]+=1;
      }
      else if((grade >=60 )&&(grade <=69)){
        histogram[6]+=1;
      }
      else if((grade >=70 )&&(grade <=79)){
        histogram[7]+=1;
      }
      else if((grade >=80 )&&(grade <=89)){
        histogram[8]+=1;
      }
      else if((grade >=90 )&&(grade <=100)){
        histogram[9]+=1;
      }
  }
}

if (rejectcount > 0){
  return rejectLineNum;
}

return 0;
//close
infile.close();
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
  if (argc < 2) {

  }
  const int numBuckets = 10;
  const int bucketRange = 100/numBuckets;
  int  buckets[numBuckets];
  int* rejectedRecords;
  int retCode = histogram(argv[1], buckets, 22200000, 22299999, rejectedRecords);
  if (retCode < 0) {
      cout << "Unable to compute histogram." << endl;
  }
  else {
    for (int i = 0; i < numBuckets; ++i)
      if (i != numBuckets-1)
  cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)-1) << "]: " << buckets[i] << endl;
      else
  cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)) << "]: " << buckets[i] << endl;
    if (retCode > 0) {
      cout << "Number of rejected records: " << retCode << endl;
      cout << "Rejected records are:";
      for (int i = 0; i < retCode; ++i)
  cout << " " << rejectedRecords[i];
      cout << endl;
      delete[] rejectedRecords;
    }
  }

  return 0;
}

#endif

