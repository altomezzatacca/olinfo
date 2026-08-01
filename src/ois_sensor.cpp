#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int N, i;
int V[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &V[i]));

    int ans = 0;
  for(i = 0; i < N; i++){
    if(V[i] == -1) V[i] = V[i - 1];
    ans += V[i];
  }

    printf("%d\n", ans); // print the result
    return 0;
}
