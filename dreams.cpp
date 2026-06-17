#include <bits/stdc++.h>
using namespace std;

int makepal(int half, bool odd) {
    string s1 = to_string(half);
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    if (odd) s2.erase(0, 1);
    return stoi(s1 + s2);
}

int pal(int n) {
    if (n <= 0) return 0;
    string s = to_string(n);
    int len = s.size(), ans = 0;
    for (int l = 1; l < len; l++) 
        ans += 9 * pow(10, (l - 1) / 2);
    int half = stoi(s.substr(0, (len + 1) / 2));
    for (int i = pow(10, (len - 1) / 2); i < half; i++) ans++;
    if (makepal(half, len % 2) <= n) ans++;
    return ans;
}

int main() {
    int N; cin >> N;
    while (N--) {
        int A, B; cin >> A >> B;
        cout << pal(B) - pal(A - 1) << "\n";
    }
}