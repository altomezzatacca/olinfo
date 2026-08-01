#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        queue<int> A, B;
        for (int i = 0; i < N; ++i){
            int x;
            cin >> x;
            A.emplace(x);
        }
        for (int i = 0; i < N; ++i){
            int x;
            cin >> x;
            B.emplace(x);
        }
        int x = 0;
        while(!A.empty() && !B.empty()){
            int a = A.front(), b = B.front();
            if(a == b){
                A.pop(); B.pop();
                x++;
            } else if(a > b)
                B.pop();
            else
                A.pop(); 
        }
        cout << "Case #" << test << ": ";
        cout << x << endl;
    }

    return 0;
}