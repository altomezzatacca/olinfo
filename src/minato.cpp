#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, M;
	cin >> N >> M;
	
	char C[N][M];
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> C[i][j];
		}
	}
	int V[N][M];
	memset(V, 0, sizeof V);
	V[0][0]=1;
	for(int i=1; i<N; i++){
		if (C[i][0]=='+') break;
		else V[i][0]=1;
	}
	for(int i=1; i<M; i++){
		if(C[0][i]=='+') break;
		else V[0][i]=1;
	}
	for(int i=1; i<N; i++){
		for(int j=1; j<M; j++){
			if(C[i][j]=='+') continue;
			else V[i][j]=V[i-1][j]+V[i][j-1];
		}
	}
	cout<<V[N-1][M-1];
	
	return 0;
}