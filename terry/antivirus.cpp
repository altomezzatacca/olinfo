// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N1, N2, N3, N4;
        cin >> N1 >> N2 >> N3 >> N4; //lunghezza file

        int M;
        cin >> M;

        string F1; //contenuto file
        cin >> F1;

        string F2;
        cin >> F2;

        string F3;
        cin >> F3;

        string F4;
        cin >> F4;

        int p1 = 0, p2 = 0, p3 = 0, p4 = 0;

        // INSERISCI IL TUO CODICE QUI
        
        bool virus_bool=0;
        
		for(int i=0; i<=N1-M && !virus_bool; i++){
			for(int j=0; j<=N2-M && !virus_bool; j++){
				for(int k=0; k<=N3-M && !virus_bool; k++){
					for(int l=0; l<=N4-M && !virus_bool; l++){
						string virus=F1.substr(i, M); 
						string v2=F2.substr(j, M); 
						string v3=F3.substr(k, M); 
						string v4=F4.substr(l, M); 
						if(virus==v2 && v2==v3 && v3==v4){
						p1=i;
						p2=j;
						p3=k;
						p4=l;
						virus_bool=1;
						}
					}
				}
			}
		}

        cout << "Case #" << test << ": ";
        cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
    }

    return 0;
}