#include <bits/stdc++.h>
using namespace std;

string unescape(int N, string S) {
    string ans;
    string temp;
    int state = 0; // 0 -> ok, 1 -> &, 2 -> &a, 3 -> &am, 4 -> &amp
    for(int i = 0; i < N; i++){
        if(state == 0){
            if(S[i] == '&')
                state = 1;
            ans.push_back(S[i]);
        } else if(state == 1){
            if(S[i] == '&'){
                ans.push_back(S[i]);
            } else if(S[i] == 'a'){
                temp += S[i];
                state = 2;
            } else {
                temp += S[i];
                ans += temp;
                temp = "";
                state = 0;
                if(S[i] == '&') state = 1;
            }
        } else if(state == 2){
            if(S[i] == 'm'){
                temp += S[i];
                state = 3;
            } else {
                temp += S[i];
                ans += temp;
                temp = "";
                state = 0;
                if(S[i] == '&') state = 1;
            }
        } else if(state == 3){
            if(S[i] == 'p'){
                temp += S[i];
                state = 4;
            } else {
                temp += S[i];
                ans += temp;
                temp = "";
                state = 0;
                if(S[i] == '&') state = 1;
            }
        } else{
            if(S[i] == ';'){
                temp = "";
                state = 1;
            } else {
                temp += S[i];
                ans += temp;
                temp = "";
                state = 0;
                if(S[i] == '&') state = 1;
            }
        }
    }
    if(temp != "") ans += temp;
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N; cin >> N;
    string S;
    for(int i = 0; i < N; i++){
        char c;
        cin.get(c);
        S.push_back(c);
    }
    string ans = unescape(N, S);
    cout << (int)ans.size() << " " << ans << "\n";
}