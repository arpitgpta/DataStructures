// g++ tree1.cpp -o tree1 && ./tree1

#include<bits/stdc++.h>
using namespace std;

struct node{
    node* lch;
    int data;
    node* rch;
};

struct Snode{
    node* data;
    Snode* link;
};

class Queue{
    
    private:
        int F = -1, R = -1;
        node* *arr = new node*[50];


    public:

        void enqueue(node* val){
            arr[++F] = val;
            F %= 50;
        }

        node* dequeue(){
            return arr[++R];
            R %= 50;
        }

        bool isEmpty(){
            if(F == R) return true;
            return false;
        }

        node* front(){
            return arr[F];
        }

        node* rare(){
            return arr[(R+1)%50];
        }

};

class Stack{

    private:
        Snode *top = NULL;

    public:
        void push(node* t){
            Snode *temp = new Snode();
            temp->data = t;
            temp->link = top;
            top = temp;
        }

        node* pop(){
            node* temp = top->data;
            top = top->link;
            return temp;
        }

        node* tp(){
            node* temp = top->data;
            return temp;
        }
        
        bool isEmpty(){
            if(top == NULL) return true;
            return false;
        }

};

void pre(node* root){
    cout << root->data << " ";
    if(root->lch != NULL) pre(root->lch);
    if(root->rch != NULL) pre(root->rch);
}

void in(node* root){
    if(root->lch != NULL) in(root->lch);
    cout << root->data << " ";
    if(root->rch != NULL) in(root->rch);
}

void post(node* root){
    if(root->lch != NULL) post(root->lch);
    if(root->rch != NULL) post(root->rch);
    cout << root->data << " ";
}

int main(){
    
    int h;
    cout << "Enter height of the Tree" << endl;
    cin >> h;
    
    Queue *nlist = new Queue();
    int dtemp;
    cout << "Enter root node" << endl;
    cin >> dtemp;
    node *temp = new node();
    node* root = temp;
    temp->data = dtemp;
    temp->lch = NULL;
    temp->rch = NULL;
    nlist->enqueue(temp);


    node *ptr;
    int h1 = 0;
    while(h1 < h){
        cout << "Enter level no.: " << h1+1 << " " << pow(2,h1) << endl; 
        for(int i = 0; i < pow(2,h1); i++){

            ptr = nlist->dequeue();
            
            // left
            temp = new node();
            temp->lch = NULL;
            temp->rch = NULL;
            nlist->enqueue(temp);
            cin >> temp->data;
            ptr->lch = temp;

            // right
            temp = new node();
            temp->lch = NULL;
            temp->rch = NULL;
            nlist->enqueue(temp);
            cin >> temp->data;
            ptr->rch = temp;

        }

        h1++;
    }

    // cout << "pre: " << endl;
    // pre(root);

    // cout << endl << "in: " << endl;
    // in(root);

    // cout << endl << "post: " << endl;
    // post(root);

    // cout << endl << "level: " << endl;
    // Queue *lvl = new Queue();
    // lvl->enqueue(root);
    // while(lvl->rare() != NULL){
    //     temp = lvl->dequeue();
    //     cout << temp->data << " ";
    //     lvl->enqueue(temp->lch);
    //     lvl->enqueue(temp->rch);
    // } 

    cout << endl << "itrative pre:" << endl;
    temp = root;
    Stack *stk = new Stack();
    while(!stk->isEmpty() || temp != NULL){
        if(temp == NULL){
            // if(stk->isEmpty()) break;
            temp = stk->pop();
            temp = temp->rch;
        }
        else{
            cout << temp->data << " ";
            stk->push(temp);
            int x = stk->tp()->data;
            temp = temp->lch;
        }
    }  


    cout << endl << "itrative in:" << endl;
    temp = root;
    stk = new Stack();
    while(!stk->isEmpty() || temp != NULL){
        if(temp == NULL){
            // if(stk->isEmpty()) break;
            temp = stk->pop();
            cout << temp->data << " ";
            temp = temp->rch;
        }
        else{
            stk->push(temp);
            temp = temp->lch;
        }
    }  

}