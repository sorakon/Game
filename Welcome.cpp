#include <iostream>

using namespace std;

int main( const int argc, const char* const argv[])
{
    cout << "Welcome to UW Engineering, " <<argv[1] << "." << endl;
    // add a line of code to output the second command-line argument (argv[2])
    cout << "Your University of Waterloo E-mail address is: " << argv[2] << "@uwaterloo.ca" << endl;
    // add a line of code to output the content of argc	
 	cout << "The value stored in argc is 3" << endl;
    // add a line of code to explain what is stored in argc
 	cout << "The variable \"argc\" contains the number of command line argument given include the name of executable." << endl; 
    return 0;
}


