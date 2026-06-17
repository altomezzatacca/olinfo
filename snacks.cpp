#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, X;
    cin >> N >> X;

    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    sort(L.rbegin(), L.rend());
	int ans=0;
	while(!L.empty()){
		int n=L.size();
		if(n>=2 && L[n-1]+L[n-2]<=X) L.pop_back();
		ans++;
		L.pop_back();
	}    

    // insert your code here

    cout << ans << endl; // print the result
    return 0;
}
