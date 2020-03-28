/*


*/

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define int long long int
using namespace std;
#define pii pair <int, int>
#define pb push_back
#define deb(x) cout << #x << " " << x << endl
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl
#define Loop(s, e, itr) for (int itr = s; itr < e; itr++)
#define loop(n) for(int i = 0; i < n; i++)
#define vin vector<int>
#define w(t) int tc; cin >> tc; for(int t = 1; t <= tc; t++)
#define vec vector

class fenwich{
    private:
        int parent(int a){
            int b = (~a+1)&a;
            return a-b;    
        }

        int next(int a){
            // int b;
            // b = a;
            // b = !b;
            // b++;
            // b = b&a;
            // b = a+b;
            // return b;
            int b = (~a+1)&a;
            return a+b;
        }
    
        void add_at(int val, int ind){
            tree[++ind] += val;
            ind = next(ind);
            int m = tree.size();
            while(ind < m){
                tree[ind] += val;
                ind = next(ind);
            }
        }


    public:
        vin tree;
        vin arr;
        fenwich(vin arr){
            this->arr = arr;
            int n = arr.size();
            // deb(n);
            tree = vin(n + 1, 0);
            int temp;
            // cout << "lets start" << endl;
            loop(n){
                tree[i+1] += arr[i];
                temp = next(i+1);
                while(temp <= n){
                    // deb2(temp, tree[temp]);
                    tree[temp] += arr[i];
                    // deb(tree[temp]);
                    temp = next(temp);

                }
                // cout << "i = " << i << " done\n";
            }
            // cout << "done" << endl;
            // cout << "tree" << endl;
            // Loop(1, n+1, i) cout << tree[i] << " "; cout << endl;
        }
        
        fenwich(){}

        void update(int val, int ind){
            add_at(val-arr[ind], ind);
        }

        int sum(int a){
            int ans = tree[++a];
            a = parent(a);
            while(a){
                ans += tree[a];
                a = parent(a);
            }
            return ans;
        }

        int sum(int a, int b){
            return sum(b)-sum(a-1);
        }
};


vin tree;

int parent(int a){
    int b = (~a+1)&a;
    return a-b;    
}

int next(int a){
    // int b;
    // b = a;
    // b = !b;
    // deb(b);
    // b++;
    // deb(b);
    // b = b&a;
    // deb(b);
    // b = a+b;
    // deb(b);
    // return b;
    int b = (~a+1)&a;
    return a+b;
}

void create_fenwich(vin arr){
    int n = arr.size();
    tree = vin(n + 1, 0);
    int temp;
    loop(n){
        tree[i+1] = arr[i];
        temp = next(i+1);
        while(temp <= n){
            tree[temp] += arr[i];
            temp = next(temp);
        }
    }
}

void add_at(int val, int ind){
    tree[++ind] += val;
    ind = next(ind);
    int m = tree.size();
    while(ind < m){
        tree[ind] += val;
        ind = next(ind);
    }
}

int sum(int a){
    int ans = tree[++a];
    a = parent(a);
    while(a){
        ans += tree[a];
        a = parent(a);
    }
    return ans;
}

int sum(int a, int b){
    return sum(b)-sum(a-1);
}

int32_t main1(){
    cout << "next" << endl;
    for(int i = 1; i < 10; i++){
        int temp = i;
        while(temp < 11){
            cout << temp << " ";
            temp = next(temp);
        }
        cout << endl;
    }

    cout << "parent" << endl;
    for(int i = 0; i < 10; i++){
        int temp = i;
        while(temp){
            cout << temp << " ";
            temp = parent(temp);
        }
        cout << endl;
    }
}

int32_t main(){
    int n;
    cin >> n;
    vin arr(n);
    for(int i = 0; i < n; i++)    cin >> arr[i];
    fenwich f(arr);

    cout << "parent" << endl;

    for(int i = 0; i < 10; i++){
        int temp = i;
        while(temp){
            cout << temp << " ";
            temp = parent(temp);
        }
        cout << endl;
    }
    for(auto i : f.tree) cout << i << " "; cout << endl << endl;
    Loop(1, n, i) cout << i << " " << f.sum(i) << endl;
}