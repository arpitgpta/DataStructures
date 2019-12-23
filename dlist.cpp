#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;
struct node{
    node* pre;
    int data;
    node* next;
};

void insert(int data, node* &ptr){
    node* temp = new node();
    if(ptr != NULL) ptr->pre = temp;
    temp->data = data;
    temp->pre = NULL;
    temp->next = ptr;
    ptr = temp;
}

void search(int data,node* root){
    while(root != NULL && root->data != data) root = root->next;
    if(root == NULL ) cout << "Number not found" << endl;
    else cout << "Number Found" << endl;
}

void rev(node**root){
    node* temp = *root;
    while(temp != NULL){
        node *t1, *t2 = temp;
        t1 = t2->pre;
        t2->pre = t2->next;
        t2->next = t1;
        *root = t2;
        temp = temp->pre;
    }
}

void del(int data, node* &ptr){

    node *itr = ptr;
    while(itr->data != data)  itr = itr->next;
    // cout << itr << " " << itr->next << endl;
    if(itr->pre == NULL){
        ptr = ptr->next;
        ptr->pre = NULL;
    }
    else if(itr->next == NULL){
        cout << "here" << endl;
        itr->pre->next = itr->next;
    }
    else{
        itr->pre->next = itr->next;
        itr->next->pre = itr->pre;
    }
    free(itr);
}

void display(node* root){

    while(root != NULL){
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}

int main(){

    node* root = NULL;
    int flag = 1, dtemp;
    while(flag){
        cout << "\nEnter 1 to insert 2 to delete  3 to display  4 to reverse  5 to search  0 to exit \n" << endl;
        cin >> flag;
        switch (flag){
            case 1:
                cout << "Enter data" << endl;
                cin >> dtemp;
                insert(dtemp, root); break;

            case 2:
                cout << "Enter value to delete" << endl;
                cin >> dtemp;
                del(dtemp, root); 
                break;

            case 3: 
                display(root);
                break;

            case 4:
                rev(&root);
                break;

            case 5: 
                cout << "Enter data" << endl;
                cin >> dtemp;
                search(dtemp, root);
                break;
            
        }
    }

    return 0;
}