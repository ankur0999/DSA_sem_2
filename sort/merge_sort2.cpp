#include<iostream>
#include<time.h>
#include<unistd.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<climits>
using namespace std;


void merge(int* arr, int s, int e, int* left, int* right){
    int mid = s + (e - s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    //int* left = new int[len1];
   // left[len1] = INT_MAX;

    //int* right = new int[len2];
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
   // delete []left;
    //delete []right;
}


void merge_sort(int* arr, int s, int e, int* left, int* right){
	if(s>=e)
		return;
	int mid = s + (e - s)/2;
	merge_sort(arr, s, mid, left, right);
	merge_sort(arr, mid+1, e, left, right);
	merge(arr, s, e, left, right);
}


int main(int argc, char* argv[]){
    std:: fstream myfile(argv[1]);
    std:: ofstream mesurement(argv[2], std::ios_base::app);
    int noOfElement = stoi(argv[3]);
    int a, l=0;
    int* arr = new int[noOfElement];
    int* left = new int[(noOfElement/2)+1];
    int* right = new int[noOfElement/2];
    while(l<noOfElement){
	    myfile >> a;
	    arr[l++] = a;
    }
	    
    
    struct timespec begin;
    timespec_get(&begin, TIME_UTC);
    merge_sort(arr, 0, l-1, left, right);
    struct timespec end;
    timespec_get(&end, TIME_UTC);
    double time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000000.0;
    /*for(int i=0; i<l; i++){
	    cout << arr[i] << " ";
    }*/
    cout<<endl;
    mesurement<<noOfElement<<" "<<time_spent<<endl;
    mesurement.close();
    myfile.close();
    delete [] arr;
    delete [] left;
    delete [] right;
}

