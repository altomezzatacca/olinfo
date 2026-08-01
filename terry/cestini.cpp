#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int t) {
    int N, M, Q;
    cin >> N >> M >> Q;

    string S;
    cin >> S;
	
    vector<vector<char>> cestini(M);
    
    for (int i=0; i<N; i++) {
        cestini[0].push_back(S[i]);
    }
	
    string risposta;

    for (int i = 0; i < Q; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == 's') {
            // Aggiungi codice...
 			char oggetto = cestini[a].back();
            cestini[a].pop_back();
            cestini[b].push_back(oggetto);
        } else {
            // Aggiungi altro codice...
            risposta.push_back(cestini[a][b]);
        }
    }


    cout << "Case #" << t << ": " << risposta << endl;
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