#include <bits/stdc++.h>
using namespace std;

void send(int num, string source, string via, string distination){
    if (num == 1)
        cout << "Send from " << source << " to " << distination << endl;
    else
    {
        send(num-1, source, distination, via);
        cout << "Send from " << source << " to " << distination << endl;
        send(num-1, via, source, distination);
    }
    
}

int main(){
    send(3, "First", "Second", "Third");
    return 0;
}