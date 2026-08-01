#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    string T = "";
    int pos = 0;
    while(pos < S.size()){
        T.push_back(S[pos]);
        switch(S[pos]){
          case 'a':
            pos += 5;
            break;
          case 'b':
            pos += 5;
            break;
          case 'c':
            pos += 7;
            break;
          case 'd':
            pos += 5;
            break;
          case 'e':
            pos += 4;
            break;
          case 'f':
            pos += 7;
            break;
          case 'g':
            pos += 4;
            break;
          case 'h':
            pos += 5;
            break;
          case 'i':
            pos += 5;
            break;
          case 'j':
            pos += 7;
            break;
          case 'k':
            pos += 4;
            break;
          case 'l':
            pos += 4;
            break;
          case 'm':
            pos += 4;
            break;
          case 'n':
            pos += 8;
            break;
          case 'o':
            pos += 5;
            break;
          case 'p':
            pos += 4;
            break;
          case 'q':
            pos += 6;
            break;
          case 'r':
            pos += 5;
            break;
          case 's':
            pos += 6;
            break;
          case 't':
            pos += 5;
            break;
          case 'u':
            pos += 7;
            break;
          case 'v':
            pos += 6;
            break;
          case 'w':
            pos += 7;
            break;
          case 'x':
            pos += 4;
            break;
          case 'y':
            pos += 6;
            break;
          case 'z':
            pos += 4;
            break;
        }
    }
    cout << T << endl;
    return 0;
}