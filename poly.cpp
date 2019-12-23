#include "MakeCodeAwsome.cpp"

struct pnode{
    int coff, expo;
    pnode* next;

    pnode(int c, int e): coff(c), expo(e) {}
};

void insert(pnode* &head, pnode* &tail, int c, int e){
    pnode *temp = new pnode(c, e);
    if(head == NULL){
        head = tail = temp;
    } 
    else{
        tail->next = temp;
        tail = temp;
    }
}

void print(pnode* head){
    pnode* temp = head;
    while(temp != NULL){
        // deb(head);
        // deb(head->coff);
        // deb(head->expo);
        write(temp->coff,"x^",temp->expo);
        temp = temp->next;
    }
    // write(" now ",head);
}

int main(){

    pnode *pol1 = NULL, *pol2 = NULL, *ans = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
    char ch;
    int a,b = 1;

    cout << "Enter first polynomial";
    while(b != 0){
        read(a,b);
        insert(pol1, t1, a, b);
    }

    cout << "Enter second polynomial";
    b = 1;
    while(b != 0){
        read(a,b);
        insert(pol2, t2, a, b);
    }

    t1 = pol1;
    t2 = pol2;

    do{
        pnode *temp;
        if(t1->expo > t2->expo){
            temp = new pnode(t1->coff, t1->expo);
            t1 = t1->next;
        }
        else if(t1->expo < t2->expo){
            temp = new pnode(t2->coff, t2->expo);
            t2 = t2->next;
        }
        else{
            temp = new pnode(t1->coff+t2->coff, t1->expo);
            t2 = t2->next;
            t1 = t1->next;
        }
        temp->next = NULL;
        if(ans == NULL)
            t3 = ans = temp;
        else{
            t3->next = temp;
            t3 = temp;
        }


    }while(t1 != NULL and t2 != NULL);
    print(ans);
    


}







































// struct pnode{

//     int coff;
//     int expo;
//     pnode* next;

//     pnode(int c, int ex): coff(c), expo(ex), next(NULL) {}

//     void insert(pnode* &head, pnode* &tail, int c, int e){
//         pnode *temp = new pnode(c, e);
//         if(head == NULL){
//             tail = head = temp;
            
//         } 
//         else{
//             tail->next = temp; 
//             tail = temp;
//         }
//     }

// };