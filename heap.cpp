#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
void maxHeapify(vector<int>& arr, int index ,int size){
	int largest = index;
	int left = 2*index + 1;
	int right = 2*index + 2;
	if( left < size && arr[largest] < arr[left]) 
		largest = left;
	if(right < size && arr[largest] < arr[right])
		largest = right;
	if(largest != index){
		swap(arr[largest], arr[index]);
		maxHeapify(arr, largest, size);
	}
}

void heap(vector<int>& arr){
	int size = arr.size();
	for(int i = (size-1)/2; i>=0; i--){
		maxHeapify(arr, i, size);
	}
}
void print(vector<int> arr){
	int size = arr.size();
	for(int i=0; i< size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
void removeMax(vector<int>& arr){
	int size = arr.size();
	swap(arr[0], arr[size-1]);
	arr.pop_back();
	maxHeapify(arr, 0, arr.size());
}
void insert(vector<int>& arr, int data){
	arr.push_back(data);
	int size = arr.size();
	int index = size-1;
	int parent = (index-1)/2;
	while(arr[parent] < arr[index]){
		swap(arr[parent], arr[index]);
		index = parent;
		parent = (index-1)/2;
	}
}
void heapSort(vector<int> & arr, int size){
	while(size > 1){
		swap(arr[0], arr[size-1]);
		size--;
                maxHeapify(arr, 0, size);
	}
}

int main(int argc, char* argv[]){
    fstream myfile(argv[1]);
    int a;
    vector<int> arr;
    while(myfile >> a){
	    arr.push_back(a);
    }
    cout<< "Original Array " << endl;
    print(arr);
    heap(arr);
    cout << "Heapified array " << endl;
    print(arr);
    removeMax(arr);
    cout << " array after removing max element "<< endl;
    print(arr);
    cout<< " let insert new element 20 " << endl;
    insert(arr, 20);
    print(arr);
    int size = arr.size();
    heapSort(arr, size);
    cout << " after sorting "<<endl;
    print(arr);
    myfile.close();
    return 0;
}

