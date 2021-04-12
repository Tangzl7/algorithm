#include<bits/stdc++.h>
using namespace std;

int spilt(string s) {
    istringstream p(s);
    string t;
    while(p >> t) {
        cout << t << endl;
    }
    return 0;
}

int main() {
    string s;
    getline(cin, s);
    spilt(s);
    return 0;
}