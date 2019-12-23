// 1 10 1 20 1 30 1 25 1 28 1 27 1 5
// g++ practice.cpp -o practice && ./practice

//completed


#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* lch;
    node* rch;
    node* pre;
};

node* root = NULL;

void preOrder(node* ptr){
    if(ptr != NULL){
        cout << ptr->data << " " ; 
        preOrder(ptr->lch);
        preOrder(ptr->rch);
    }
}

void inOrder(node* ptr){
    if(ptr != NULL){
        inOrder(ptr->lch);
        cout << ptr->data << " " ; 
        inOrder(ptr->rch);
    }
}

void ll(node** temp){
    node *A = *temp, *B = (*temp)->lch;
    node *Br = B->rch, *Ar = A->rch;

    A->lch = Br;
    
    B->pre = A->pre;
    A->pre = B;
    B->rch = A;
    if(Br != NULL) Br->pre = A;
    *temp = B;

}

void rr(node** temp){
    node *A = *temp, *B = (*temp)->rch;
    node *Bl = B->lch, *Al = A->lch;

    A->rch = Bl;
    
    B->pre = A->pre;
    A->pre = B;
    B->lch = A;
    if(Bl != NULL) Bl->pre = A;
    *temp = B;

}

void lr(node** temp){

    node* A = *temp;
    node* B = A->lch;
    node *C = B->rch;
    node *Cr = C->rch, *Cl = C->lch;

    *temp = C;
    B->rch = Cl;
    A->lch = Cr;

    C->pre = A->pre;
    C->lch = B;
    C->rch = A;

    B->pre = C;
    A->pre = C;

    if(Cl != NULL) Cl->pre = B;
    if(Cr != NULL) Cr->pre = A;

}

void rl(node** temp){

    node* A = *temp;
    node* B = A->rch;
    node *C = B->lch;
    node *Cr = C->rch, *Cl = C->lch;
    *temp = C;
    B->lch = Cr;
    A->rch = Cl;

    C->pre = A->pre;
    C->lch = A;
    C->rch = B;

    B->pre = C;
    A->pre = C;
    if(Cl != NULL) Cl->pre = A;
    if(Cr != NULL) Cr->pre = B;

}

int height(node* temp){
    if(temp == NULL) return 0;
    int x = height(temp->lch);
    int y = height(temp->rch);
    if(x > y) return x+1;
    else return y+1;
}

int difference(node* temp){
    if(temp == NULL) return 0;
    return height(temp->lch) - height(temp->rch);
}

void update(node* &temp){

    if(temp == NULL) return;

    int diff = difference(temp);
    if(diff == 2){
        if(difference(temp->lch) == 1 || difference(temp->lch) == 0){
            if(temp->pre == NULL) ll(&root);
            else if(temp->data > temp->pre->data) ll(&temp->pre->rch);
            else if(temp->data < temp->pre->data)ll(&temp->pre->lch);
        }
        else if(difference(temp->lch) == -1){
            if(temp->pre == NULL) lr(&root);
            else if(temp->data > temp->pre->data) lr(&temp->pre->rch);
            else lr(&temp->pre->lch);
        } 
    }
    else if(diff == -2){
        if(difference(temp->rch) == 1 ){
            if(temp->pre == NULL) rl(&root);
            else if(temp->pre->data > temp->data) rl(&temp->pre->lch);
            else rl(&temp->pre->rch);
        }
        else if(difference(temp->rch) == -1 || difference(temp->lch) == 0){
            if(temp->pre == NULL) rr(&root);
            else if(temp->data > temp->pre->data) rr(&temp->pre->rch);
            else if(temp->data < temp->pre->data) rr(&temp->pre->lch);
        } 
    }
    if(temp != NULL)    update(temp->pre);   
}

void insert(int data, node* &ptr){

    if(ptr == NULL){
        node *temp = new node();
        temp->data = data;
        temp->lch = NULL;
        temp->rch = NULL;
        temp->pre = ptr;
        ptr = temp;
        // cout << data << " is assigned in"
        update(temp);
    }
    else if(data > ptr->data){
        if(ptr->rch == NULL){
            node *temp = new node();
            temp->data = data;
            temp->lch = NULL;
            temp->rch = NULL;
            temp->pre = ptr;
            ptr->rch = temp;
            update(temp);
        }
        else    insert(data,ptr->rch);
        
    }
    else{
        if(ptr->lch == NULL){
            node *temp = new node();
            temp->data = data;
            temp->lch = NULL;
            temp->rch = NULL;
            temp->pre = ptr;
            ptr->lch = temp;
            update(temp);
        }
        else    insert(data,ptr->lch);
    }

}

void del(int data, node* &ptr);

int son(node* dad){
    node* temp = dad;
    node* t1 = dad;

    if(dad->lch == NULL){
        temp = temp->rch;
        while(temp != NULL){
            t1 = temp;
            temp = temp->lch;
        }
    }   
    else{
        temp = temp->lch;
        while(temp != NULL){
            t1 = temp;
            temp = temp->rch;
        }
    }

    del(t1->data,root);
    return t1->data;


}

void del(int data, node* &ptr){
    node* itr = ptr;
    while(itr != NULL && itr->data != data){
        if(itr->data > data) itr = itr->lch;
        else if(itr->data < data) itr = itr->rch;
    }
    if(itr == NULL){
         cout << "Number not found" << endl;
         return;
    }
    node* temp = itr->pre;
    if(temp == NULL){
        if(itr->rch == NULL && itr->lch == NULL){
            root = NULL;
            return;
        }
        else{
            int x = son(itr);
            itr->data = x;
        }
    }
    else if(data > temp->data){
        
        if(itr->rch == NULL && itr->lch == NULL){
            temp->rch = NULL;
        }
        else{
            int x = son(itr);
            itr->data = x; 
        }
        update(temp);
    }else if(data < temp->data){
        if(itr->rch == NULL && itr->lch == NULL){
            temp->lch = NULL;
        }
        else{
            int x = son(itr);
            itr->data = x;
        }
        update(temp);
    }
}

int main(){
        
    cout << "To insert press 1, to del press 2, to print press 3, to exit press 0" << endl;
    int flag = 4;
    int dtemp;
    do{
        cin >> flag;
        if(flag == 1){
            cout << "Enter value to insert" << endl;
            cin >> dtemp;      
            insert(dtemp,root);
        } 
        else if(flag == 2){
            cout << "Enter value to delete" << endl;
            cin >> dtemp;      
            del(dtemp,root);
        }
        else if(flag == 3) preOrder(root);
    }while(flag != 0);    
            

}