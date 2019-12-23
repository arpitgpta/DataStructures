#include <bits/stdc++.h>
using namespace std;


struct tnode{

    int data;
    tnode *left;
    tnode *right;

};

class Queue{

    private:
        int arr[50];
        


}



int main(){

    tnode *root = NULL;
    int dtemp, h;
    cout << "Enter height of tree" << endl;
    cin >> h;
    cout << "Enter root node" << endl;
    cin >> dtemp;
    tnode *temp = new tnode();
    temp->left = NULL;
    temp->right = NULL;
    temp->data = dtemp;
    root = temp;
    int q;
    for(int i = 1; i < h; i++){
        cout << "Level no.: " << i << endl;
        for(int j = 0; j < pow(2, i-1); j++){
            cout << "Is left element tere??" << endl;
            cin >> q;
            if(q == 0){

            }
            else{
                
            }
            cout << "Is right element tere??" << endl;
            cin >> q;
            if(q == 0){

            }
            else{

            }
        }


    }











    return 0;
}