// g++ test.cpp -o test && ./test

#include <bits/stdc++.h>
using namespace std;

int tree[100]={-1};

void print(int i){
    if(tree[i] > 0){
        int j = i;
        while(j > 0){
            cout << tree[j] << " ";
            j /= 2;
        }
        cout << endl;
    }
}

void triverse(int i){

    if(tree[2*i] == -1 && tree[2*i+1] == -1) {
        print(i);
    }
    else {
        triverse(2*i);
        triverse(2*i+1);
    }
}

int main(){

    for(int i = 0; i < 100; i++)  tree[i] = -1;
    cout << "Enter tree in bridth first manner (if there is no data enter -1)" << endl;
    for(int i = 1; i < 16; i++) cin >> tree[i];

    triverse(1);
}