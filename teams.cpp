#include<bits/stdc++.h>
using namespace std;

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int A, B, T = 0;
  cin >> A >> B;
  while(A + B >= 4 && A && B){
    if(!(A ^ B)){
      A -= 2;
      B -= 2;
    } else if (A > B){
      A -= 3;
      B --;
    } else {
      A --;
      B -= 3;
    }
    T++;
  }
  cout << T << "\n";
  return 0;
}