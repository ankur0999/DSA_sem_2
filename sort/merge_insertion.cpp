#include<iostream>
#include<time.h>
#include<unistd.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<climits>
#include "insertion_sort.h"
using namespace std;


void merge(int* arr, int s, int e){
    int mid = s + (e - s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* left = new int[len1];
   // left[len1] = INT_MAX;

    int* right = new int[len2];
   // right[len2] = INT_MAX;

    int mainArrayIndex = s;
    for(int i=0; i<len1; i++){
	    left[i] = arr[mainArrayIndex++];
    }
    for(int i=0; i<len2; i++){
	    right[i] = arr[mainArrayIndex++];
    }
    int index1 = 0;
    int index2 = 0;
    /*
    for(int r = s; r < e; r++){
        if(left[index1] < right[index2]){
		arr[r] = left[index1++];
	}
	else{
		arr[r] = right[index2++];
	}
    }*/
    mainArrayIndex = s;
	
	while(index1 < len1 && index2 < len2){
	
	    if(left[index1] < right[index2])
	    	arr[mainArrayIndex++] = left[index1++];
	    else
	        arr[mainArrayIndex++] = right[index2++];
	        
		}
	while(index1 < len1){
		arr[mainArrayIndex++] = left[index1++];
	}
	while(index2 < len2)
	    arr[mainArrayIndex++] = right[index2++];
    delete []left;
    delete []right;
}


void merge_sort(int* arr, int s, int e){
	
	int mid = s + (e - s)/2;
	if((e - s) <= 2000){
		
		insertion_sort(arr, s, e);
		return;
	}
	
	merge_sort(arr, s, mid);
	merge_sort(arr, mid+1, e);
	merge(arr, s, e);
}


int main(int argc, char* argv[]){
    std:: fstream myfile(argv[1]);
    std:: ofstream mesurement(argv[2], std::ios_base::app);
   // std:: ofstream outfile(argv[4]);
    int noOfElement = stoi(argv[3]);
    int a, l=0;
    int* arr = new int[noOfElement];
    while(l <= noOfElement){
	    myfile >> a;
	    arr[l++] = a;
    }
	    
    
    struct timespec begin;
    timespec_get(&begin, TIME_UTC);
    merge_sort(arr, 0, l-1);
    struct timespec end;
    timespec_get(&end, TIME_UTC);
    double time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000000.0;
    /*for(int i=0; i<l; i++){
	    outfile << arr[i] << endl;
    }*/
   // cout<<endl;
    mesurement<<noOfElement<<" "<<time_spent<<endl;
   //cout<< noOfElement<<" "<<time_spent<<endl;
    mesurement.close();
    myfile.close();
}

