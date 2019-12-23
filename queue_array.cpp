// g++ queue_array.cpp -o queue_array && ./queue_array



// WRITE COMMENT HERE

/*


*/


#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;
#define ll long long

class queue_array{

    private:
        int size = 50;
        int f = -1,r = -1;
        int arr[50];

    public:
        void enqueue(int num){
            (f++)%(size-1);
            arr[f] = num;
        }

        int dequeue(){
            if(r == f) cout << "Queue is empty ";
            else{
                (r++)%(size-1);
                int temp = arr[r];
                return temp;
            }
            return -1;
        }

        int front(){
            if(f != r) return arr[f];
        }

        int rare(){
            if(f != r) return arr[r];
        }

        bool isEmpty(){
            if(f != r) return false;
            else return true;
        }

};

class queue_ll{

    private:

        struct node {
            int data;
            struct node* next;
        };
        struct node *f = NULL;
        struct node *r = NULL;
    public:
        void enqueue(int num){
            node* temp = new node();
            temp->data = num;
            temp->next = NULL;
            if(f == NULL){
                f = r = temp;
            }
            else{
                r->next = temp;
                r = temp;
            }
        }

        int dequeue(){
            if(f == NULL) cout << "Queue is empty ";
            else{
                int temp = f->data;
                f = f->next;
                return temp;
            }
            return -1;
        }

        int front(){
            if(f != NULL) return f->data;
            else cout << "queue is empty" << endl;
        }

        int rare(){
            if(f != NULL) return r->data;
        }

        bool isEmpty(){
            if(f != NULL) return false;
            else return true;
        }

};

int main(){

    queue_array *qa = new queue_array();
    queue_ll *ql = new queue_ll();
    for(int i = 0; i < 10; i++){
        qa->enqueue(i);
        ql->enqueue(i);
    } 
    cout << "queue array :";
    for(int i = 0; i < 10; i++) cout << qa->dequeue() << " "; cout << endl;
    cout << "queue ll :"; 
    for(int i = 0; i < 10; i++) cout << ql->dequeue() << " ";  cout << endl;
}
