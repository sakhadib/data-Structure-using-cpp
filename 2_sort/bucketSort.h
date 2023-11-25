void bucketSort(int *arr, int len){
    int max = arr[0];
    int min = arr[0];
    for(int i = 1; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    int bucketLen = max - min + 1;
    int *bucket = new int[bucketLen];
    for(int i = 0; i < bucketLen; i++){
        bucket[i] = 0;
    }
    for(int i = 0; i < len; i++){
        bucket[arr[i] - min]++;
    }
    int index = 0;
    for(int i = 0; i < bucketLen; i++){
        for(int j = 0; j < bucket[i]; j++){
            arr[index++] = i + min;
        }
    }
    delete[] bucket;
}