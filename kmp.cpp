#include<bits/stdc++.h>

using namespace std;



int* lpsMaker(char patt[], int lps[]){
    
    int i = 1, j, k;

    while(patt[i] != NULL){
        if(patt[i] == patt[0]){
            int p = 0;
            int temp = i;
            while(patt[i+p] == patt[p]){
                lps[temp++] == p++;
            }
        }

    }
    



    return lps;

}

int main(){
    char str[100];
    char patt[100];
    
    cout << "Enter String" << endl;
    gets(str);

    cout << "Enter pattern to search" << endl;
    gets(patt);

    int temp[sizeof(patt)] = {-1};
    int* lps = lpsMaker(patt, temp);

    cout << str << " " << patt;
}