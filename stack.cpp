#include<bits/stdc++.h>

using namespace std;


class stk{

    private:
        int size = 20, topi = -1;
        int *s = (int*)malloc(sizeof(int)*size);

        void sizeDoubler(){
            int *temp = (int*)malloc(sizeof(int)*size*2);
            for(int i = 0; i < size; i++) temp[i] = s[i];
            int *temp2 = s;
            s = temp;
            free(temp2);
            size*=2;
        }

    public:

        int pop(){
            if(topi < 0){
                cout << "Stack is Empty" << endl;
            }
            else{
                return s[topi--];
            }
        }

        void push(int d){
            while(size <= topi) sizeDoubler();
            s[++topi] = d;
        }

        bool isEmpty(){
            if(topi <= -1) return 1;
            return 0;
        }

        int top(){
            return s[topi];
        }

};
int main(){
    stk *s1 = new stk();
    s1->push(5);
    s1->push(50);
    s1->push(500);
    s1->push(5000);
    cout << s1->top() << endl;
    for(int i = 0; i < 4; i++) cout << s1->pop() << " " ;
    cout << endl << s1->isEmpty();
}