#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;

class mulStk{

    private:
        
        int size = 10;
        int top1 = -1;
        int top2 = 10;
        int *s = new int[10];

    public:

        void push1(int d){
            if(top1 == top2-1) cout << "no space" << endl;
            else s[++top1] = d;
        }

        void push2(int d){
            if(top1 == top2-1) cout << "no space" << endl;
            else s[--top2] = d;
        }

        int pop1(){
            if(top1 == -1) return INT_MIN;
            else return s[top1--];
        }

        int pop2(){
            if(top1 == size) return INT_MIN;
            else return s[top2++];
        }

        void trv1(){
            int temp = top1;
            while(temp > -1) cout << s[temp--] << " "; cout << endl;
        }

        void trv2(){
            int temp = top2;
            while(temp < size) cout << s[temp++] << " "; cout << endl;
        }

};

int main(){
    
    mulStk *ms = new mulStk();

    cout << "press->> 1 to insert in stk 1, 2 to insert in stk 2; 3 to pop from 1, 4 to pop form 2; 5 to print 1; 6 to print 2 " << endl;
    int flag, dtemp;
    do{
        cin >> flag;
        switch(flag){
            case 1:
                cin >> dtemp;
                ms->push1(dtemp);
                break;
            case 2:
                cin >> dtemp;
                ms->push2(dtemp);
                break;
            case 3:
                dtemp = ms->pop1();
                dtemp == INT_MIN ? cout << "Stack is empty" << endl : cout << dtemp << endl; 
                break;
            case 4:
                dtemp = ms->pop2();
                dtemp == INT_MIN ? cout << "Stack is empty" << endl : cout << dtemp << endl; 
                break;
            case 5:
                ms->trv1();
                break;
            case 6:
                ms->trv2();
        }
    }while(flag != 0);

    return 0;
}