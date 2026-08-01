#include <bits/stdc++.h>
using namespace std;
constexpr static int mod = 1e9 + 7;
// è necessario iterare k da 1 a N, ma mi serve davvero calcolarmi ogni volta C(freq[i], k)?
// posso sfruttare la proprietà C(n, k + 1) = C(n, k) * k / (n - k + 1)

long long fast_exp(long long b, int e){ // O(N)
    if(e == 0 || b == 1) return 1;
    if(e == 1) return b;
    long long c = 1;
    while(e){
        if(e & 1)
            c = (c * b) % mod;
        e >>= 1;
        b = (b * b) % mod;
    }
    return c;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int N;
    cin >> N;
    vector<int> freq;
    map<int, int> M;
    for (int i = 0, x; i < N; i++) { // O(N)
        cin >> x;
        M[x]++;
    }
    auto it = M.begin();
    while(it != M.end()){ // O(N)
        freq.emplace_back(it->second);
        it++;
    }
    sort(begin(freq), end(freq)); // O(N log N)
    long long s = 1; // insieme vuoto
    int F = freq.size();
    vector<long long> next(F, 1); // C(n, 0) = 1
    vector<long long> inv(N + 1); // precalcolo tutti gli inversi per togliere un fattore log N
    for(int i = 0; i <= N; i++) // O(N)
        inv[i] = fast_exp(i, mod - 2); // O(log N)
    int last = 0;
    for(int k = 1; k <= N; k++){ // sottoinsiemi di k elementi; O(N)
        long long x = 1;
        for(int i = last; i < F; i++){ // O(N)
            if(freq[i] < k) {
                last = i;
                continue;
            }
            long long _n = freq[i] - k + 1;
            long long _k = inv[k];
            next[i] = (next[i] * _n) % mod;
            next[i] = (next[i] * _k) % mod;
            x = (x * (1 + next[i])) % mod;
        }
        x--; // tolgo il caso in cui non ho preso alcun elemento
        s = (s + x) % mod;
    }
    cout << s << "\n";
    return 0;
}