#include<iostream>
using namespace std;
int partition(int arr[], int s, int e){
    int pivot = arr[e];
    int i = s-1;
    for(int j = s; j<e; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i = i+1;
    swap(arr[i], arr[e]);
   // cout<<i<<endl;
    return i;
}

int k_largest(int arr[],int i, int j, int k){
    if(i>j) return -1;
     int p = partition(arr, i, j);
     int rel = i+k-1;
     if(rel == p) return arr[p];
     else if(rel < p)
        return k_largest(arr, i, p-1, k);
     else 
        return k_largest(arr, p+1 , j, rel-p);
     
}
int main(){
    int arr[10] = {5, 10, 1, 43, 23, 98, 3, 62, 14, 6};
    //int arr[6] = {5, 10, 1, 43, 23, 98};
    cout <<k_largest(arr ,0 ,9, 5)<< endl;
}