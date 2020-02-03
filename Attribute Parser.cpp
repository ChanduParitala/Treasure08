#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();
    vector<string> tags;
    vector<string> queries;
    for (int i = 0; i < N; ++i) {
        if (i < N/2) {
            string tag;
            getline(cin, tag);
            tags.push_back(tag);
        } else {
            cin.ignore();
        }
    }
    for(int i = 0; i < Q; ++i) {
        string query;
        string attr;
        while(cin.peek() != '~') {getlinecin.ignore();}
        cin.ignore(1);
        getline(cin, attr);
        cout << attr << endl;
        
    }
    return 0;
}
