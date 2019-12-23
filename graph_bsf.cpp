// g++ graph_bsf.cpp -o graph_bsf && ./graph_bsf
// 7
// 0 1 1 1 0 0 0
// 1 0 1 0 0 0 0
// 1 1 0 1 1 0 0
// 1 0 1 0 1 0 0
// 0 0 1 1 0 1 1
// 0 0 0 0 1 0 0
// 0 0 0 0 1 0 0
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;



class Queue{
                
    private:
        int size = 50;
        int f = -1,r = -1;
        int arr[50];

    public:
        void enqueue(int num){
            (f++)%(size-1);
            arr[f] = num;
        }

        int dequeue(){
            if(r == f) cout << "Queue is empty ";
            else{
                (r++)%(size-1);
                int temp = arr[r];
                return temp;
            }
            return INT_MIN;
        }

        int front(){
            if(f != r) return arr[f];
        }

        int rare(){
            if(f != r) return arr[r];
        }

        bool isEmpty(){
            if(f == r) return true;
            else return false;
        }



};



int main(){

    int n_v;
    cout << "Enter number of virtex" << endl;
    cin >> n_v;
    vector<vector<int>> mtx(n_v+1, vector<int>(n_v+1, 0));

    cout << "Enter adjusent matrix" << endl;

    for(int i = 1; i <= n_v; i++) for(int j = 1; j <= n_v; j++) cin >> mtx[i][j];

    vector<int> visited(n_v+1,0);

    Queue *que = new Queue();

    int temp;
    for(temp = 1; temp <= n_v; temp++) if(mtx[1][temp] > 0) break;
    que->enqueue(temp);
    // deb(temp);

    while(!(que->isEmpty())){
        temp = que->dequeue();
        // cout << "taken out " << temp << endl;
        if(!visited[temp])cout << temp << " ";
        visited[temp] = 1;
        // cout << "now exploreing each code of " << temp;
        for(int i = 1; i <= n_v; i++){
            // cout << "for " << temp << " exploreing " << i << endl;
            if(mtx[temp][i] > 0 && !visited[i]){
                // cout << i << " have connection with " << temp << " and not visited" << endl;
                que->enqueue(i); 
                cout << i << " "; 
                visited[i] = 1;
            }
        }
    }
    





}