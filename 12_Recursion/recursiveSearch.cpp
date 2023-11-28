//Adib Sakhawat - sakhadib
//IUT, 2023

#include <bits/stdc++.h>
using namespace std;

bool search(int *arr, int len, int itr, int val){
    if(itr == len){
        return false;
    }

    if(arr[itr] == val){
        return true;
    }

    return search(arr, len, ++itr, val);
}

int main() {

    int arr[5] = {1, 4, 2, 3, 5};
    int len = sizeof(arr)/sizeof(int);

    int q = 12;

    bool iS = search(arr, len, 0, q);

    if(iS) cout << "found" ;
    else cout << "not found";
    return 0;
}