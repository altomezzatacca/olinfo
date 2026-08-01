#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    string S;
    cin >> S;

    int K = 0, H = 0, ans = 0;
    for(int i = 0; i < N; i++){
    	switch(S[i]){
    		case 'D':
    			K += 9;
    			break;
    		case 'U':
    			K -= 11;
    			while(K <= 0){
    				if(H < 1){
    					cout << -1;
    					return 0;
					} else{
						H--; ans++;
						K += 10;
					}
				}
    			break;
    		case 'H':
    			if(i == 0) {
    				K+= 10;
    				ans++;
				}
    			else H++;
    			break;
    		case 'B':
    			K += 10;
    			break;
		}
	}
	cout << ans;

    return 0;
}
