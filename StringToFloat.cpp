//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
// You are allowed float.h
#include <float.h>
#include <math.h>
#include <iostream>


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

bool stringToFloat(const char input[], float& value);

//////////////////////////////////////////////////////////////
//
// Your code here ...

bool stringToFloat(const char input[], float& value) {
  // Your code here ...
    int index =0;
    float decimal = 0;
    int count=0;
    int PowerExp =0;
    bool NegativeExp = false;
    bool GotSign = false;
    bool NegativeDet = false;
    int DotIndex=-1;
    int PowerIndex=0;
    int MaxIndex=0;
    float large = FLT_MAX;
    float small = FLT_MIN;

    while (input[index] != '.'){
        index++;

        if (input[index] == 0){
          break;
        }
    }


    for (int i=0; input[i] != '\0'; ++i){
        if (input[i] == '.'){
          DotIndex = i;
        } 
    }

    for (int i=0; input[i] != '\0'; ++i){
        MaxIndex = i;
    }

    for (int i =0;input[i] != '\0'; ++i){
        if (input[i] == 'E' || input[i] == 'e'){
          PowerIndex = i;
        } 
    }



    if (input[0] =='+' || input[0] =='-'){
      for (int i =1; i<index; ++i){
        if (input[1]-'0' == 0){
          value = 0;
          break;
        }
        int digit = input[i] -'0';
        large -= digit*pow(10,(index-1-i));
        small -= digit*pow(10,(index-1-i));
        if (large <0 || small >0){
          return false; 
        }
        if (digit >= 0 && digit <= 9){
          value += digit*pow(10,(index-1-i));
        }
        else{
          return false;
        }
      }
    }

    else{
      for (int i =0; i<index; ++i){
        if (input[0]-'0' == 0){
          value = 0;
          break;
        }
        int digit = input[i]-'0';
        large -= digit*pow(10,(index-1-i));
        small -= digit*pow(10,(index-1-i));
        if (large <0 || small >0){
          return false; 
        }
        if (digit >= 0 && digit <= 9){
          value += digit*pow(10,(index-1-i));
        }
        else{
          return false;
        }
      }
    }

    if (input[index] == '.'){
      while (input[index+1] != 0 && input[index+1] != 'e' && input[index+1] != 'E'){
        int digit = input[index+1]-'0';
        if (digit >= 0 && digit <= 9){
          decimal = decimal*10 + digit;
        }
        else{
          return false;
        }
        count++;
        index++;
      }
    }

    decimal = decimal*pow(10,-1*count);
    if (value < 0 || NegativeDet==true){
      value -= decimal;
    }
    else{
      value += decimal;
    }

    if (input[index+1] == 'e' || input[index+1] == 'E'){
      while (input[index+2] !=0){
        if (input[index+2] == '-' || input[index+2] == '+'){
          GotSign = true;
          if (input[index+2] == '-'){
            NegativeExp = true;
          }
          else{
            NegativeExp = false;
          }
          int digit = input[index+3]-'0';
          if (digit >= 0 && digit <= 9){
            PowerExp = PowerExp*10 + digit;
          }
          else{
            return false;
          }
        }
        else if(GotSign == false){
          int digit = input[index+2]-'0';
          if (digit >= 0 && digit <= 9){
            PowerExp = PowerExp*10 + digit;
          }
          else{
            return false;
          }
        }
        index++;
      }
    }

    if (NegativeExp == true){
      PowerExp *=-1;
    }

    value = value*pow(10,PowerExp);

    if (input[0]== '+') {
    value = value; 
    }
    if (input[0]== '-') {
    value = -1*value;
    }


    return true;
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
  float argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <float>" << endl;
    return -1;
  }

  if (stringToFloat(argv[1],argv1)) 
    cout << "argv[1] is a float with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not a float. argv[1]: " <<argv[1] << endl;
  return 0;
}

#endif
