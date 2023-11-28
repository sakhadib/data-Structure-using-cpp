//Adib Sakhawat - sakhadib
//IUT, 2023

#include <bits/stdc++.h>
using namespace std;

int power(int num, int pow){
    if(pow == 0){
        return 1;
    }

    return num * power(num, --pow);
}

int main() {

    int x = power(2, 4);
    cout << x;
    
    return 0;
}