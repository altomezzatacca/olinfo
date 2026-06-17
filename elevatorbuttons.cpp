#include <bits/stdc++.h>
using namespace std;

int main() {
    int lo, hi, pos;
    cin >> lo >> hi >> pos;
    string P;
    cin >> P;
    string ans = "";
    for(int i = 0; i < (int)P.size(); i++){
        if(P[i] == 'U')
            pos ++;
        else if (P[i] == 'D')
            pos--;
        else
            pos = 0;
        if(pos > hi || pos < lo){
            ans = "error";
            break;
        }
        if(i == (int)P.size() - 1)
            ans = to_string(pos);
    }
    cout << ans << '\n';
    return 0;
}
