#include<bits/stdc++.h>

using namespace std;


struct node{
    int value;
    struct node* nextNode;
};

typedef struct node nd;

nd* head = NULL;

void addNew(int val){

    nd *n = (nd*) malloc(sizeof(nd));
    n->nextNode = head;
    n->value = val;
    head = n;

}

void displayAll(){

    nd* temp = head;

    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->nextNode;
    }
    cout << endl;

}

int nthNode(int n){

    nd* temp = head;
    for(int i = 0; i < n-1; i++) temp = temp->nextNode;
    return temp->value;

}

void delNth(int n){

    nd* temp = head;
    for (int i = 0; i < n-2; i++) temp = temp->nextNode;
    nd* temp2 = temp->nextNode;
    temp->nextNode = temp2->nextNode;

}


void insertNth(int n, int val){

    nd* ptr = (nd*) malloc(sizeof(nd));
    nd* temp = head;

    for(int i = 0; i < n-2; i++) temp = temp->nextNode;

    ptr->nextNode = temp->nextNode;
    ptr->value = val;
    temp->nextNode = ptr;

}

int printrev(nd* ptr){
    //bsse case
    if(ptr->nextNode == NULL) return ptr->value;

    //recursive case
    // int temp = printrev(ptr->nextNode);
    cout << printrev(ptr->nextNode) << " ";
    return ptr->value; 

}



int main(){
    
    int cs, temp;
    while(cs != 9){

        cout << "Press 1 to add new element\nPress 2 to display all\nPress 3 to find value at a certian node\nPress 4 to delete an element\nPress 5 to insert at nth position\nPress 6 to print in reverse\nPress 9 to Exit" << endl;
        cin >> cs;

        switch(cs){

            case 1:
                cout << "Enter the value to be inserted" << endl;
                cin >> temp;
                addNew(temp);
                break;

            case 2: 
                displayAll();
                break;

            case 3:
                cout << "value of which node do you want to access" << endl;
                cin >> temp;
                cout << nthNode(temp) << endl; 
                break;

            case 4:
                cout << "Which node do you want to delete" << endl;
                cin >> temp;
                delNth(temp);
                break;

            case 5:
                cout << "Enter position" << endl;
                int t2;
                cin >> t2;
                cout << "Enter value" << endl;
                cin >> temp;
                insertNth(t2, temp);
                break;
            case 6:
                cout << printrev(head);
                cout << endl;
                break;

        }
    }
}