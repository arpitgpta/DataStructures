#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;
#define deb(x,y) cout << #x << " " << x << endl << #y << " " << y << endl;

class Queue{
// error squiggles
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



int main(){

    Queue *q = new Queue(); 
    for(int i = 0; i < 10; i++) q->enqueue(i);
   n it a = 
    // for(int i = 0; i < 10; i++) deb(q->dequeue(); 

}