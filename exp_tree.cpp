// g++ exp_tree.cpp -o exp_tree && ./exp_tree
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;

bool isOprator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ')' || ch == '(') return true;
    return false;
}

int inPre(char ch){

    if(ch == '+' || ch == '-') return 2;
    if(ch == '*' || ch == '/') return 4;
    if(ch == '(') return 0;
    return 0;
}

int outPre(char ch){

    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 3;
    if(ch == '(') return 5;
    if(ch == ')') return 0;
    return 0;
}

class stk{

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
            return 0;
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
            return s[topi];
        }

        void traverser(){
            for(int i = topi; i >= 0; i--) cout << s[i] << " "; cout << endl; 
        }

};

string postfix(string infix){

    string ans = "";
    stk *op = new stk();
    int len = infix.length();
    int i = 0;

    while(i < len){
        if(isOprator(infix[i])){
            if(op->isEmpty()){
                op->push(infix[i++]);
            } 
            else if(outPre(infix[i]) > inPre(op->top())){
                op->push(infix[i++]);
            } 
            else if(outPre(infix[i]) == inPre(op->top())){
                op->pop(); 
                i++;
            }
            else {
                while(!op->isEmpty() && outPre(infix[i]) < inPre(op->top())){
                    if(op->top() == '('){
                        op->pop();
                    } 
                    else{
                        ans += op->pop();
                    }
                }
                if(infix[i] != ')'){
                    op->push(infix[i++]);
                } 
            }
        }
        else{
            while(i != len && !isOprator(infix[i])){
                ans+= infix[i++]; 
            } 
        }
    }

    while(!op->isEmpty()){
        if(op->top() == '(' || op->top() == ')') op->pop();
        else{ 
            ans += op->pop();
        }
    } 
    return ans;
}

struct node{

    node(char ch){
        data = ch;
        lch = rch = NULL;
    }

    char data;
    node* lch; 
    node* rch;

};

void preOrder(node* root){
    if(root != NULL){
        cout << root->data << " ";
        preOrder(root->lch);
        preOrder(root->rch);
    }
}
void inOrder(node* root){
    if(root != NULL){
        inOrder(root->lch);
        cout << root->data << " ";
        inOrder(root->rch);
    }
}
void postOrder(node* root){
    if(root != NULL){
        postOrder(root->lch);
        postOrder(root->rch);
        cout << root->data << " ";
    }
}

int main(){
    
    string exp;
    cin >> exp;
    exp = postfix(exp);
    stack<node*> st1;
    
    int len = exp.length();
    for(int i = 0; i < len; i++){
        node* temp = new node(exp[i]);
        if(isOprator(exp[i])){
            node* t2 = st1.top(); st1.pop();
            node* t1 = st1.top(); st1.pop();
            temp->lch = t1;
            temp->rch = t2;
            st1.push(temp);
        }
        else{
            st1.push(temp);
        }
    }
    node* root = st1.top();
    cout << "pre order :";
    preOrder(root);
    cout << endl;
    cout << "in order :";
    inOrder(root);
    cout << endl;
    cout << "post order :";
    postOrder(root);
    cout << endl;

}