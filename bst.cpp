#include <bits/stdc++.h>
#define deb(x) cout << #x << " " << x << endl;
using namespace std;

struct node{

    int num;
    node* lch;
    node* rch;

};

class bst{

    private:
        int varis(node* baap){
            node* temp = baap;
            int rtval;
            if(temp->lch == NULL && temp->rch == NULL) return baap->num;
            else if(temp->lch == NULL){
                temp = temp->rch;
                while(temp->lch != NULL) temp = temp->lch;
                return del(temp->num);
            }
            else{
                temp = baap->lch;
                while(temp->rch != NULL) temp = temp->rch;
                return del(temp->num);
            }
        }

        node* prePtrTo(int num){
            node* temp = root;
            node* t2 = root;
            while(temp->num != num){
                t2 = temp;
                if(num < temp->num){
                    temp = temp->lch;
                }
                else if(num > temp->num){
                    temp = temp->rch;
                }
            }
            return t2;
        }

        node* ptrTo(int num, node* p){
            if(num > p->num) return p->rch;
            else return p->lch;
        }

        
 
    public:

        node* root = NULL;
        void insert(int data){
            node* temp = root;
            node* t2 = root;
            while(temp != NULL){
                if(data < temp->num){
                    t2 = temp;
                    temp = temp->lch;
                }
                else if(data > temp->num){
                    t2 = temp;
                    temp = temp->rch;
                }
                 else{
                    cout << "Sorry!! dublicte element :(" << endl;
                    return;
                }
            }
            node *nt = new node();
            nt->lch = NULL; 
            nt->rch = NULL; 
            nt->num = data;
            if(t2 != NULL){
                if(data > t2->num) t2->rch = nt;
                if(data < t2->num) t2->lch = nt;
            }
            else{
                root = nt;
            }
        }

        void inre(node* root, int num){
            if(root == NULL){
                node *n1 = new node();
                n1->num = num;
                n1->lch = NULL;
                n1->rch = NULL;
                root = n1;
            }

            else{
                if(num > root->num){
                    if(root->rch == NULL){
                        node *n1 = new node();
                        n1->num = num;
                        n1->lch = NULL;
                        n1->rch = NULL;
                        root->rch = n1;
                    }
                    else
                        inre(root->rch, num);
                } 
                else if(num < root->num){
                    if(root->lch == NULL){
                        node *n1 = new node();
                        n1->num = num;
                        n1->lch = NULL;
                        n1->rch = NULL;
                        root->lch = n1;
                    }
                    else    
                        inre(root->rch, num);
                }
            }
        }

        void pre(node* temp){ 
            if(temp != NULL){
                pre(temp->lch);
                if(temp->lch == (root->num)) cout << temp->num << " " << "(root)";
                else cout << temp->num << " ";
                pre(temp->rch);
            }
        }

        int del(int val){
            node *p, *p1;
            if(root->num == val){
                p = root;
                int p2 = varis(p);
                p->num = p2;
            }
            else{    
                p = prePtrTo(val);
                p1 = ptrTo(val,p);
                if(p1->lch == NULL && p1->rch == NULL){
                    if(p->num < val) p->rch = NULL;
                    if(p->num > val) p->lch = NULL;
                }
                else{
                    int p2 = varis(p1);
                    p1->num = p2;
                }
            }
            return val;
        }
        
};

int main(){
    cout << "Enter no of elements" << endl;
    int t, num;
    cin >> t;
    bst *b = new bst();
    while(t){

        cin >> num;
        b->insert(num);
        t--;
    }
    b->pre(b->root);
    int flag = 1;
    while(flag){
        cout << "Enter value to delete" << endl;
        int temp;
        cin >> temp;
        b->del(temp);
        b->pre(b->root);
        if(b->root == NULL) cout << "All deleted " << endl;
        else{    cout << endl << "To delete more enter 1 else 0" << endl;
            cin >> flag;
        }
    }
}