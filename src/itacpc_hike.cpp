#include "bits/stdc++.h"
using namespace std;

int main(){
    int N; cin >> N;
    int ans = 3000;
    for(int x; cin >> x && N--; ans+= x);
    cout << ans;
}