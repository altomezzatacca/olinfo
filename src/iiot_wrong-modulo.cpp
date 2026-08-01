#include <bits/stdc++.h>
using namespace std;
// ax % ay = a (x % y)
// -> ax % ay = x % y se e solo se (a = 1) OR (x = ky)
// -> \sum_{k=1}^N \lfloor{N / k}\rfloor
// -> \sum_{h=1}^N d(h)
// -> maybe i already know this problem

long long solve(){
    long long N, a; cin >> N >> a;
    if(a == 1) return N * N;
    long long ans = 0;
    for(long long k = 1; k <= N;){ // ~O(2 * sqrt(N))
        long long v = N / k;
        long long r = N / v;
        ans += v * (r - k + 1);
        k = r + 1;
    }
    return ans;
}

int main(){
    int T; cin >> T;
    while(T--)
        cout << solve() << "\n";
    return 0;
}
