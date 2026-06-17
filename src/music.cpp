#include<bits/stdc++.h>
using namespace std;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    long long N;
    cin >> N;
    vector<long long> C(N);
    for (int i = 0; i < N; ++i)
        cin >> C[i];
    long long U = 0;
    vector<long long> diff1(N + 2), diff2(N + 2);
    // diff1 -> C[i] - C[i + 1]
    // diff2 -> C[i] - C[i + 2]
    // rimuovo l'elemento 0 -> tolgo diff1[0]
    // rimuovo l'elemento i -> tolgo diff1[i - 1] e diff1[i] e aggiungo diff2[i - 1]
    for(int i = 0; i < N - 1; U += diff1[i++])
        diff1[i] = max(0LL, C[i] - C[i + 1]);
    for(int i = 0; i < N - 2; i++)
        diff2[i] = max(0LL, C[i] - C[i + 2]);
    long long max_ix = 0, max_val = diff1[0];
    for(int i = 1; i < N; i++){
        long long val = diff1[i - 1] + diff1[i] - diff2[i - 1];
        if(val > max_val){
            max_val = val;
            max_ix = i;
        }
    }
    long long vv = C[max_ix];
    U -= max_val;
    stack<long long> S;
    while((int)C.size() != max_ix + 1){
        S.push(C.back());
        C.pop_back();
    }
    C.pop_back();
    while(!S.empty()){
        C.push_back(S.top());
        S.pop();
    }
    long long min_val = max(0LL, vv - C[0]);
    for(int i = 0; i < N - 2; i++){
        long long val = max(0LL, C[i] - vv) + max(0LL, vv - C[i + 1]);
        min_val = min(val, min_val);
    }
    min_val = min(min_val, max(0LL, C[N - 2] - vv));
    cout << U + min_val << endl;
    return 0;
}