#include "MakeCodeAwsome.cpp"

int Array::findMissing2(int a, int b){
    int i, j, flag;
    Fo(i,a,b){
        flag = 0;
        fo(j, len()){
            if(get(j) == i) flag = 1;
        }
        if(flag == 0) return i;
    }
    return INT_MIN; 
}

void Array::sumK(int k){
    int i = 0, j = 1;
    while(j < len()){
        if()
    }
}

int main(){
    Array *a = new Array();
    int i, temp;
    fo(i,10){
        cin >> temp;
        a->append(temp);
    }

    
    return 0;
}