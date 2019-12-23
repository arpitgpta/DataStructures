#include<bits/stdc++.>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}nd;

nd* head = NULL;

void insert(int data){
    nd* temp = (nd*)malloc(sizeof(nd));
    
}

int main(){
    int n, temp;
    cout << "How many values u want to insert" << endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Enter value" << endl;
        cin >> temp;
        insert(temp);
    }
}