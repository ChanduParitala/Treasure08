#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int absDiagonals(vector < vector<int> > mat) {
    int n = 3;
    cout << "n: " << 3;
    int primaryDiag, secondaryDiag = 0;
    for(int i = 0; i < n; i++) {
        primaryDiag += mat[i][i];
        secondaryDiag += mat[n - 1 - i][i];
    }
    return abs(primaryDiag - secondaryDiag);
}


int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    cout << absDiagonals(a);
    return 0;
}
