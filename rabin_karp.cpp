#include<bits/stdc++.h>
#include<string.h>

using namespace std;

long long makeHash(string str,int start, int end){
    //excluding end
    long long ans = 0;

    for(int i = start; i < end; i++) ans = ans*33 + (str[i]-'a'+1);

    return ans;
}

int main(){
    string text;
    string patt ;
    cout << "Enter text" << endl;
    cin >> text;
    cout << "Enter pattern to search" << endl;
    cin >> patt;

    long long hash_patt = makeHash(patt, 0, patt.size());
    int i;
    for(i = 0; i < text.size(); i++){
        long long temp = makeHash(text, i, i+patt.size());
        if(temp == hash_patt){ 
            cout << "match found at position: "  << i << endl;
            break;
        } 
    }

    if(i == text.size()) cout << "Pattern not found" << endl;


}