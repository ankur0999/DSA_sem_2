#include<iostream>
using namespace std;
// I'm going to make minimum heap
void min_heapify(int arr[], int index, int n){
    if(index >= n) return;
    int left = 2*index + 1;
    int right = 2*index + 2;
    int minimum = index;
    if(left < n && arr[minimum] > arr[left]){
        minimum = left;
    }
    if(right < n && arr[minimum] > arr[right]){
        minimum = right;
    }
    if(minimum != index){
        swap(arr[minimum], arr[index]);
        min_heapify(arr, minimum, n);
    }

}
void make_heap(int arr[], int n){
    for(int i=(n-1)/2; i>=0; i--){
        min_heapify(arr, i, n);
    }
}

int remove_min(int arr[], int& size){
    int ans = arr[0];
	swap(arr[0], arr[size-1]);
	size--;
	min_heapify(arr, 0, size);
    return ans;
}
void insert(int arr[], int& size, int val){
    arr[size] = val;
    size++;
    int parent = (size-2)/2;
    int index = size-1;
    while(arr[parent] > arr[index]){
        swap(arr[parent], arr[index]);
        index = parent;
        parent = (index-1)/2;
        }
}
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {3, 4, 1, 8, 2, 0, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    make_heap(arr, size);
    print(arr, size);
    insert(arr, size, 5);
    print(arr,size);
    cout<<remove_min(arr, size)<<endl;
    cout<<remove_min(arr, size)<<endl;
    cout<<remove_min(arr, size)<<endl;
    cout<<remove_min(arr, size)<<endl;
}