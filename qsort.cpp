#include "MakeCodeAwsome.cpp"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b - temp;
}

void sort(int arr[], int start, int end){


    int size = end-start+1;
    write(); write();
    deb(size);
    deb(start);
    deb(end);
    // if(size <= 1) return; 
    int gtr[size];
    int lsr[size];
    int i, ls = 0, gs = 0;
    int fi = 0;
    for(i = start; i <= end; i++){
        if(arr[i] >= arr[start]){
            gtr[gs++] = arr[i];
        }
        else{
            lsr[ls++] = arr[i]; 
        }
    }



    if(ls > 1) sort(lsr, 0, ls);
    if(gs > 2) sort(gtr, 1, gs);

    // for(int p = 0; p < ls; p++){
    //     for(int q = 0; q-1 < ls; q++){
    //         if(lsr[q] > lsr[q+1]) swap(lsr[q], lsr[q+1]);    
    //     }
    // }
    // for(int p = 0; p < gs; p++){
    //     for(int q = 0; q < gs - 1; q++){
    //         if(gtr[q] > gtr[q+1]) swap(gtr[q], gtr[q+1]);    
    //     }
    // }

    for(i = 0; i < ls; i++){
        arr[fi] = lsr[i];
        fi++;
    } 
    for(i = 0; i < gs; i++){
        arr[fi] = gtr[i];
        fi++;
    } 
    
}

int main(){

    write("Enter size of array");
    int n;    
    read(n);
    int arr[n];
    write("Enter the array elements");
    int i;
    for(i = 0; i < n; i++) read(arr[i]);
    
    sort(arr, 0, n-1);
    write("final");
    for(i = 0; i < n; i++) write(arr[i]);

    return 0;
}

























