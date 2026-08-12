#include "bits/stdc++.h"
using namespace std;
// la sottostringa di indici (i, j] è valida se vale:
// A_j - A_i = B_j - B_i = C_j - C_i
// da cui, con un po di manipolazione algebrica, A_j - B_j = A_i - B_i AND A_j - C_j = A_i - C_i

int fotosintesi (int N, string S) {
    int a = 0, b = 0, c = 0;
    map<pair<int, int>, int> m;
    m[{0, 0}] = -1;
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'A') a++;
        if(S[i] == 'B') b++;
        if(S[i] == 'C') c++; // c++ menzionato
        if(!m.count({a - b, a - c})) m[{a - b, a - c}] = i;
        else ans = max(ans, i - m[{a - b, a - c}]);
    }
    return ans;
}

#ifndef EVAL
int main () {
    string S; cin >> S;
    cout << fotosintesi(S.size(), S) << endl;
}
#endif
