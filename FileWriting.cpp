//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <fstream>
using namespace std;
#include <iostream>
#include <float.h>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
//
// struct definitions 
//

// struct Student{
// 	int studentID;
// 	int grade; 
// };
// //student

// struct Dataset{
// 	int numStudents;
// 	Student* students;
// };
// //data

// struct Rejects{
// 	int numRejects;
// 	int* rejects;
// };
// //rejects

// struct Mode{
// 	int numModes;
// 	int* modes;
// };

// struct Statistics{
// 	int   minimum;
// 	float average;
// 	int   maximum;
// 	float popStdDev;
// 	float smplStdDev;
// 	Mode  mode;
// 	int   histogram[10];
// };

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//
int readCSV(const char filename[],const int minAcceptableID, 
				const int maxAcceptableID,Dataset& data, 
				Rejects& rejects);

int computeStatistics(Dataset& data, Statistics& stats);

int writeCSV(const char filename[], const Statistics& stats);

int mode(const int dataset[], const int size, int mode[]);
void selection(int dataset[], int size);
bool sort(int dataset[], const int size);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//
int readCSV(const char filename[],const int minAcceptableID, 
				const int maxAcceptableID,Dataset& data, 
				Rejects& rejects){
	//Your code here ...
	const int maxLineLength = 100;
	char line[maxLineLength];
	rejects.rejects = new int[100]; 
	rejects.numRejects = 0; 
	data.students = new Student[100];
	data.numStudents = 0;
	int rejectcount = 0;
	int studentcount = 0;
	int rejectLineNum = 0;


	ifstream infile;
	infile.open(filename);
	if (!infile.is_open()){
		return -1;
	}

    if(minAcceptableID > maxAcceptableID){
    	return -1;
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

		Student student;

		int ID = 0;
		int k = 0;
		int value = 0;
		int mark = 0;
		int s = 1;
		int pos = 0;
		bool error = false; 

		if (!done){
		  while (line[k] != ','){
		      if (line[k] >= '0' && line[k] <= '9'){
		          value = line[k] - '0';
		          ID = ID*10 + value;
		      }
		      else if (line[k] != ' ' && line[k] != '\t'){
		          error = true;
		      }
		      k++;
		  }
		  // stud.studentID = ID;
		  k++;
		
		while (line[k]){
			if (line[k] >= '0' && line[k] <= '9'){
				value = line[k] - '0';
			    mark = mark*10 + value;
			}
			else if (line[k] == '-'){
		  		s = -1*s;
			}
			else if (line[k] != ' ' && line[k] != '\t'){
		  		error = true;
			}
			k++;
		}
		mark = mark*s;

		if (ID < minAcceptableID || ID > maxAcceptableID || mark < 0 || mark > 100 || error == true){
			rejects.rejects[rejectcount] = fileLineNumber;
			rejectcount++;
			rejectLineNum++;
		} else {
			student.grade = mark; 
			student.studentID = ID;
			studentcount += 1;
			data.students[pos] = student;
			pos += 1;
		}
	}
	rejects.numRejects = rejectcount; 
	data.numStudents = studentcount;
	if (rejectcount != 0){
		return 1; 
	}
}
	return 0;
	infile.close(); 
}


// void selection(int arr[], int size){
//   int max= 0; 
//   int temp = 0;
//   for (int i = max; i <= size-1; i++) {
//       if ( arr[i] > arr[max] ) {
//           max = i;
//       }
//   }
//   temp = arr[size-1];
//   arr[size-1] = arr[max];
//   arr[max] = temp;
//   if ( size > 1 ) {
//       selection (arr, --size);
//   }
// }

// bool sort(int arr[], const int size){
//   if (size <=0){
//     return false; 
//   } else {
//     selection(arr,size);
//     return true;
//   }
// }


