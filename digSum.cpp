#include <bits/stdc++.h>
using namespace std;

int main(){

    cout << "enter dimention of matrix" << endl;
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++) arr[i] = vector<int>(n);
    cout << "Enter matrix" << endl;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> arr[i][j];
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        ans1 += arr[i][i];
        ans2 += arr[i][n-i-1];
    }
    cout << "sum of first dignoal = " << ans1 << endl;
    cout << "sum of second dignoal = " << ans2 << endl;


}