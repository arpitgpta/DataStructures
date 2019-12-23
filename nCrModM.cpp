// g++ nCrModM.cpp -o nCrModM && ./nCrModM
// to calculate ncr mod m with little ferment theorem

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define deb(x) cout << #x << " " << x << endl;

ull fact(ull a, int m){
    ull ans = 1;
    while(a > 1) {
        ans = (ans*a)%m;
        a--;
    }
    return ans;
}

ull power(ull p, ull q, int m){
    if(q == 0) return 1;
    if(q == 1) return p;
    ull temp = power(p, q/2, m)%m;
    if(q&1) return (((temp*temp)%m)*p)%m;
    return (temp*temp)%m;
}

ull ncr(ull n, ull r, ull m){

    ull n_fact = fact(n, m)%m;
    ull nr_fact = fact(n-r, m)%m;
    ull r_fact = fact(r, m)%m;
    ull p1 = power(nr_fact, m-2, m)%m;
    ull p2 = power(r_fact, m-2, m)%m;

    return (((n_fact*p1)%m)*p2)%m;
}

int main(){
    
    int n, r, m;
    cin >> n >> r >> m;
    cout << ncr(n, r, m) << endl;

}