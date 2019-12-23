#include<bits/stdc++.h>
using namespace std;


// int temp = check(sp1[i][0],sp2[j][1],sp3,size3);
int check(int I, int J, int arr[][3], int n){
    for(int i = 1; i < n; i++){
        if((arr[i][0] == I) && (arr[i][1] == J)){
            return i;
        }
    }
    return 0;
}

int main(){
    int n1, m1, n2, m2;
    
    cout << "enter dimensions of first matrix" << endl;
    cin >> m1 >> n1;
    int arr1[m1][n1];
    
    cout << "enter matrix" << endl;
    for(int i = 0; i < m1; i++)
        for(int j = 0; j < n1; j++)
            cin >> arr1[i][j];
    
    cout << "enter dimensions of second matrix" << endl;
    cin >> m2 >> n2;
    int arr2[m2][n2];

    cout << "enter matrix" << endl;
    for(int i = 0; i < m2; i++)
        for(int j = 0; j < n2; j++)
            cin >> arr2[i][j];
    
    int sp1[m1*n1+1][3], size1 = 1;  
    int sp2[m2*n2+1][3], size2 = 1;

    sp1[0][0] = -1; sp1[0][1] = -1; sp1[0][2] = 0; 
    sp2[0][0] = -1; sp2[0][1] = -1; sp2[0][2] = 0; 

    for(int i = 0; i < m1; i++)
        for(int j = 0; j < n1; j++)
            if(arr1[i][j] != 0) sp1[size1][0] = i, sp1[size1][1] = j, sp1[size1++][2] = arr1[i][j];

    cout << "first sparse" << endl;
    for(int i = 1; i < size1; i++) cout << sp1[i][0] << " " << sp1[i][1] << " " << sp1[i][2] << endl; 

    for(int i = 0; i < m2; i++)
        for(int j = 0; j < n2; j++)
            if(arr2[i][j] != 0) sp2[size2][0] = i, sp2[size2][1] = j, sp2[size2++][2] = arr2[i][j];

    cout << "second sparse" << endl;
    for(int i = 1; i < size2; i++) cout << sp2[i][0] << " " << sp2[i][1] << " " << sp2[i][2] << endl; 
    cout << endl;
    int sp3[m1*n2+1][3], size3 = 1;
    sp3[0][0] = -1; sp3[0][1] = -1; sp3[0][2] = 0; 

    for(int i = 1; i < size1; i++)
        for(int j = 1; j < size2; j++){
            if(sp1[i][1] == sp2[j][0]){
                int temp = check(sp1[i][0],sp2[j][1],sp3,size3);
                if(temp != 0){
                    sp3[temp][2] += sp1[i][2]*sp2[j][2];
                }
                else{
                    sp3[size3][0] = sp1[i][0];
                    sp3[size3][1] = sp2[j][1];
                    sp3[size3++][2] = sp1[i][2]*sp2[j][2];
                }
            }
        }

    for(int i = 1; i < size3; i++) cout << sp3[i][0]+1 << " " << sp3[i][1]+1 << " " << sp3[i][2] << endl;

}