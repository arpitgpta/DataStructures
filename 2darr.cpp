#include "G:\ds\MakeCodeAwsome.cpp"


int main(){

    int i1, j1, i2, j2;
    write("Enter dimensions of first matrix");
    read(i1, j1);

    write("Enter dimensions of second matrix");
    read(i2, j2);

    while(1){
        if(j1 !=i2){
            write("invalid dimensions for multiplication, try again");
            write("Enter dimensions of first matrix");
            read(i1, j1);

            write("Enter dimensions of second matrix");
            read(i2, j2);
        } 
        else break;
    }

    int a[i1][j1], b[i2][j2], c[i1][j2];

    for(int i = 0; i < i1; i++){
        for(int j = 0; j < j2; j++){
            c[i][j] = 0;
        }
    }

    write("Enter first array");
    for(int i = 0; i < i1; i++)
        for(int j = 0; j < j1; j++)
            cin >> a[i][j];


    write("Enter second array");
    for(int i = 0; i < i2; i++)
        for(int j = 0; j < j2; j++)
            cin >> b[i][j];




    write("Sum:");

    for(int i = 0; i < i1; i++){
        for(int j = 0; j < j2; j++){
            cout <<a[i][j] + b[i][j] << " ";
        }
        cout << endl;
    }
    write("Substraction:");

    for(int i = 0; i < i1; i++){
        for(int j = 0; j < j2; j++){
            cout <<a[i][j] - b[i][j]<< " ";
        }
        cout << endl;
    }

    for(int i = 0; i < i1; i++){
        for(int j = 0; j < j2; j++){
            for(int k = 0; k < j1; k++){
                c[i][j]+= a[i][k]*b[k][j]; 
            }
        }
    }


    write("Multiplication:");

    for(int i = 0; i < i1; i++){
        for(int j = 0; j < j2; j++){
            cout <<c[i][j] << " ";
        }
        cout << endl;
    }



}
