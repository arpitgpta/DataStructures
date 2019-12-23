#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int k,high = n-1, low = 0;
    int mid = (high+low)/2;
    cout << "Enter the value to search" << endl;
    cin >> k;
    while(  low <= high ){
        // cout << high << " " << mid  << " " << low << endl;
        if(arr[mid] == k) break;
        if(k > arr[mid] )
            low = mid+1;
        else high = mid-1;

        mid = (high+low)/2;
           
         
    }

    if(arr[mid] == k) cout << "Number found at " << mid << endl;
    else cout << "Number not found" << endl;

}