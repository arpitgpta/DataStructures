#include <bits/stdc++.h>
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

        void traverser(){
            for(int i = topi; i >= 0; i--) cout << s[i] << " "; cout << endl; 
        }

};