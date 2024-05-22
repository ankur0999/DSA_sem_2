

void insertion_sort(int* arr, int start, int end){
    int i, j, key;
    
    for(i=start; i<= end; i++){
        key = arr[i];
        j = i-1;
        while(j>=start && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
            }
        arr[j+1] = key;
        }
}

