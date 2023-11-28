//Adib Sakhawat - sakhadib
//IUT, 2023

#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int main() {

    int x = fib(4);
    cout << x ;
    return 0;
}
