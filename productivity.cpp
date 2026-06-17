#include <bits/stdc++.h>
using namespace std;

// input data
int N, M, E;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N >> M >> E;

    int best = 0;
    for(int i = M; i <= N; i++)
      best = max(best, E % i);

    cout << best << endl; // print the result
    return 0;
}