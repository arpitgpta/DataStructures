#include<bits/stdc++.h>
#include "ArrayADT.cpp"

using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for(i = 0; i < n; i++)
#define Fo(i, p, q) for(i = p; i < q; i++)

template<typename... T>
void read(T&... args){
    ((cin >> args),...);
}

template<typename... T>
void write(T&&... args){
    ((cout << args << " "),...);
    cout << endl;
}

