// g++ heap.cpp -o heap &&  ./heap
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;

void insert(int data, vector<int> &h, int &last){
    int temp = last;
    while(temp > 1 && h[temp/2] < data){
        h[temp] = h[temp/2];
        temp /= 2;
    }
    h[temp] = data;
    last++;
}



int main(){

    int n;
    cout << "Enter no of nodes" << endl;
    cin >> n;
    vector<int> arr(n+1, 0);
    int temp1, temp2;
    int last = 1;
    for(int i = 0; i < n; i++){
        cin >> temp1;
        insert(temp1, arr, last);
    }
    int lpt = n, temp;
    for(int i = 0; i < n; i++){
        temp = arr[1];
        int ptr = 1;
        while(2*ptr < lpt){

        }
    }

    return 0;
}