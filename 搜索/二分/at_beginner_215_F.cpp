/*********************************
 * The maximization problem of a minimum value can often be solved with a binary search.     ——Editorial
 * 二分答案+滑动窗口
 * 
 * ******************************/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int> > a(n);
    for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int l = 0, r = 1e9 + 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        int ma = -1, mi = 1e9 + 1, flag = 0;
        queue<pair<int,int> > q;
        for (int i=0; i<n; i++) {
            while(!q.empty()) {
                if (q.front().first + mid > a[i].first) break;
                mi = min(mi, q.front().second);
                ma = max(ma, q.front().second);
                q.pop();
            }
            if ((abs(a[i].second - mi) >= mid && mi != 1e9+1) || (abs(ma - a[i].second) >= mid && ma != -1 )) {
                flag = 1;
                break;
            }
            q.push(a[i]);
        }
        if (flag == 1) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << endl;
} 
