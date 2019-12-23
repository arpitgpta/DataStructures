// g++ tree23.cpp -o tree23 && ./tree23

#include <bits/stdc++.h>
using namespace std;

class node{



    public:    
        int ld, rd;
        node *pre, *lch, *mch, *rch;
        node(){
            pre = lch = rch = mch = NULL;
            ld = rd = INT_MIN;
        }
        node(int a){
            pre = lch = rch = mch = NULL;
            rd = INT_MIN;
            ld = a;
        }
        node(int a, int b){
            pre = lch = rch = mch = NULL;
            rd = a > b ? a : b;
            ld = a > b ? b : a;

        }

};

class t23{

    private:


        // t23(){
        // }


        // helping functions

        int max3(int a, int b, int c){
            if(a > b && a > c) return a;
            if(b > c && b > a) return b;
            if(c > a && c > b) return c;
            return 0;
        }

        int mid3(int a, int b, int c){
            if((a > b && a < c) || (a < b && a > c)) return a;
            if((b > c && b < a) || (b < c && b > a)) return b;
            if((c > a && c < b) || (c < a && c > b)) return c;
            return 0;
        }

        int min3(int a, int b, int c){
            if(a < b && a < c) return a;
            if(b < c && b < a) return b;
            if(c < a && c < b) return c;
            return 0;
        }

        void arrange(node* temp){
            //to be called in leave only
            int a = temp->ld, b = temp->rd;
            temp->rd = a > b ? a : b;
            temp->ld = a < b ? a : b;
        }


        bool isLeave(node* ptr){
            return ptr->lch == NULL && ptr->mch == NULL && ptr->rch == NULL ? true : false;
        }


        node** fromWhere(node* ptr){
            if(ptr->pre == NULL) return &root;
            if(ptr->ld < ptr->pre->ld) return &ptr->pre->lch;
            if(ptr->ld > ptr->pre->ld && ptr->ld < ptr->pre->rd) return &ptr->pre->mch;
            if(ptr->ld > ptr->pre->rd) return &ptr->pre->rch;
            return NULL;
        }

        bool isRoot(node* ptr){
            return root == ptr ? true : false;
        }

        void backProp(int data, node* ptr){
            if(ptr->rd != INT_MIN){
                if(!isRoot(ptr)){

                }
                else{
                    if(data < ptr->ld){
                        
                        //make pre of all
                        node *ptr_ld = new node(ptr->ld);
                        ptr_ld->lch = ptr;
                        ptr->ld = data;
                        ptr_ld->pre = ptr->pre;

                        node *ptr_rd = new node(ptr->rd);
                        ptr_ld->mch = ptr_rd;
                        ptr->rd = INT_MIN;
                        ptr_rd->lch = ptr->mch;
                        ptr->mch = NULL;
                        ptr_rd->mch = ptr->rch;
                        ptr_rd->pre = ptr_ld;

                        node *ptr_lch2 = new node(ptr->lch->rd);
                        ptr->lch->rd = INT_MIN;

                        ptr->mch = ptr_lch2;

                    }
                    else if(data < ptr->rd){

                    }
                    else{

                    }

                }
            }
            else{
                if(data < ptr->ld){
                    ptr->rch = ptr->mch;
                    ptr->rd = ptr->ld;
                    ptr->ld = data;
                    int temp = ptr->lch->rd;
                    node *n1 = new node(temp); 
                    ptr->lch->rd = INT_MIN;
                    ptr->mch = n1;
                }
                else{
                    ptr->rd = data;
                    node *n1 = new node(ptr->mch->rd);
                    ptr->mch->rd = INT_MIN;
                    ptr->rch = n1;
                }
            }
        }

        void split(node* ptr, int data, node** dad){

            cout << "split is called" << endl;
            
            int a = min3(ptr->ld, ptr->rd, data);
            int b = mid3(ptr->ld, ptr->rd, data);
            int c = max3(ptr->ld, ptr->rd, data);

            if(isRoot(ptr)){

                node *n1 = new node();
                node *n2 = new node();

                n1->ld = b;
                n2->ld = c;
                ptr->ld = a;
                ptr->rd = INT_MIN;
                n1->pre = ptr->pre;
                *dad = n1;
                n1->lch = ptr;
                n1->mch = n2;
                // cout << "n1->ld " << n1->ld << " n1->lch->ld " << n1->lch->ld << " n1->mch->ld " << n1->mch->ld << endl;

            }
            else{
                backProp(data,ptr);
            }

        }

    public:    

        node* root = NULL;

        void insert(int data, node* ptr){
            cout << "insert called" << endl;
            if(ptr == NULL){
                cout << "root case" << endl;
                node* temp = new node(data);
                root = temp;
                cout << "After change root ld = " << root->ld << endl; 
            }
            else if(isLeave(ptr)){
                cout << "leave case " << endl;
                if(ptr->ld == INT_MIN) ptr->ld = data;
                
                else if(ptr->rd == INT_MIN){
                    cout << "ld is full putting in rd" << endl;  
                    ptr->rd = data;
                    arrange(ptr);
                    cout << "ptr->rd = " << ptr->rd << endl;
                }
                else{
                    cout << "leave node is full time to call split" << endl;
                    split(ptr,data,fromWhere(ptr));
                }
            }
            else{
                cout << "came in non leave node" << endl;
                if(data < ptr->ld){
                    insert(data,ptr->lch);
                }
                else if(data > ptr->ld && ptr->rd == INT_MIN){
                    insert(data, ptr->mch);
                }
                else{
                    if(data > ptr->rd){
                        insert(data, ptr->rch);
                    }
                }

            }
        }

        void del(int data,node* ptr){

        }

        void preOrder(node* ptr){

        }

};



int main(){

    t23 *tree = new t23();

    cout << "To insert press 1, to del press 2, to print press 3, to exit press 0" << endl;
    int flag = 4;
    int dtemp;
    do{
        cin >> flag;
        if(flag == 1){
            // cout << "Enter value to insert" << endl;
            cin >> dtemp;      
            tree->insert(dtemp,tree->root);
        } 
        else if(flag == 2){
            // cout << "Enter value to delete" << endl;
            cin >> dtemp;      
            tree->del(dtemp,tree->root);
        }
        else if(flag == 3) tree->preOrder(tree->root);
    }while(flag != 0);    

}