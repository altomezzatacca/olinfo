#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long P[N][2];
    for (int i=0; i<N; i++) cin>>P[i][0]>>P[i][1];
    long long area=0;
    for (int i=0; i<N-1; i++){
        area+=P[i][0]*P[i+1][1]-P[i+1][0]*P[i][1];
    }
    area+=P[N-1][0]*P[0][1]-P[0][0]*P[N-1][1];
    long long r=abs(area)/2;
    cout<<r;
    return 0;
}