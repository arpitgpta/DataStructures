// g++ graph_dsf.cpp -o graph_dsf &&  ./graph_dsf
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;

void explore(int temp, vector<vector<int>> &mtx, vector<int> &visited){

    if(!visited[temp]){
        cout << temp << " ";
        visited[temp] = 1;
        for(int i = 1; i < visited.size(); i++){
            if(mtx[temp][i] > 0 && !visited[i]){
                explore(i, mtx, visited);
            }
        }
    }
}

int main(){

    int n_v;
    cout << "Enter number of virtex" << endl;
    cin >> n_v;
    vector<vector<int>> mtx(n_v+1, vector<int>(n_v+1, 0));

    cout << "Enter adjusent matrix" << endl;

    for(int i = 1; i <= n_v; i++) for(int j = 1; j <= n_v; j++) cin >> mtx[i][j];

    vector<int> visited(n_v+1,0);

    int temp;
    for(temp = 1; temp <= n_v; temp++) if(mtx[1][temp] > 0) break;

    explore(temp, mtx, visited);

    return 0;
}