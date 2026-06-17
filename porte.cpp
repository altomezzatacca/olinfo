#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int main (){

    ifstream in("input.txt");
	ofstream out("output.txt");

    int N;
    in>>N;
    
    vector<int> A(N);
    for (int i=0; i<N; i++) in>>A[i];
    
    vector <long long> R(N, 0);
    R[N-1]=1;
    
    for (int i=N-2; i>=0; i--) {
        int j=1;
        while(i+j<N) {
            if ((A[i]+A[i+j])%j==0) R[i]+=R[i+j]%mod;
            j*=2;
        }
    }
    
    out << R[0] % mod;
    
    return 0;
    
}