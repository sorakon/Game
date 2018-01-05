//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

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

bool stringToInt(const char input[], int& value);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

#include <iostream>
#include <limits.h> 




bool stringToInt(const char input[], int& value) {
  int temp;
  value = 0;

    if (input[0]=='-'||input[0]=='+')
    {
      for (int i=1; input[i] != '\0'; ++i)
      {
        temp = input[i];
        switch (temp)
        {
          case '0' :
          if (value >= INT_MAX/10)
          return false;
          value = value*10 + 0;
          break;

          case '1' :
          if (value >= INT_MAX/10)
          return false;
          value = value*10 + 1;
          break;

          case '2' :
          if (value >= INT_MAX/10)
          return false;
          value = value*10 + 2;
          break;

          case '3' :
          if (value >= INT_MAX/10)
          return false;
          value = value*10 + 3;
          break;

          case '4' :
          if (value >= INT_MAX/10)
          return false;
          value = value*10 + 4;
          break;

          case '5' :
          if (value >= INT_MAX/10)
          return false;
          value = value*10 + 5;
          break;

          case '6' :
          if (value >= INT_MAX/10)
          return false;
          value = value*10 + 6;
          break;

          case '7' :
          if (value >= INT_MAX/10)
          return false;
          value = value*10 + 7;
          break;

          case '8' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 8;
          break;

          case '9' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 9;
          break;

          default :
          return false;
        }

      }
      if (input[0] == '-') {value = -1*value;} 
      else if (input[0] == '+') {value = value;}
      return true;
    }
    else if (input[0]=='0'|| input[0]=='1'|| input[0]=='2'|| input[0]=='3'|| input[0]=='4'|| input[0]=='5'|| input[0]=='6'|| input[0]=='7'|| input[0]=='8'|| input[0]=='9')
    {
      for (int i=0; input[i] != '\0'; ++i)
      {
        temp = input[i];
        switch (temp)
        {
          case '0' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 0;
          break;

          case '1' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 1;
          break;

          case '2' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 2;
          break;

          case '3' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 3;
          break;

          case '4' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 4;
          break;

          case '5' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 5;
          break;

          case '6' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 6;
          break;

          case '7' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 7;
          break;

          case '8' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 8;
          break;

          case '9' :
          if (value >= INT_MAX/10 )
          return false;
          value = value*10 + 9;
          break;

          default :
          return false;
        }
      }
      return true;
    }
    else
      return false;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

// if (input[0]=='+' || input[0]=='-'|| input[0]==' ' || input[0]=='0'|| input[0]=='1'|| 
//     input[0]=='2' || input[0]=='3'|| input[0]=='4'|| input[0]=='5'|| 
//     input[0]=='6' || input[0]=='7'|| input[0]=='8'|| input[0]=='9') {
//   for (int i=2; i<200; i++){
//     if (input[i]!='0'|| input[i]!='1'|| input[i]!='2' || input[i]!='3'|| input[i]!='4'|| input[i]!='5'|| 
//         input[i]!='6' || input[i]!='7'|| input[i]!='8'|| input[i]!='9'){
//         return false; 
//       } else {
//         i++;
//         return true; 
//       }
//       int string = atoi(input); 
//         value = string;
//         return true;
//     }
//         int string = atoi(input); 
//         value = string;
//       }
//       return true;
//     }

  // if (input[0]=='+' || input[0]=='-'|| input[0]==' ' || input[0]=='0'|| input[0]=='1'|| 
  //     input[0]=='2' || input[0]=='3'|| input[0]=='4'|| input[0]=='5'|| 
  //     input[0]=='6' || input[0]=='7'|| input[0]=='8'|| input[0]=='9')
  //   {
  //     int string = atoi(input); 
  //     value = string;
  //     return true;
  //   } 
  //     return false;
  //   }

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  int argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <int>" << endl;
    return -1;
  }

  if (stringToInt(argv[1],argv1)) 
    cout << "argv[1] is an int with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not an int." << endl;
  return 0;
}

#endif