int computeStatistics(Dataset& data, Statistics& stats){
	//Your code here ...
	double max = FLT_MIN;
	double min = FLT_MAX;
	double sum = 0;
	// cout << data.numStudents << endl; 
	// cout << max << endl; 
	// cout << min << endl; 
	for(int i = 0; i < data.numStudents; ++i) {
		if (data.students[i].grade > max) max = data.students[i].grade;
		if (data.students[i].grade < min) min = data.students[i].grade;
		sum += data.students[i].grade;
	}
	stats.average = sum / data.numStudents; 
	stats.minimum = min; 
	stats.maximum = max; 

	// cout << stats.average << endl; 
	// cout << stats.minimum << endl; 

	for (int i = 0; i < 10; ++i){
		stats.histogram[i] = 0; 
	}

	for(int i = 0; i < data.numStudents; ++i) {
		if ((data.students[i].grade >= 0) &&  (data.students[i].grade >= 9)){
			stats.histogram[0] += 1; 
		} else if ((data.students[i].grade >= 10) &&  (data.students[i].grade <= 19)){
			stats.histogram[1] += 1; 
		} else if ((data.students[i].grade >= 20) &&  (data.students[i].grade <= 29)){
			stats.histogram[2] += 1;
		} else if ((data.students[i].grade >= 30) &&  (data.students[i].grade <= 39)){
			stats.histogram[3] += 1;
		} else if ((data.students[i].grade >= 40) &&  (data.students[i].grade <= 49)){
			stats.histogram[4] += 1;
		} else if ((data.students[i].grade >= 50) &&  (data.students[i].grade <= 59)){
			stats.histogram[5] += 1;
		} else if ((data.students[i].grade >= 60) &&  (data.students[i].grade <= 69)){
			stats.histogram[6] += 1;
		} else if ((data.students[i].grade >= 70) &&  (data.students[i].grade <= 79)){
			stats.histogram[7] += 1;
		} else if ((data.students[i].grade >= 80) &&  (data.students[i].grade <= 89)){
			stats.histogram[8] += 1;
		} else if ((data.students[i].grade >= 90) &&  (data.students[i].grade <= 100)){
			stats.histogram[9] += 1;
		}
	}

	float var = 0; 
	for(int i = 0; i < data.numStudents; ++i) {
		var = var + pow(stats.average - data.students[i].grade, 2); 
	} 
	stats.popStdDev = pow(var/data.numStudents, 0.5);
	stats.smplStdDev = pow(var/(data.numStudents - 1), 0.5);

	int arr[data.numStudents]; 
	for (int i=0; i < data.numStudents; i++){
		arr[i] = data.students[i].grade; 
	}

	int modedataset[100]={0};

	// sort(arr, data.numStudents);
	// int modeArr[100]={0};
	// int count = 1;
	// int maximum = 1;
	// int num = 1;

	Mode mod;

	// for (int i = 0; i< data.numStudents -1 ; i++){
	// 	count = 1; //reset counter to 1 everytime when it excutes the while loop
	// 	while (arr[i] == arr[i+1]) {
	// 		count ++;
	// 		i++;
	// }
	// if (count == maximum){ 
	// 	modeArr[num] = arr[i];
	// 	num ++;
	// if (i == data.numStudents-2 && maximum == 1){
	// 	modeArr[num - 1] = arr[i+1];
	// 	}
	// } else if (count > maximum){
 //      maximum = count;
 //      num = 1; // reset number of modes to 1 if the other number appears more than the previous mode
 //      modeArr[0] = arr[i];
 //    }
 //    }

 //    mod.numModes = num; 
	mod.numModes = mode(arr, data.numStudents, modedataset); 


	return 0;
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


int writeCSV(const char filename[], const Statistics& stats){
	//Your code here ...
	int index = 0;
	bool extension = false; 
	int dot = 0; 
	while (filename[index] != 0) {
		if (filename[index] == '.') {
			extension = true; 
			dot = index; 
		}
		index++; 
	}
	index = index -1;
	char* FileCopy = new char[index + 6]; 

	for (int i = 0; i <= index; ++i){
		FileCopy[i] = filename[i]; 
	}

	if (extension){
		if (FileCopy[dot] == '.' && FileCopy[dot+1] == 'c' && FileCopy[dot+2] == 's' && FileCopy[dot+3] == 'v'){
			FileCopy[dot+1] = 's';
			FileCopy[dot+2] = 't';
			FileCopy[dot+3] = 'a';
			FileCopy[dot+4] = 't';		
		}
		else {
			return -1; 
		}
	} else {
			FileCopy[index+1] = '.';
			FileCopy[index+2] = 's';
			FileCopy[index+3] = 't';
			FileCopy[index+4] = 'a';
			FileCopy[index+5] = 't';
			FileCopy[index+6] = 0;
	}

    ofstream outfile;
    outfile.open(filename);
    if (!outfile.is_open()){
        return -1;
    }

    outfile << "Minimum: " << stats.minimum << endl; 
    outfile << "Average: " << stats.average << endl; 
    outfile << "Maximum: " << stats.maximum << endl; 
    outfile << "Population Standard Deviation: " << stats.popStdDev << endl; 
    outfile << "Sample Standard Deviation: " << stats.smplStdDev << endl; 
    outfile << "Modes: ";
    for (int i = 0; i < stats.mode.numModes; ++i){
    	outfile << stats.mode.modes[i];
    	if (i < stats.mode.numModes -1) {
    		outfile << ", ";
    	}
    }
    outfile << endl; 
    outfile << "Histogram: " << endl; 
    outfile << "[0-9]" << stats.histogram[0] << endl; 
    outfile << "[10-19]" << stats.histogram[1] << endl; 
    outfile << "[20-29]" << stats.histogram[2] << endl; 
    outfile << "[30-39]" << stats.histogram[3] << endl; 
    outfile << "[40-49]" << stats.histogram[4] << endl; 
    outfile << "[50-59]" << stats.histogram[5] << endl; 
    outfile << "[60-69]" << stats.histogram[6] << endl; 
    outfile << "[70-79]" << stats.histogram[7] << endl; 
    outfile << "[80-89]" << stats.histogram[8] << endl;     
    outfile << "[90-100]" << stats.histogram[9] << endl; 


    outfile.close();
	return 0;
}
//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  	
	// Some test driver code here ....
	int minAcceptableID = 0;
	int maxAcceptableID = 2000000;

	Dataset data = {0};
	Rejects rejects = {0};
	Statistics stats = {0};

	std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;

	if(readCSV(argv[1], minAcceptableID, maxAcceptableID, data, rejects) < 0)
	{
		std::cout << ".csv file could not be read" << std::endl;
	}

	if (computeStatistics(data, stats) < 0)
	{
		std::cout << "Stats could not be computed" << std::endl;
	}

	if (writeCSV(argv[1], stats) < 0)
	{
		std::cout << ".stat file could not be written" << std::endl;
	}

	std::cout << "Average: " << stats.average << std::endl;
	std::cout << "Minimum: " << stats.minimum << std::endl;
	std::cout << "Maximum: " << stats.maximum << std::endl;
	std::cout << "Population standard deviation: " << stats.popStdDev << std::endl;
	std::cout << "Sample standard deviation: " << stats.smplStdDev << std::endl;
	
	
	for (unsigned char i = 0; i < stats.mode.numModes; i++)
	{
		std::cout << "Mode: " << stats.mode.modes[i] << std::endl;
	}

	for (unsigned char i = 0; i < 10; i++)
	{
		std::cout << "Histogram bin [" << (i*10) << ", " << ((((i+1)*10) - 1) + i/9) << "]: " << stats.histogram[i] << std::endl;
	}
	

	return 0;
}

#endif
