#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>
using namespace std;

void heapify(int arr[], int size, int index){
	int largest = index;
	int left = 2*index;
	int right = 2*index + 1;
	if(left <= size && arr[largest] < arr[left])
		largest = left;
	if(right <= size && arr[largest] < arr[right])
		largest = right;
	if(largest != index){
		swap(arr[largest], arr[index]);
		heapify(arr, size, largest);
	}}

void heap_sort(int arr[], int size){
	while(size >1){
	    
	    swap(arr[1], arr[size]);
	    size--;
	    heapify(arr, size, 1);
	}
}

int main(int argc, char* argv[]){
	fstream myfile(argv[1]);
	ofstream mesurement(argv[2], ios_base::app);
	int noOfElement = stoi(argv[3]);
	int a, l=1;
	int* arr = new int[noOfElement+1];
	while(l<=noOfElement){
		myfile >> a;
		arr[l++] = a;
	}
	struct timespec begin;
	timespec_get(&begin, TIME_UTC);
	for(int i= (l-1)/2; i>0; i--)
	    heapify(arr, l-1, i);
	heap_sort(arr,l-1);
	struct timespec end;
	timespec_get(&end, TIME_UTC);
	double time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000000.0;
	mesurement << noOfElement <<" "<<time_spent<<endl;
	/*for(int i=1; i<l; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;*/
	myfile.close();
	mesurement.close();
	delete []arr;
}


