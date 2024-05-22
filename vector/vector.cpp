#include<iostream>
using namespace std;

class vector{
    public:
        int* arr;
        int capacity;
        
        int size;
    
        vector(){
        arr = new int[4];
        capacity = 4;
        int size = 0;
        }
        void push_back(int a){
        if(size < capacity){
            arr[size++] = a;
            }
        else{
        capacity = 2*capacity;
        int* arr1 = new int[capacity];
        for(int i=0; i<size; i++){
            arr1[i] = arr[i];
        }
        delete[] arr;
        arr = arr1;
        arr[size++] = a;
        }
        }
        void pop_back(){
        float load_factor = float(size)/float(capacity);
        cout<<load_factor<<endl;
        if(load_factor >= 0.25){
        size--;
        }
        else{
        size--;
        capacity = capacity/2;
        int* arr1 = new int[capacity];
        for(int i=0; i<size; i++){
            arr1[i] = arr[i];
            }
        delete[] arr;
        arr = arr1;
        }
        }
        };
  void print(vector v){
       for(int i=0; i<v.size; i++){
           cout <<  v.arr[i] << " ";
           }
           cout << endl;
           }
        
int main(){
    vector v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);
    v.push_back(12);
    v.push_back(6);
    v.push_back(8);
    v.push_back(2);
    cout<<v.capacity<<endl;
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    cout<<v.capacity<<endl;
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    print(v);
    }
        
        
        
        
    