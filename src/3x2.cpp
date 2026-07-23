#include <bits/stdc++.h>
using namespace std;

// input data
int N;
vector<int> P;

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    cin >> N;
    P.resize(N);
    for(int i = 0; i < N; i++)
        cin >> P[i];
    sort(rbegin(P), rend(P));
    int tot = 0;
    for(int i = 0; i < N; i++){
      if(i % 3 == 2) continue;
      tot += P[i];
    }
    cout << tot << endl; // print the result
    return 0;
}
