#include<bits/stdc++.h>
using namespace std;

// #define deb(x) cout << #x << " " << x << endl;

// template<typename... T>
// void read(T&... args){
//     ((cin >> args),...);
// }

// template<typename... T>
// void write(T&&... args){
//     ((cout << args << " "),...);
//     cout << endl;
// }



class Array{
    private:
        int size = 10, length = 0;
        int* arr = new int[10];

        void SizeDoubler(){
            int *temp, *temp1;
                temp = new int[size*2];
                for(int i = 0; i < size; i++) temp[i] = arr[i];
                temp1 = arr;
                arr = temp;
                free(temp1);
                temp = NULL;
                size *= 2;
                
        }

    //append 
    public:
        void append(int num){
            if(length >= size)  SizeDoubler();
            arr[length++] = num;
        }

    //insert
        void insert(int psn, int val){
            while(psn > size-1) SizeDoubler();
            if(length+1 == size) SizeDoubler();
            for(int i = length-1; i >= psn; i--) arr[i+1] = arr[i];
            arr[psn] = val;
            length++; 
        }

    //display
        void print(){
            for(int i = 0; i < length; i++) cout << arr[i] << " ";
            cout << endl;
        }
   
    // delete
        void del(int psn){
            for(int i = psn; i < length-1; i++) arr[i] = arr[i+1]; 
            length--;
        }
    // search
        //linear search
        void search(int val){
            int i;
            for(i = 0; i < length; i++) if(arr[i] == val){ cout << val << " found at " << i << endl; break; }
            if (i == length) cout << val << " not found" << endl;
        }
   
    // get 
        int get(int psn){ return arr[psn];} 

    //set
        void set(int psn, int val){
            while(psn > size)   SizeDoubler();
            arr[psn] = val;
            if(length <= psn) length = psn+1;
            
        }
        
    // max
        int max(){
            int ans = INT_MIN;
            for(int i = 0; i < length; i++) if(arr[i] > ans) ans = arr[i];
            return ans;
        } 
   
    // min 
        int min(){
            int ans = INT_MAX;
            for(int i = 0; i < length; i++) if(arr[i] < ans) ans = arr[i];
            return ans;
        }
   
    // reverse 
        void reverse(){
            for(int i = 0; i <= length/2; i++){
                int temp = arr[i];
                arr[i] = arr[length-1-i];
                arr[length-i-1] = temp;
            }
        }
    //size of array
        int len(){return length;}

    //findMissingin sorted

        int findMissing1();
  
    //findMissingin unsorted
        int findMissing2(int a, int b);

    //pair of sum with k
        void sumK(int k);
};



// int main(){
//     Array *a = new Array();
//     int cs, temp1, temp2;
//         cout << "select a option" << endl;
//         cout << " 1  for append" << endl;
//         cout << " 2  for insert" << endl;
//         cout << " 3  for delete" << endl;
//         cout << " 4  for search" << endl;
//         cout << " 5  for get value at position" << endl;
//         cout << " 6  for set value at position" << endl;
//         cout << " 7  for finding min" << endl;
//         cout << " 8  for finding max" << endl;
//         cout << " 9  for print all" << endl;
//         cout << " 10  for exit" << endl;
//     while(cs != 10){
        
//         cin >> cs;

//         switch(cs){
//             case 1:
//                 cout << "Enter value to append" << endl;
//                 cin >> temp1;
//                 a->append(temp1); 
//                 break;
//             case 2:
//                 write("Enter position and value");
//                 read(temp1, temp2);
//                 a->insert(temp1, temp2);
//                 break;
//             case 3:
//                 write("Enter position to delete");
//                 read(temp1);
//                 a->del(temp1);
//                 break;
//             case 4:
//                 write("Enter value to search");
//                 read(temp1);
//                 a->search(temp1);
//                 break;
//             case 5:
//                 write("Which position do you want to access");
//                 read(temp1);
//                 write(a->get(temp1));
//                 break;
//             case 6:
//                 write("At which position do u want to set value");
//                 read(temp1);
//                 write("Enter the value");
//                 read(temp2);
//                 a->set(temp1, temp2);
//                 break;
//             case 7:
//                 write("Minimun value in array is",a->min());
//                 break;
//             case 8:
//                 write("Maximun value in array is",a->max());
//                 break;
//             case 9:
//                 a->print();
//                 break;
//         }
//     }

//     return 0;
// }