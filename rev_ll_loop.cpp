#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node *link;
}nd;

void insert(nd** head, nd** tail, int value){
    nd* temp = (nd*)malloc(sizeof(nd));
    temp->data = value;     
    temp->link = NULL;
    // cout << "ok" << endl;
    if(*tail == NULL){
        // cout << "tail = " << tail << " temp = " << temp << endl;
        *head = temp;
        *tail = temp;
        // cout << "insetrted in head " << head->data << " tail = " << tail << endl;

    }
    else{
        (*tail)->link = temp;
        *tail = temp;
        cout << "insetrted " << (*tail)->data << endl;
    }
}

void print(nd* head){
    nd* temp = head;
    int i = 0;
    while(temp != NULL){
        cout << temp->data << " " << "temp = " << temp << endl; 
        temp = temp->link;
        i++;
    }
    cout << endl;
}




int main(){
    nd* head = NULL;
    nd* tail = NULL;
    for(int i = 0; i < 10; i++){
        insert(&head, &tail, i);
    } 
    print(head);
    nd *pre = NULL, *curr = head, *next = head->link;
    while(curr->link != NULL){
        curr->link = pre;
        pre = curr;
        curr = next;
        next = next->link;
    }
    curr->link = pre;
    head = curr;
    print(head);
}