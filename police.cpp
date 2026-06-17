/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;
// constraints
#define MAXN 100000

// input data
int N, K;
int V[MAXN + 1];

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &K));
    for (int i = 1; i <= N; i++) assert(1 == scanf("%d", &V[i]));
    vector<bool> B(N + 1);
    int next = 1, count = 0;
    while(!B[next] && next != K){
        count++;
        B[next] = 1;
        next = V[next];
    }
    cout << (next == K ? count : -1);
    return 0;
}