// g++ nCrModM.cpp -o nCrModM && ./nCrModM
// to calculate ncr mod m with little ferment theorem

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define deb(x) cout << #x << " " << x << endl;
#define MOD %1000000007  
#define M 1000000007

vector<ull> fact_mod_m(1e6, 0); // for memorising factorial of all numbers
vector<ull> fact_inverse(1e6, 0); // to memorise ((x!)^(m-2))MOD 

ull fact(ull a){
    ull ans = 1;
    while(a > 1) {
        ans = (ans*a)MOD;
        a--;
    }
    return ans;
}

ull power(ull p, ull q){
    if(q == 0) return 1;
    if(q == 1) return p;
    ull temp = power(p, q/2)MOD;
    if(q&1) return (((temp*temp)MOD)*p)MOD;
    return (temp*temp)MOD;
}

ull ncr(ull n, ull r){

    // ull n_fact = fact(n)MOD;
    // ull nr_fact = fact(n-r)MOD;
    // ull r_fact = fact(r)MOD;
    // ull p1 = power(nr_fact, M-2)MOD;
    // ull p2 = power(r_fact, M-2)MOD;

    return (((fact_mod_m[n]*fact_inverse[r])MOD)*fact_inverse[n-r])MOD;

}

void pre_processing(){
    fact_mod_m[0] = 1;
    for(int i = 1; i < 1e5; i++) fact_mod_m[i] = i*fact_mod_m[i-1];
    for(int i = 1; i < 1e5; i++) fact_inverse[i] = power(fact_mod_m[i], M-2)MOD;
}

int main(){
    
    pre_processing();
    int t;
    // cin >> t;
    // while(t--){
    //     int n, r;
    //     cin >> n >> r;
    //     cout << ncr(n, r) << endl;
    // }
    int flag = 0;
    for(int i = 0; i < 100000; i++){
        ull t1 = ncr(100000, i);
        ull t2 = ncr(100000, 100000-i);
        if(t1 != t2){
            cout << "Error in ncr at i = " << i << endl;
            flag = 1;
        }
    }
    if(flag == 0) cout << "no error occured" << endl;

}