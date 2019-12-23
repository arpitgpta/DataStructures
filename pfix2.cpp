#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;


class stkch{

    private:
        int size = 20, topi = -1;
        char *s = (char*)malloc(sizeof(char)*size);

        void sizeDoubler(){
            char *temp = (char*)malloc(sizeof(char)*size*2);
            for(int i = 0; i < size; i++) temp[i] = s[i];
            char *temp2 = s;
            s = temp;
            free(temp2);
            size*=2;
        }

    public:

        char pop(){
            if(topi < 0){
                cout << "Stack is Empty" << endl;
            }
            else{
                return s[topi--];
            }
        }

        void push(char d){
            while(size <= topi) sizeDoubler();
            s[++topi] = d;
        }

        bool isEmpty(){
            if(topi <= -1) return 1;
            return 0;
        }

        char top(){
            if(topi == -1) return NULL;
            return s[topi];
        }

};

class stkin{

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

int isOprator(char ch){
    if(ch == '/' || ch == '*' || ch == '-' || ch == '+' || ch == '%' || ch == '^' || ch == '(' || ch == ')') return 1;
    return 0;
}

int preout(char ch){

    if(ch == '-' || ch == '+') return 1;
    if(ch == '*' || ch == '/') return 3;
    if(ch == '%') return 5;
    if(ch == '(') return 9;
    if(ch == ')') return 0;
    if(ch == '^') return 8;
    return 0;
}

int prein(char ch){

    if(ch == '-' || ch == '+') return 2;
    if(ch == '*' || ch == '/') return 4;
    if(ch == '%') return 6;
    if(ch == '(') return 0;
    if(ch == '^') return 7;
    return 0;
}

int cal(int a, int b, char ch){
    if(ch == '+') return a+b;
    if(ch == '-') return a-b;
    if(ch == '*') return a*b;
    if(ch == '/') return a/b;
    return 0;
}


int main(){

    stkch *op = new stkch();
    stkin *nums = new stkin();

    string exp;
    cout << "Enter Expression" << endl;
    cin >> exp;

    int i = 0;
    int p = 0;
    while(exp[i] != NULL && p < 200){
        if(isOprator(exp[i]) && p < 200){
            if(prein(op->top()) > preout(exp[i])){
                int t2 = nums->pop();
                int t1 = nums->pop();
                int t3 = cal(t1,t2,op->pop());
                nums->push(t3);
            }
            else if(prein(op->top()) == preout(exp[i])){
                op->pop();
                i++;
            }
            else{
                op->push(exp[i++]);                
            } p++;
        }
        else{
            int temp = 0;
            while(!isOprator(exp[i]) && exp[i] != NULL && p < 200){
                temp = temp*10 + (exp[i++] - '0');
            }
            nums->push(temp);
        }
    }
    while(!(op->isEmpty())){
        int t2 = nums->pop();
        int t1 = nums->pop();
        int t3 = cal(t1,t2,op->pop());
        nums->push(t3);
    }
    cout << nums->top();

}