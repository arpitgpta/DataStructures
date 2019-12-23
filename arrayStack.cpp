#include<bits/stdc++.h>

using namespace std;

// Stack implementation using array
int t = -1;
int* arr = (int*) malloc(sizeof(int)*1024);
    

void push(int val){
    arr[++t] = val;
}

void pop(){
    arr[t--] = 0;
}

int top(){
    return arr[t];
}

int size(){
    return t+1;
}

bool isEmpty(){
    return t == (-1);
}

void printAll(){
    for(int i = t; i >= 0; i--) cout << arr[i] << " ";
    cout << endl;
}

int main(){

    int  cs = 0;
    while(cs != 9){
        int temp, cs;
        cout << "Enter your choice\n1.push\n2.pop\n3.top\n4.size\n5.isEmpty\n6.printASll\n9.Exit" << endl;
        cin >> cs;

        switch(cs){
            
            case 1: 
                cout << "enter value" << endl;
                cin >> temp;
                push(temp);
                break;
            
            case 2:
                pop();
                cout << "done" << endl;
                break;

            case 3:
                cout << "Top value is: " << top() << endl;
                break;

            case 4:
                cout << "Size of the stack is: " << size() << endl;
                break;

            case 5:
                if(isEmpty()) cout << "Stack is empty" << endl;
                else cout << "Stack is not empty" << endl;
                break;

            case 6:
                printAll();
                break;


        }


    }

}