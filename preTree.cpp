#include "MakeCodeAwsome.cpp"

struct node{

    int data;
    node* left;
    node* right;

};

int main(){

    node *epe = NULL, *ene = NULL, *ope = NULL, *one = NULL;
    node *head;
        node *ebch = NULL, *obch = NULL;

    bool even = false, odd = false, epos = false, opos = false, eneg = false, oneg = false;
    int flag, data;

    node *temp2 = new node();
    temp2->left = NULL;                                  
    temp2->right = NULL;
    temp2->data = 0;
    head = temp2;

    node *temp1 = new node();
    temp1->left = NULL;                                  
    temp1->right = NULL;
    write("Enter 20 numbers");
    read(temp1->data);
    data = temp1->data;
    
    if(data % 2 == 0){
        head->left = temp1;
        even = true;
        if(data > 0){
            epos = true;
            epe = temp1;
        }
        else{
            eneg = true;
            ene = temp1;
        }
    }
    else{
        odd = true;
        head->right = temp1;
        if(data > 0){
            opos = true;
            ope = temp1;
        }
        else{
            oneg = true;
            one = temp1;
        }
    }

    for(int i = 0; i < 11; i++){
        
        node *temp = new node();
        temp->left = NULL;
        temp->right = NULL;
        read(temp->data);
        data = temp->data;

        if(data % 2 == 0){
            if(even){           
                if(data > 0){
                    if(epos){
                        epe->left = temp;
                        epe = temp;
                    }
                    else{
                        epos = true;
                        ene->left = temp;
                        ebch = ene;
                        epe = temp;
                    }
                }
                else{
                    if(eneg){
                        ene->right = temp;
                        ene = temp;
                    }
                    else{
                        eneg = true;
                        epe->right = temp;
                        ebch = epe;
                        ene = temp;
                    }
                }
            }
            else{
                even = true;
                head->left = temp;
                if(data > 0){
                    epe = temp;
                    epos = true;
                }
                else{
                    ene = temp;
                    eneg = true;
                }
            }
        }
        else{
            if(odd){
                if(data > 0){
                    if(opos){
                        ope->left = temp;
                        ope = temp;
                    }
                    else{
                        opos = true;
                        one->left = temp;
                        obch = one;
                        epe = temp;
                    }
                }
                else{
                    if(oneg){
                        one->right = temp;
                        one = temp;
                    }
                    else{
                        oneg = true;
                        ope->right = temp;
                        obch = ope;
                        one = temp;
                    }
                }

            }
            else{
                odd = true;
                head->right = temp;
                if(data > 0){
                    ope = temp;
                    opos = true;
                }
                else{
                    one = temp;
                    oneg = true;
                }
            }
        }
    }

    node *temp = head->left;
    if(temp->data > 0){
        while(temp != NULL){
            write(temp->data);
            temp = temp->left;
        }
        temp = ebch->right;
        while(temp != NULL){
            write(temp->data);
            temp = temp->right;
        }
    }
    else{
        while(temp != NULL){
            write(temp->data);
            temp = temp->right;
        }
        temp = ebch->left;
        while(temp != NULL){
            write(temp->data);
            temp = temp->left;
        }
    }

    temp = head->right;
    if(temp->data > 0){
        while(temp != NULL){
            write(temp->data);
            temp = temp->left;
        }
        temp = obch->right;
        while(temp != NULL){
            write(temp->data);
            temp = temp->right;
        }
    }
    else{
        while(temp != NULL){
            write(temp->data);
            temp = temp->right;
        }
        temp = obch->left;
        while(temp != NULL){
            write(temp->data);
            temp = temp->left;
        }
    }   

   return 0;
}