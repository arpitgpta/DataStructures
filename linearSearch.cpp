#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << "enter size of array" << endl;
    int t, temp; 
    cin >> t;
    int arr[t];
    for(int i = 0; i < t; i++){
        cin >> temp;
        arr[i] = temp;
    }
    cout << "Enter value to search" << endl;
    cin >> temp;
    int i;
    for(i = 0; i < t; i++) if(arr[i] == temp) cout << "number found" << endl;
    if(i == temp) cout << " Number not found";

}