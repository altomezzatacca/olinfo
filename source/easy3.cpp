#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i=0; i<N; i++) cin >> V[i];
    
    sort(V.begin(), V.end());
    
    int e=-1, o=-1, e2=-1, o2=-1;
    bool founde=0, foundo=0, founde2=0, foundo2=0;
    
    for (int i=N-1; i>=0 && !(founde2 || foundo2); i--){
    	if (V[i]%2==0){
    		if (founde){
    			if(!founde2){
    				founde2=true;
    				e2=V[i];
				}
			} else{
				founde=true;
				e=V[i];
			}
		} else{
			if (foundo){
    			if(!foundo2){
    				foundo2=true;
    				o2=V[i];
				}
			} else{
				foundo=true;
				o=V[i];
			}
		}
	}
    
    int se = -1, so = -1;
    
    if(founde2) se = e + e2;
    if(foundo2) so = o + o2;
    
    int r = max (se, so);
    
    cout<<r;
    
	return 0;
}