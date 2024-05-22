#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class heap{
    private:
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

    public:
    vector<int> arr;
    heap(vector<int> vec){
       for(int i=0; i< vec.size(); i++){
           arr.push_back(vec[i]);
           }
    }
    void buildHeap(){
        int size = arr.size();
        for(int i = (size-1)/2; i>=0; i--){
                maxHeapify(arr, i, size);
        }
    }
    void removeMax(){
        int size = arr.size();
        swap(arr[0], arr[size-1]);
        arr.pop_back();
        maxHeapify(arr, 0, arr.size());
    }
    void insert(int data){
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
    void heapSort(){
        int size = arr.size();
        while(size > 1){
                swap(arr[0], arr[size-1]);
                size--;
                maxHeapify(arr, 0, size);
        }
}
};
void print(vector<int> arr){
        int size = arr.size();
        for(int i=0; i< size; i++){
                cout << arr[i] << " ";
        }
        cout << endl;
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
    heap H(arr);
    H.buildHeap();
    cout << "Heapified array " << endl;
    print(H.arr);
    H.removeMax();
    cout << " array after removing max element "<< endl;
    print(H.arr);
    cout<< " let insert new element 20 " << endl;
    H.insert(20);
    print(H.arr);
    
    H.heapSort();
    cout << " after sorting "<<endl;
    print(H.arr);
    myfile.close();
    return 0;
}
 


    
    
        

