#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> bi (10, -1), V(N);
  for(int i = 0; i < N; i++) {
    cout << "? " << i + 1 << " " << i + 1 << "\n";
    cout.flush();
    int x; cin >> x;
    if(bi[x] == -1) bi[x] = i + 1;
  }
  for(int i = 0; i < N; i++){
    int bitmask = 0;
    for(int j = 0; j < 10 && bi[j] != -1; j++){
      cout << "? " << i + 1 << " " << bi[j] << "\n";
      cout.flush();
      int x; cin >> x;
      if (x != -1) bitmask |= 1 << x;
    }
    V[i] = bitmask;
  }

  cout << "! "; // print the result
  for (int i = 0; i < N; i++)
	cout << V[i] << ' ';
  cout << endl;
  return 0;
}