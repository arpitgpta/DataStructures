// g++ trie.cpp -o trie && ./trie

#include <bits/stdc++.h>
using namespace std;

struct node{
    int count = 0;
    vector<node*> arr;
    node* pre = NULL;
    node() : arr(26, NULL){}
};

node* head = new node();
void insert(string s){
    node* temp = head; 
    int i = 0;
    while(s[i] != NULL){
        if(temp->arr[s[i]-'a'] == NULL){

            node* t1 = new node();
            temp->arr[s[i]-'a'] = t1;
            t1->pre = temp;
            temp = t1;
            i++;
        }
        else{
            temp = temp->arr[s[i]-'a'];
            i++;
        } 
    }
    (temp->count)++;
}

bool search(string s){

    int i = 0; 
    node* temp = head;
    while(s[i] != NULL){
        if(temp == NULL) return false;
        temp = temp->arr[s[i]-'a'];
        i++;
    }

    cout << temp->count << " times" << endl;
    return true;
}


int main(){

    int flag = 0;
    do{
        cin >> flag;
        string s;
        if(flag == 1){
            cin >> s;
            insert(s);
        }
        else if(flag == 2){
            cin >> s;
            search(s);
        }
        else if(flag = 3){
            cin >> s;
        }
    }while(flag != 0);

}

