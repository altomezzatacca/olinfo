#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N, K;
    cin >> N >> K;

    long long risposta = N;

    while(N > 0){
      N /= K;
      risposta += N;
    }

    cout << "Case #" << t << ": " << risposta << endl;
}

int main() {
    freopen("pesci_input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) 
        solve(t);
    
    return 0;
}