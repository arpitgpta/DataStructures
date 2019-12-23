#include <bits/stdc++.h>
using namespace std;

struct node{

    int data;
    node* pptr;
    node* lch;
    node* rch;
};

int del(int val, node* &root);

void in(node* root){
    if(root != NULL){
        in(root->lch);
        cout << root->data << " ";
        in(root->rch); 
    }
}

int varis(node* &ptr){
    node* temp;
    if(ptr->lch == NULL){
        temp = ptr->rch;
        while(temp->lch != NULL) temp = temp->lch;
        return del(temp->data,ptr);
    }
    else{
        temp = ptr->lch;
        while(temp->rch != NULL) temp = temp->rch;
        return del(temp->data,ptr);
    }
} 

int del(int val, node* &root){
    node* temp = root;
    while(temp != NULL && temp->data != val){
        if(val > temp->data) temp = temp->rch;
        else if(val < temp->data) temp = temp->lch; 
    }
    if(temp == NULL){
        cout << "Number not found in the tree" << endl;
    }
    else if(temp->lch == NULL && temp->rch == NULL){
        if(temp == root){
            root = NULL;
        }
        else if(temp->pptr->data > temp->data){
            temp->pptr->lch = NULL;
        }
        else if(temp->pptr->data < temp->data){
            temp->pptr->rch = NULL;
        }
    }
    else{
        int v = varis(temp);
        temp->data = v;
    }


    return val;
}

void insert(node* &root, int data){
    if(root == NULL){
            node *temp = new node();
            temp->data = data;
            temp->lch = NULL;
            temp->rch = NULL;
            temp->pptr = NULL;
            root = temp;
    } 
    else if(data > root->data){
        if(root->rch == NULL){
            node *temp = new node();
            temp->data = data;
            temp->lch = NULL;
            temp->rch = NULL;
            temp->pptr = root;
            root->rch = temp;
        }
        else{
            insert(root->rch, data);
        }
    }
    else if(data < root->data){
        if(root->lch == NULL){
            node *temp = new node();
            temp->data = data;
            temp->lch = NULL;
            temp->rch = NULL;
            temp->pptr = root;
            root->lch = temp;
        }
        else{
            insert(root->lch, data);
        }
    }
}

int main(){
    node* root = NULL;
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    cout << "Enter elements" << endl;
    for(int i = 0; i < n; i++){
        int dtemp;
        cin >> dtemp;
        insert(root,dtemp);
    }
    cout << "Given elements are:" << endl;
    in(root);
    int flag = 1;
    cout << endl;
    while(flag){
        cout << "Enter number to delete" << endl;
        int num;
        cin >> num;
        del(num,root);
        in(root);
        if(root == NULL){
            cout << "No more elements avilable" << endl;
            break;
        } 
        else cout << endl << "Do you want to delete more(1/0)" << endl;
        cin >> flag;
    }
}