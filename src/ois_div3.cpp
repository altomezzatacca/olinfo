#include <bits/stdc++.h>
using namespace std;

string ans(int n, string V1, string V2){
	if((int)V1.size() == n || V1 == "-1"){
		if((int)V2.size() > n - 2 || V2 == "-1") return "-1";
		else return V2;//QUA
	} else {
		if((int)V2.size() > n - 2 || V2 == "-1") return V1;
		else if((int)V1.size() > (int)V2.size()) return V1;
		else if((int)V1.size() < (int)V2.size()) return V2;
		else for(int i = 0; i < (int)V1.size(); i++){
			if(V1[i] > V2[i]) return V1;
			else if (V1[i] < V2[i]) return V2;
		}
	}
	return V1;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int N; cin >> N;
    for (int t = 0; t < N; t++) {
        string V;
        cin >> V;
		long long sum = 0;
		while(V.size() > 0 && V[0] == '0')
			V.erase(0, 1);
		if(V.size() == 0){
			cout << "-1" << endl;
			continue;
		}
		for(int i = 0; i < V.size(); i++)
			sum += (V[i] - '0') % 3;
		if(sum % 3 == 0){
	        cout << V << endl;
		} else {
			sum %= 3;
			string V1 = V, V2 = V;
			int b1 = 0, b2 = 0;
			for(int i = 0; i < V1.size() - 1; i++)
				if(V1[i] % 3 == sum && V1[i] < V1[i + 1]){
					V1.erase(i, 1);
					b1 = 1;
					break;
				}
			if(b1 == 0){
				for(int i = V1.size() - 1; i >= 0; i--)
					if(V1[i] % 3 == sum){
						V1.erase(i, 1);
						break;
					}
			}
			for(int i = 0; i < V2.size() - 1; i++)
				if(V2[i] % 3 == 3 - sum && V2[i] < V2[i + 1]){
					V2.erase(i, 1);
					b2++;
					break;
				}
			for(int i = 0; i < V2.size() - 1; i++)
				if(V2[i] % 3 == 3 - sum && V2[i] < V2[i + 1]){
					V2.erase(i, 1);
					b2++;
					break;
				}
			if(b2 < 2){
				for(int i = V2.size() - 1; i >= 0 && b2 < 2; i--)
					if(V2[i] % 3 == 3 - sum){
						V2.erase(i, 1);
						b2++;
					}
			}
			while(V1.size() > 0 && V1[0] == '0')
				V1.erase(0, 1);
			if(V1.size() == 0) V1 = "-1";
			while(V2.size() > 0 && V2[0] == '0')
				V2.erase(0, 1);
			if(V2.size() == 0) V2 = "-1";
			cout << ans(V.size(), V1, V2) << endl;
		}
    }
    return 0;
}