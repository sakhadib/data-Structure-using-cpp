void countingSort(int *arr, int len){
    int max = arr[0];
    for(int i = 1; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int *count = new int[max + 1];
    for(int i = 0; i < max + 1; i++){
        count[i] = 0;
    }
    for(int i = 0; i < len; i++){
        count[arr[i]]++;
    }
    int j = 0;
    for(int i = 0; i < max + 1; i++){
        while(count[i] > 0){
            arr[j] = i;
            j++;
            count[i]--;
        }
    }
    delete[] count;
}