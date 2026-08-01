#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

void solve(int t) {
    int N, K, risposta = 0;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    // aggiungi codice...
    
    sort(C.begin(), C.end());
    
    if(N==K){
    	risposta=0;
	}
	
	vector<int> diff(N-1);
	for (int i=0; i<N-1; i++){
		diff[i]= C[i+1]-C[i];
	}
	sort(diff.begin(), diff.end());
	reverse(diff.begin(), diff.end());
	
	risposta=C[N-1]-C[0];
	
    for(int i=0;i<K-1;i++){
        risposta-=diff[i];
    }
	
    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}