#include<bits/stdc++.h>
using namespace std;

bool search(int* arr, int &num){
    int high = sizeof(arr)/sizeof(int)-1;
    int low = 0;
    int mid = (high+low)/2;

    while(low <= high){
        if(arr[mid] == num) return 1;
        if(arr[mid] > num) low = mid+1;
        else if(arr[mid] < high) high = mid-1;

        mid = (low+high)/2;
    }
    
    if(low >= high) return 0;

}

int main(){
    int n;
    cout << "Enter the length of array" << endl;
    cin >> n;

    int *arr = (int*)malloc(sizeof(int)*n);
    cout << "Enter the sorted array" << endl;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int temp;
    cout << "Enter value to search" << endl;
    cin >> temp;

    if(search(arr, temp)) cout << "Number found" << endl;
    else cout << "Number not found" << endl;

}