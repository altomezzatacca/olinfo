#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        long long N; cin >> N;
        int operazioni = 0;
        while(N){
            if(N == 2){
                operazioni++;
                N >>= 1;
            } else if(N & 1){
                operazioni++;
                N++;
            }
            operazioni++;
            N >>= 1;
        }
        cout << "Case #" << test << ": ";
        cout << operazioni - 1 << endl;
    }
    
    return 0;
}