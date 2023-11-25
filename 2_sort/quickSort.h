void quickSort(int *arr, int len){
    if(len < 2) return;
    int pivot = arr[len - 1];
    int i = -1;
    for(int j = 0; j < len - 1; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[len - 1];
    arr[len - 1] = temp;
    quickSort(arr, i + 1);
    quickSort(arr + i + 2, len - i - 2);
}