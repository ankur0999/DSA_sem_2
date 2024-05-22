#include<iostream>
#include<time.h>
#include<unistd.h>
#include<fstream>
#include<string.h>
using namespace std;

void insertion_sort(int* arr, int size){
    int i, j, key;
    for(i=1; i< size; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
            }
        arr[j+1] = key;
        }
}

int main(int argc, char* argv[]){
    std :: fstream myfile(argv[1]);
   // std :: ofstream outfile(argv[2]);
    std :: ofstream mesurement(argv[2],std::ios_base::app);
//    outfile<< "sorted integers are: "<<endl<<endl;
    int noOfElement = stoi(argv[3]);
    int a, l=0, arr[noOfElement];
    while(myfile >> a){
        arr[l] = a;
        l++;
    }
    //int arr[] = {3, 4, 5, 1, 6}; 
    struct timespec begin;
    timespec_get(&begin,TIME_UTC);
    //struct timespec begin2;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin2);
    insertion_sort(arr, l);
    //sleep(5);
    struct timespec end;
    timespec_get(&end, TIME_UTC);
    //struct timespec end2;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end2);
    double time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000000.0;
    //double time_spent2 = (end2.tv_sec - begin2.tv_sec) + (end2.tv_nsec - begin2.tv_nsec)/1000000000.0;
   // cout<< " Time it took to excute: "<< time_spent<<endl;
   mesurement<<noOfElement<<" "<<time_spent<<endl; 
   //cout<<"  CPU Time: "<< time_spent2<<endl;
    //for(int i=0; i<l; i++){
   //outfile<<arr[i] <<endl;
    //}
    //outfile.close();
    myfile.close();
    mesurement.close();
    //getchar();
}
