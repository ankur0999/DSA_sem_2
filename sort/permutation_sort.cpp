#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<time.h>
#include<string>
using namespace std;
bool isSorted(vector<int> arr){
	int l = arr.size();
	while(--l > 0)
		if(arr[l-1] > arr[l])
			return false;
	return true;
}

void solve(vector<int>& arr, vector<vector<int>>& output, int index){
	if(index >= arr.size()){
		output.push_back(arr);
		return;
	}
	for(int i = index; i< arr.size(); i++){
		swap(arr[index], arr[i]);
	        if(isSorted(arr)){
			output.push_back(arr);
			return;
		}
		solve(arr, output, index + 1);
		swap(arr[index], arr[i]);
	}
}
vector<vector<int>> slow_sort(vector<int>& arr){
	vector<vector<int>> output;
	int index = 0; 
	solve(arr, output, index);
	sort(output.begin(), output.end());
	return output;
}
void printArray(vector<int> arr){
	for(int i=0; i<arr.size(); i++){
		cout<< arr[i] <<" ";
	}
	cout<<endl;
}
int main(int argc, char* argv[]){
	vector<int> arr;
	fstream myfile(argv[1]);
	ofstream mesurement(argv[2], ios_base::app);
	int noOfElement = stoi(argv[3]);
	int l=0,a;
	while(l < noOfElement){
		myfile >> a;
		arr.push_back(a);
		l++;
	}
	//cout<<"before sorted "<<endl;
	//printArray(arr);
	struct timespec begin;
	timespec_get(&begin, TIME_UTC);
	vector<vector<int>> output = slow_sort(arr);
	struct timespec end;
	timespec_get(&end, TIME_UTC);
	double time_taken = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000000.0;
	mesurement << noOfElement << " "<<time_taken<<endl;
	cout<<"after sorted "<<endl;
	printArray(output[0]);
	myfile.close();
	mesurement.close();
	arr.clear();
	return 0;
}
