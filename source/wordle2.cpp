#include <bits/stdc++.h>
using namespace std;
//W: assente, Y: in posizione sbagliata, G: corretto
string answer = "-----";
multiset<char> S;
vector<int> times(26, 0);

void guess(string g){
    string response;
    cout << "? " << g << endl;
    cin >> response;
    for(int i = 0; i < 5; i++){
        if(response[i] == 'G') answer[i] = g[i];
        if(response[i] != 'W') times[g[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        int temp = times[i] - S.count(i + 'a');
        while(temp-- > 0) S.insert(i + 'a');
        times[i] = 0;
    }
}

void solve(){
    guess("abcde");
    guess("fghij");
    guess("klmno");
    guess("pqrst");
    guess("uvwxy");
    set<char> s;
    for(auto u: S) s.insert(u);
    if(s.size() < 5) s.insert('z');
    vector<char> v;
    for(auto u: s) v.emplace_back(u);
    for(int i = 0; i < (int)v.size() - 1; i++){
        if(answer.find("-") == string::npos) break;
        guess(string(5, v[i]));
    }
    for(int i = 0; i < 5; i++)
        if(answer[i] == '-') answer[i] = v[(int)v.size() - 1];
    cout << "! " << answer << endl;
    answer = "-----";
    S.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) 
        solve();
    return 0;
}