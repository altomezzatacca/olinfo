#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9+7;

int trova(int n){
	if(n < 3) return n;
	long long ans = 4, fact = 1;
	
	for(int i = 2; i <= n - 1; i++){
		fact *= i;
		fact %= mod;
		ans += fact;
		ans %= mod;
	}
	
	return ans;
}