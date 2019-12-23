#include "MakeCodeAwsome.cpp"

typedef struct node{
    int data;
    struct node* link;
}nd;

void insert(nd* &head, nd* &tail, int val){

    nd* temp = (nd*)malloc(sizeof(nd));
    temp->link = NULL;
    temp->data = val;
    if(tail == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->link = temp;
        tail = temp;
    }

}

void print(nd* head){
    nd* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

int main(){
    
    nd* head1 = NULL;
    nd* tail1 = NULL;
    for(int i = 0; i < 14; i += 2) insert(head1, tail1, i);
    
    nd* head2 = NULL;
    nd* tail2 = NULL;
    for(int i = 1; i < 15; i += 2) insert(head2, tail2, i);
    
    nd *t1 = head1, *t2 = head2, *Fhead = NULL, *Ftail = NULL;
    while(t1 != NULL && t2 != NULL){
        if(t1->data < t2->data){
            if(Ftail == NULL){
                Fhead = t1;
                Ftail = t1;
                t1 = t1->link;
            } 
            else{
                Ftail->link = t1;
                Ftail = t1;
                t1 = t1->link;
            }
        }
        else{
            if(Ftail == NULL){
                Fhead = t2;
                Ftail = t2;
                t2 = t2->link;
            } 
            else{
                Ftail->link = t2;
                Ftail = t2;
                t2 = t2->link;
            }
        } 
    }
    while(t1 != NULL){
        Ftail->link = t1;
        Ftail = t1;
        t1 = t1->link;
    }
    while(t2 != NULL){
        Ftail->link = t2;
        Ftail = t2;
        t2 = t2->link;
    }
    print(Fhead);


    return 0;
}