#include <bits/stdc++.h>
using namespace std;

void fun(long long a){
    for(int i = 0; i < 63; i++){
        long long temp = a;
        long long t2 = pow(2,i);
        if(!(a&t2)) cout << i << endl;
    }
}

int main(){

    long long a = 0;
    // cout << sizeof(a);
    fun(4);

    return 0;
}