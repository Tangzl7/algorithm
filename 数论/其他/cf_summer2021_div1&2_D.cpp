/****************************************
 * 
 * a + b = (a & b) + (a | b)
 * 
 * *************************************/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, a[10005];
    cin >> n >> k;
    pair<int, int> first[3];
    for (int i=0; i<3; i++) {
        if (i == 2) {
            cout << "and 1 3" << endl;
            cin >> first[i].first;
            cout << "or 1 3" << endl;
            cin >> first[i].second; 
        } else {
            cout << "and " << i+1 << " " << i+2 << endl;
            cin >> first[i].first;
            cout << "or " << i+1 << " " << i+2 << endl;
            cin >> first[i].second;
        }
        a[i] = first[i].first + first[i].second;
    }
    a[1] = (a[0] + a[1] - a[2]) / 2;
    a[0] = a[0] - a[1];
    a[2] = a[2] - a[0];
    for (int i=3; i<n; i++) {
        int and_, or_, sum;
        cout << "and " << i << " " << i+1 << endl;
        cin >> and_;
        cout << "or " << i << " " << i+1 << endl;
        cin >> or_;
        sum = and_ + or_;
        a[i] = sum - a[i-1];
    }
    sort(a, a+n);
    cout << "finish " << a[k-1] << endl;
}
