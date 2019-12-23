// g++ revN.cpp -o revN && ./revN
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;

    public: 
        node(int d){
            data = d;
            next = NULL;
        }
};

node *start = NULL, *last = NULL;

void insert(int data){
    node* temp = new node(data);
    if(start == NULL)
        start = last = temp;
    else{
        last->next = temp;
        last = temp;
    }
}

void dis(){
    node* temp = start;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}


void rev_helper(node* pre, node* its){
    if(its->next == NULL){
        start = its;
        its->next = pre;
    }
          
    else{
        rev_helper(its, its->next);
        its->next = pre;
    }

}



void revN(int n){

    node *p = start, *q = start, *q_1;
    for(int i = 0; i < n-1; i++) q = q->next;

    q_1 = q->next;
    q->next = NULL;
    rev_helper(NULL,start);
    p->next = q_1;

}


int main(){

    int flag = 1, dtemp;
    cout << "to insert press 1 to revN press 2 to display press 3" << endl;
    do{
        cin >> flag;
        if(flag == 1){
            cin >> dtemp;
            insert(dtemp);
        }
        else if(flag == 2){
            cin >> dtemp;
            revN(dtemp);
        }
        else if(flag == 3) dis();

    }while(flag != 0);


}