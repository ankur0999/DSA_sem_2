#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>
using namespace std;

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int* arr, int s, int e){
     int pivot = arr[e];
     int i = s-1;
     for(int j = s; j<e; j++){
	     if(arr[j] <= pivot){
		     i++;
		     swap(arr[i],arr[j]);
	     }
     }
     i = i+1;
     swap(arr[i],arr[e]);
     return i;
}

void quick_sort(int* arr, int s, int e){
    if(s < e){
	    int k = partition(arr, s, e);
	    quick_sort(arr, s, k-1);
	    quick_sort(arr, k+1, e);
    }
}

int  main(int argc, char* argv[]){
	fstream myfile(argv[1]);
	ofstream mesurement(argv[2],ios_base::app);
	int noOfElement = stoi(argv[3]);
        
	int* arr = new int[noOfElement];
	int a, l=0;
	while(l < noOfElement){
		myfile>>a;
		arr[l++] = a;
	}
	struct timespec begin;
	timespec_get(&begin, TIME_UTC);
	quick_sort(arr, 0, l-1);
	struct timespec end;
	timespec_get(&end, TIME_UTC);
	double timeSpent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000000.0;
	/*for(int i=0; i<l; i++){
		cout << arr[i]<<" ";
	}*/
	cout<<endl;
	mesurement<< noOfElement<< " " <<timeSpent<<endl;
	mesurement.close();
	myfile.close();
	delete []arr;
}


