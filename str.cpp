#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;


void fun(string s, string s1, int sl, int cl, int arr[], long long a){
    if(sl <= cl) cout << s1 << endl;
    else{
        for(int i = 0; i < sl; i++){
            long long a2 = a;
            long long p = pow(2,i);
            a2 = a2 & p;
            if(!a2){
                
                a2= a2|p;

            }
            if(arr[i] == 0){
                int arr2[sl];
                for(int j = 0; j < sl; j++) arr2[j] = arr[j];
                arr2[i] = 1;
                string s2 = s1;
                s2+= s[i]; 
                fun(s,s2,sl,cl+1,arr2,a2); 
            }
        }
    }
}

int main(){
    string s = "ABC";
    string s1 = "";
    long long a = 0;
    int sl = 3, cl = 0;
    int arr[3] = {0};
    fun(s,s1,sl,cl,arr,a);

}