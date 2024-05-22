#include<iostream>
using namespace std;
int* counting_sort(int A[], int n, int k){
	int* B = new int[n];
	int* C = new int[k];
	for(int i=0; i<k; i++)
                C[i] = 0;
	for(int i=0; i<n; i++)
		C[A[i]]++;
	for(int i=1; i<k; i++)
                C[i] = C[i-1] + C[i];
	for(int i= n-1; i>=0; i--){
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
	return B;
}
void print(int arr[],int n){
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main(){
	int arr[8] = {2,5,3,0,2,3,0,3};
	int* result = counting_sort(arr, 8, 6);
	print(result, 8);
}
