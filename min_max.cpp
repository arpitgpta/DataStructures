#include "G:\ds\MakeCodeAwsome.cpp"


int main(){
    Array *a = new Array();
    int i, temp, sum = 0;
    fo(i,10){
        read(temp);
        a->append(temp);
    }
    fo(i, 10){
        if((a->get(i)/10)%10 == 5 || (a->get(i)/10)%10 == 0) sum+= a->get(i);
    }
    cout << sum;

}