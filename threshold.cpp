#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> G(101, 0);
    for(int i = 0; i < N; i++){
      int x; cin >> x; G[x]++;
    }
    for(int i = 100; i > 0; i--){
      cout << G[i] << " ";
      G[i - 1] += G[i];
    }
    cout << G[0];
    return 0;
}