#include <bits/stdc++.h>
using namespace std;
constexpr static int P = 1e6 + 3, mod = 1e9 + 7;

long long mod_pow(long long b, int e){
    long long ans = 1;
    while(e){
        if(e & 1)
            ans = (ans * b) % mod;
        e >>= 1;
        b = (b * b) % mod;
    }
    return ans;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N; cin >> N;
        vector<int> R(N);
        long long pp = mod_pow(P, mod - 2);
        long long target = 0, current;
        for (int i = 0; i < N; ++i){
            cin >> R[i];
            pp *= P; pp %= mod;
            target = (target * P + R[i]) % mod;
        }
        current = target;
        int x = 0;
        for(int i = 0; i < N; i++){
            if(current == target)
                x++;
            current = (current - (pp * R[i]) % mod + mod) % mod;
            current = (current * P + R[i]) % mod;
        }
        cout << "Case #" << test << ": ";
        cout << x << endl;
    }
    return 0;
}

/* Hashing - O(TN^2)
map<long long, int> m;
inline long long hashing(deque<int> &D){
    int N = D.size();
    int h = 0, pp = 1;
    for(int i = 0; i < N; i++){
        pp *= P; pp %= mod;
        h = (h + (long long)(pp * D[i]) % mod) % mod;
    }
    return h;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        deque<int> R(N);
        for (int i = 0; i < N; ++i)
            cin >> R[i];
        deque<int> D = R;
        int target = hashing(R);
        for(int i = 0; i < N; i++){
            D.push_back(D.front());
            D.pop_front();
            m[hashing(D)]++;
        }
        cout << "Case #" << test << ": ";
        cout << m[target] << endl;
    }
    return 0;
} */