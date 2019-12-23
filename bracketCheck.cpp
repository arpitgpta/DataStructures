#include<bits/stdc++.h>
#include<string.h>
using namespace std;


typedef struct node{
    char ch;
    node* link;
}nd;

struct node* head = NULL;

void push(char c){
    nd* temp = (nd*)malloc(sizeof(nd));
    temp->ch = c;
    temp->link = head;
    head = temp;

}

void pop(){
    head = head->link;
}

char top(){
    return head->ch;
}

char comply(char c){
    if(c == '(') return ')';
    if(c == '{') return '}';
    if(c == '[') return ']';
}


int main(){
    char br[100];
    cout << "enter the brackets" << endl;
    gets(br);

    int i = 0;
    push('\0'); 
    while(br[i] != NULL){
        
        if(br[i] == '[' || br[i] == '{' || br[i] == '('){
            push(br[i]);
        }
        else if(comply(top()) == br[i]) pop();
        else if(top() == NULL){
            cout << "pattern of brackets is incorrect" << endl; 
            break;
        }
        else if(comply(top()) != br[i]){
            cout << "pattern of brackets is incorrect" << endl; 
            break;
        }
        i++;
    }
    if(br[i] == NULL && head->ch ==NULL) cout << "correct sequence of brackets" << endl;
    else cout << "pattern of brackets is incorrect" << endl; 
}
