#include<bits/stdc++.h>
using namespace std;

struct node {
    int first;
    double second;
};

bool cmp(node a, node b) {
    return a.first > b.first;
}

int main() {
    int n, m, t, x;
    int max_e1, max_e2;
    map<int, double> a, b, c;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t >> x;
        a[t] = x;
        if (i == 0) max_e1 = t;
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> t >> x;
        b[t] = x;
        if (i == 0) max_e2 = t;
    }
    while (max_e1 >= max_e2) {
        double mult = a[max_e1] / b[max_e2];
        c[max_e1 - max_e2] = mult;
        for (int i=max_e1, j=max_e2; i>=0 && j>=0; i--, j--) {
            a[i] -= b[j]*mult;
        }
        if (fabs(mult) < 0.05) c[max_e1 - max_e2] = 0;
        while(fabs(a[max_e1]) < 0.05 && max_e1 >= max_e2) {
            a[max_e1] = 0;
            max_e1 --;
        }
    }
    int sum1= 0, sum2 = 0;
    node res1[100], res2[100];
    for (auto iter=c.begin(); iter != c.end(); iter++) {
        if (fabs(iter->second) < 0.1 && fabs(iter->second) > 0.05) iter->second = 0.1;
        if (fabs(iter->second) >= 0.1) {
            res1[sum1].first = iter->first;
            res1[sum1].second = iter->second;
            sum1++;
        }
    }
    cout << sum1;
    sort(res1, res1+sum1, cmp);
    if (sum1 == 0) cout << " 0 0.0";
    for (int i=0; i<sum1; i++) printf(" %d %.1lf", res1[i].first, res1[i].second);
    cout << endl;
    for (auto iter=a.begin(); iter != a.end(); iter++) {
        if (fabs(iter->second) < 0.1 && fabs(iter->second) > 0.05) iter->second = 0.1;
        if (fabs(iter->second) >= 0.1) {
            res2[sum2].first = iter->first;
            res2[sum2].second = iter->second;
            sum2++;
        }
    }
    cout << sum2;
    sort(res2, res2+sum2, cmp);
    if (sum2 == 0) cout << " 0 0.0";
    for (int i=0; i<sum2; i++) printf(" %d %.1lf", res2[i].first, res2[i].second);
    cout << endl;
}