//Adib Sakhawat - sakhadib
//IUT, 2023

#include <bits/stdc++.h>
using namespace std;

const string nums[10] = {"Zero ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine"};

void spell(int num){
    if(num % 10 == 0){
        return;
    }

    int x = num % 10;
    num = num / 10;
    spell(num);
    cout << nums[x];
    return;

}

int main() {

    spell(2435);
    return 0;
}