#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> mem;

long long collatz(long long N){
	if (N==1) return 0;
	if (mem.count(N)) return mem[N];
	
	long long passi;
	if (N%2==0) passi = 1 + collatz(N / 2);
	else passi = 1 + collatz(3 * N + 1);
	
	mem[N] = passi;
	
	return passi;
}

int main(){

	ifstream in("input.txt");
	ofstream out("output.txt");
	long long N;
	in >> N;
	out << 1 + collatz(N);
	return 0;
}