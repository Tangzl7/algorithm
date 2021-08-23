/****************************
 * 两个数a和b互质说明a的所有a的所有因子都不能被b整除
 * 该题直接将a1到an的所有数的因子得到并且因子的整数倍被标记
 * 剩余没有被标记的就是[1, m]中与a1到an互质的数
 * 得到因子的复杂度为O(sqrt(ai))
 * *************************/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a[100005];
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    int vis[100005] = {0};
    set<int> s;
    for (int i=0; i<n; i++) {
        for (int j=2; j*j<=a[i]; j++) {
            if (a[i] % j == 0) {
                while(a[i] % j == 0) a[i] /= j;
                if (s.count(j) == 0) {
                    s.insert(j);
                    for (int k=j; k<=m; k+=j) {
                        vis[k] = 1;
                    }
                }
            }
        }
        if (a[i] != 1) {
            if (s.count(a[i]) == 0) {
                s.insert(a[i]);
                for (int k=a[i]; k<=m; k+=a[i]) vis[k] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i=1; i<=m; i++) {
        if (vis[i] == 0) cnt ++;
    }
    cout << cnt << endl;
    for (int i=1; i<=m; i++)
        if (vis[i] == 0) cout << i << endl;
}