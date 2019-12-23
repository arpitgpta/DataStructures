#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    int less[200];
    int gtr[200];
    int li = 0;
    int hi = 0;
    node* pptr;
    node* lch;
    node* rch;
};

void preOrder(node* root){
    if(root != NULL){
        preOrder(root->lch);
        preOrder(root->rch);
        cout << root->val << " ";
    }
}

void inOrder(node* root){
    if(root != NULL){
        inOrder(root->lch);
        cout << root->val << " ";
        inOrder(root->rch);
    }
}



void insert(int data, node* root){
   if(data > root->val){
        if(root->rch == NULL){
            node* temp = new node();
            temp->pptr = root;
            temp->val = data;
            temp->rch = NULL;
            temp->lch = NULL;
            root->rch = temp;
            int al = 0;
            while(root->gtr[al] != data){
                temp->less[temp->li++] = root->gtr[al++];
            }
            al++;
            while(al < root->hi){
                temp->gtr[temp->hi++] = root->gtr[al++];
            }
        }
        else{
            insert(data,root->rch);
        }
    }
    else if(data < root->val){
        if(root->lch == NULL){
            node* temp = new node();
            temp->pptr = root;
            temp->val = data;
            temp->rch = NULL;
            temp->lch = NULL;
            root->lch = temp;
            int al = 0;
            while(root->less[al] != data){
                temp->less[temp->li++] = root->less[al++];
            }
            al++;
            while(al < root->li){
                temp->gtr[temp->hi++] = root->less[al++];
            }
        }
        else{
            insert(data,root->lch);
        }
    }
}

int main(){
    cout << "Enter no of Elements" << endl;
    int n;
    cin >> n;
    int pre[n];
    int in[n];

    cout << "Enter elements of pre order" << endl;
    for(int i = 0; i < n; i++) cin >> pre[i];

    cout << "Enter elements of in order" << endl;
    for(int i = 0; i < n; i++) cin >> in[i];

    node* root = NULL;
    node* temp = new node();
    temp->val = pre[0];
    temp->pptr = NULL;
    temp->lch = NULL;
    temp->rch = NULL;
    root = temp;
    int al = 0;
    while(pre[0] != in[al]){
        temp->less[temp->li++] = in[al++];
    }
    al++;
    while(al < n){
        temp->gtr[temp->hi++] = in[al++];
    }

    for(int i = 1; i < n; i++) insert(pre[i],root);

    cout << "Post order :" << endl;
    preOrder(root);

    cout << "In order :" << endl;
    inOrder(root);


}