#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> &a, pair<int,int> &b) {
    if(a.first==b.first) {
        return a.second>b.second;
    } 
    return a.first<b.first;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    int K;
    cin>>K>>N;
    vector<pair<int,int>> V(N);
    for(int i=0;i<N;i++) {
        int a, b;
        cin>>a>>b;
        V[i].first=a;
        V[i].second=b;
    }
    sort(V.begin(), V.end(), comp);
    int ans=1;
    int fine = V[0].second;
    int index=0;
    while(index<N) {  
        if(fine==K-1)
            break;     
        ans++;
        int massimo=V[index].second;
        while(index<N&&V[index].first<=fine+1) {
            massimo=max(V[index].second,massimo);
            index++;
        }
        fine=massimo;
    }
    cout<<ans;
}