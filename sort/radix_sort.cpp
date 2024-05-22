#include<iostream>
using namespace std;
#include<math.h>
#include<fstream>
#include<string>
#include<time.h>

int* radix_sort(int A[], int n, int d){
	int* B = new int[n];
	int* C = new int[10];
	for(int i=0; i<10; i++)
		C[i] = 0;
	for(int i=0; i<d; i++){
		int a = pow(10,i);
		
		for(int j=0; j<n; j++)
			C[(A[j]/a)%10]++;
		
		
		for(int j=1; j<10; j++)
			C[j] = C[j-1] + C[j];
		for(int j=n-1; j>=0; j--){
			B[C[(A[j]/a)%10]-1] = A[j];
			C[(A[j]/a)%10]--;
		}
		for(int j=0; j<n; j++)
		    A[j] = B[j];
		
		for(int j=0; j<10; j++)
			C[j] = 0;
	}
        delete[] B;
        delete[] C;
	return A;
}
void print(int arr[], int n){
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	        cout<<endl;
}
int main(int argc, char* argv[]){
	//int arr[7] = {329, 457, 657, 839, 436, 720, 355};
	fstream input(argv[1]);
	ofstream output(argv[2]);
	//ofstream mesurement(argv[2], ios_base :: app);
	int noOfElement = stoi(argv[3]);
	int a, l=0;
	int* arr = new int[noOfElement];
	while(l < noOfElement){
		input >> a;
		arr[l++] = a;
	}
	//struct timespec begin;
	//timespec_get(&begin, TIME_UTC);
	int* result = radix_sort(arr, l, 8);
	//struct timespec end;
	//timespec_get(&end, TIME_UTC);
	//double time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000000.0;
	//mesurement << noOfElement << " " << time_spent << endl;
	for(int i=0; i<l ; i++){
		output<<result[i]<<endl;
	}
        //print(result, 7);
	}
/*int main(){
	int arr[] ={28 , 35, 35, 73, 95, 69, 32, 76, 13, 35, 2, 8,385, 125, 402};
	int* b = radix_sort(arr, 15, 3);
	print(arr, 15);
}*/