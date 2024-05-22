#include <bits/stdc++.h>
#include<fstream>
#include<string>
#include<time.h>
using namespace std;

bool isSorted(int arr[], int size){
	
	while(--size > 0)
		if(arr[size-1] > arr[size])
			return false;
		return true;
}
void shuf(int arr[], int size){
	for(int i=0; i<size; i++)
		swap(arr[i],arr[rand()%size]);
}

void bogoSort(int arr[], int size){
	while(!isSorted(arr, size)){
		shuf(arr, size);
	}
}

void printArray(int arr[], int size){
	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}
}
int main(int argc, char* argv[]){
        fstream myfile(argv[1]);
	ofstream mesurement(argv[2], ios_base :: app);
	int noOfElement = stoi(argv[3]);
	int l=0,a;
	int* arr = new int[noOfElement];
	while(l<noOfElement){
		myfile >> a;
		arr[l++] = a;
	}
	//int arr[6] = {3, 4, 1, 6, 9, 0};
	//cout<<" array before sorting "<<endl;
	//printArray(arr, 6);
        //cout<<" after sorting " <<endl;
	struct timespec begin;
	timespec_get(&begin, TIME_UTC);
	bogoSort(arr, l);
	struct timespec end;
	timespec_get(&end, TIME_UTC);
	double time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000000.0;

	//printArray(arr, 6);
	mesurement<<noOfElement<<" "<<time_spent<<endl;
	mesurement.close();
	myfile.close();
	delete[] arr;
	return 0;
}
