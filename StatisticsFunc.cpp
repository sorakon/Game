//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>
#include <limits.h>
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

bool statistics(const float dataset[], const int size,
                float& min, float& avg, float& max,
                float& popSD, float& smplSD, float& mdn);

float minimum(const float dataset[], const int size);
float average(const float dataset[], const int size);
float maximum(const float dataset[], const int size);
float popStdDev(const float dataset[], const int size);
float smplStdDev(const float dataset[], const int size);
float median(const float dataset[], const int size);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

bool statistics(const float dataset[], const int size,
                float& min, float& avg, float& max,
                float& popSD, float& smplSD, float& mdn) {
    if (size <= 0){
        return false;
    }
    min = minimum(dataset, size);
    avg = average(dataset, size);
    max = maximum(dataset, size);
    popSD = popStdDev(dataset, size);
    smplSD = smplStdDev(dataset, size);
    mdn = median(dataset, size);
    return true;
}

float minimum(const float dataset[], const int size) {
    float min = dataset[0];
    for (int i = 0; i < size; ++i) {
        float value = dataset[i]; //find minimum
        if ( value < min) min = value; }
    return min;
}

float average(const float dataset[], const int size) {
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        float value = dataset[i]; //find minimum
        sum += value;
    }
    float ave = sum/size;
    return ave;
}

float maximum(const float dataset[], const int size) {
    float max = dataset[0];
    for (int i = 0; i < size; ++i) {
        float value = dataset[i]; //find minimum
        if ( value > max) max = value; }
    return max;
}

float popStdDev(const float dataset[], const int size) {
    float var = 0;
    float ave = average(dataset, size);
    for (int i = 0; i < size; ++i) {
        var = var+ pow(ave - dataset[i], 2);
    }
    float psDev = pow(var/size, 0.5);
    return psDev;
}

float smplStdDev(const float dataset[], const int size) {
    float var = 0;
    float ave = average(dataset, size);
    for (int i = 0; i < size; i++) {
        var = var + pow(ave - dataset[i], 2);
    }
    float ssDev = pow(var/(size-1), 0.5);
    return ssDev;
}

float median(const float dataset[], const int size) {
    float *nums = new float[size];
    for (int i = 0; i <size; i++){
        nums[i]=dataset[i];
    }
    for (int i = 0; i <size-1; i++) {
        for (int j= 0; j<size-i-1; j++) {
            if (nums[j]>nums[j+1]){
                float temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
    float median;
    if (size%2 !=0) {
        median = nums[(size+1)/2-1];
    } else {
        median = (nums[size/2-1]+nums[size/2])/2;
    }
    return median;
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
    int size = 16;
    float dataset[] = {17.6028,10.9157,16.7465,16.9766,18.6747,7.96327,10.0283,16.5234,9.16662,13.3095,12.161,14.4331,10.4718,12.701,19.2834};
    float min;
    float avg;
    float max;
    float popStDev;
    float smplStDev;
    float median;
    
    if (statistics(dataset, size, min, avg, max, popStDev, smplStDev, median)) {
        cout << "Minimum: " << min << endl
        << "Average: " << avg << endl
        << "Median:  " << median << endl
        << "Maximum: " << max << endl
        << "Population Standard Deviation: " << popStDev << endl
        << "Sample Standard Deviation:     " << smplStDev << endl;
    }
    else
        cout << "Error: unable to compute statistics" << endl;
    
    return 0;
}

#endif
