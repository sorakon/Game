//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int SWStats(const float dataset[], const int size,
            const int currentSample, const int windowSize,
            float& min, float& avg, float& max,
            float& smplSD, float& mdn);

int SWMinimum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& minimum);
int SWAverage(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& average);
int SWMaximum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& maximum);
int SWSmplStdDev(const float dataset[], const int size,
                 const int currentSample, const int windowSize,
                 float& smplStdDev);
int SWMedian(const float dataset[], const int size,
             const int currentSample, const int windowSize,
             float& median);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

float average(const float dataset[], const int size) {
    float sum=0;
    for (int i=0; i<size; i++) {
        sum+=dataset[i];
    }
    float avg=sum/(size);
    return avg;
}

float med(const float dataset[], const int size) {
    float *nums=new float[size];
    for (int i=0; i<size; i++) {
        nums[i]=dataset[i];
    }
    for (int i = 0; i < size - 1; i++) {
        for (int k = 0; k < size - i - 1; k++) {
            if (nums[k] > nums[k + 1]) {
                float temp = nums[k];
                nums[k] = nums[k + 1];
                nums[k + 1] = temp;
            }
        }
    }
    float median;
    if (size%2==0) {
        median=(nums[size/2-1]+nums[size/2])/2;
    }else{
        median=nums[(size+1)/2-1];
    }
    return median;
}

int SWStats(const float dataset[], const int size,
            const int currentSample, const int windowSize,
            float& min, float& avg, float& max,
            float& smplSD, float& mdn) {
    if(windowSize<=0){
        return -1;
    }
    if(windowSize==1 || windowSize>size){
        SWMinimum(dataset, size, currentSample, windowSize, min);
        SWAverage(dataset, size, currentSample, windowSize, avg);
        SWMaximum(dataset, size, currentSample, windowSize, max);
        SWSmplStdDev(dataset, size, currentSample, windowSize, smplSD);
        SWMedian(dataset, size, currentSample, windowSize, mdn);
        return 1;
    }
    SWMinimum(dataset, size, currentSample, windowSize, min);
    SWAverage(dataset, size, currentSample, windowSize, avg);
    SWMaximum(dataset, size, currentSample, windowSize, max);
    SWSmplStdDev(dataset, size, currentSample, windowSize, smplSD);
    SWMedian(dataset, size, currentSample, windowSize, mdn);
    return 0;
}

int SWMinimum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& minimum) {
    float* sizeArr=new float[windowSize];
    for (int a=0; a<windowSize; a++) {
        if(currentSample+1-windowSize>=0){
            sizeArr[a]=dataset[currentSample+1-windowSize+a];
        }else{
            if (a>currentSample) {
                sizeArr[a]=dataset[0];
            }else{
                sizeArr[a]=dataset[a];
            }
        }
    }
    
    minimum=sizeArr[0];
    for (int a=0; a<windowSize; a++) {
        if(minimum>sizeArr[a]){
            minimum=sizeArr[a];
        }
    }
    return 0;
}

int SWAverage(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& average) {
    float* sizeArr=new float[windowSize];
    for (int j=0; j<windowSize; j++) {
        if(currentSample+1-windowSize>=0){
            sizeArr[j]=dataset[currentSample+1-windowSize+j];
        }else{
            if (j>currentSample) {
                sizeArr[j]=dataset[0];
            }else{
                sizeArr[j]=dataset[j];
            }
        }
    }
    double sum=0;
    for (int i=0; i<windowSize; i++) {
        sum+=sizeArr[i];
    }
    average=sum/windowSize;
    return 0;
}

int SWMaximum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& maximum) {
    float* sizeArr=new float[windowSize];
    for (int i=0; i<windowSize; i++) {
        if(currentSample+1-windowSize>=0){
            sizeArr[i]=dataset[currentSample+1-windowSize+i];
        }else{
            if (i>currentSample) {
                sizeArr[i]=dataset[0];
            }else{
                sizeArr[i]=dataset[i];
            }
        }
    }
    
    maximum=sizeArr[0];
    for (int i=0; i<windowSize; i++) {
        if(maximum<sizeArr[i]){
            maximum=sizeArr[i];
        }
    }
    return 0;
}

int SWSmplStdDev(const float dataset[], const int size,
                 const int currentSample, const int windowSize,
                 float& smplStdDev) {
    float* sizeArr=new float[windowSize];
    for (int a=0; a<windowSize; a++) {
        if(currentSample+1-windowSize>=0){
            sizeArr[a]=dataset[currentSample+1-windowSize+a];
        }else{
            if (a>currentSample) {
                sizeArr[a]=dataset[0];
            }else{
                sizeArr[a]=dataset[a];
            }
        }
    }
    
    float ssDevSum=0;
    float avg = average(sizeArr, windowSize);
    for(int i=0; i<windowSize; i++){
        ssDevSum+=pow(avg-sizeArr[i], 2);
    }
    smplStdDev=pow(ssDevSum/(windowSize-1), 0.5);
    return 0;
}

int SWMedian(const float dataset[], const int size,
             const int currentSample, const int windowSize,
             float& median) {
    float* sizeArr=new float[windowSize];
    for (int a=0; a<windowSize; a++) {
        if(currentSample+1-windowSize>=0){
            sizeArr[a]=dataset[currentSample+1-windowSize+a];
        }else{
            if (a>currentSample) {
                sizeArr[a]=dataset[0];
            }else{
                sizeArr[a]=dataset[a];
            }
        }
    }
    median=med(sizeArr, windowSize);
    return 0;
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
    int size = 1;
    float dataset[] = {17.6028};
    int windowSize = 4;
    int currentSample = 0;
    float min;
    float avg;
    float max;
    float smplSD;
    float median;
    
    cout << "Sample \t Minimum \t Average \t Median \t Maximum \t Sample Standard Deviation" << endl;
    
    while (currentSample < size) {
        int retCode = SWStats(dataset, size, currentSample, windowSize, min, avg, max, smplSD, median);
        if (retCode >= 0) {
            cout << currentSample << "\t " << min << "\t " << avg << "\t " << max << "\t " << median << "\t " << smplSD << endl;
            if (retCode > 0)
                cerr << "Warning: something weird happened, but we computed stats anyway ... YMMV" << endl;
        }
        else {
            cerr << "Error: unable to compute sliding-window statistics; exiting" << endl;
            return(-1);
        }
        ++currentSample;
    }
    return 0;
}

#endif
