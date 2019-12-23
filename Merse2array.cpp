#include "MakeCodeAwsome.cpp"
#include "ArrayADT.cpp"

int main(){
    Array *a = new Array();
    Array *b = new Array();
    int i, l1, l2, temp;
    write("enter no of elements in first array");
    read(l1);
    write("Enter elements of first array");
    fo(i, l1){
        read(temp);
        a->append(temp);
    } 

    write("enter no of elements in second array");
    read(l2);
    write("Enter elements of second array");
    fo(i, l2){
        read(temp);
        b->append(temp);
    }

    Array *c = new Array();
    int pa = 0, pb = 0, pc = 0;
    while((pa < l1) && (pb < l2)){
        a->get(pa) < b->get(pb) ? c->set(pc++,a->get(pa++)) : c->set(pc++,b->get(pb++));
         
    }
    
    while(pa < l1) c->append(a->get(pa++));
    while(pb < l2) c->append(b->get(pb++));


    write("Mearsed array is");
    c->print();

    return 0; 
}