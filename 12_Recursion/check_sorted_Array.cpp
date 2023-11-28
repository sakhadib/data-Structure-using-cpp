//Adib Sakhawat - sakhadib
//IUT, 2023

#include <bits/stdc++.h>
using namespace std;

bool isSorted(int *arr, int len, int curr){
    if(curr == len - 1){
        return true;
    }

    if(arr[curr] > arr[curr + 1]){
        return false;
    } 

    //curr = curr + 1;

    return isSorted(arr, len, ++curr);
}

int main() {

    int arr[5] = {1, 2, 3, 8, 5};

    int len = sizeof(arr)/sizeof(int);

    bool iS = isSorted(arr, len, 0);

    if(iS){
        cout << "okay";
    }
    else{
        cout << "not Okay";
    }

    return 0;
}