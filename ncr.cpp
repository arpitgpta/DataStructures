// ncr 

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;

int ncr(int n, int r){
    int temp = r;
    int ans1 = 1, ans2 = 1;
    while(temp--)    ans1 *= n--;
    while(r > 1) ans2 *= r-- ;
    // deb(ans1);
    // deb(ans2);
    return ans1/ans2; 
}


int main(){
    int n, r;
    cin >> n >> r;
    cout << ncr(n, r);
}