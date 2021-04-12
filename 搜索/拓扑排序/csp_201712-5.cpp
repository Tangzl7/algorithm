/***************

正解没找到，但能使用拓扑排序的思想骗到60分。
只要知道当前点的最大值，就可以知道该点的所有先祖节点对于该节点的最大值，所以只要
从下往上拓扑排序的方法解决就可以了。

***************/

#include <bits/stdc++.h>
using namespace std;

#define INF 1e18

struct node {
    int num, pre;
    long long v, f, dist;
}a[100005];

long long MOD=1e18;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, son[100005];
        long long value[100005], result=0;
        cin >> n;
        queue<node> q;
        memset(son, 0, sizeof(son));
        memset(value, 0, sizeof(value));
        for (int i=1; i<=n; i++) {
            a[i].num = i;
            cin >> a[i].pre >> a[i].dist >> a[i].v >> a[i].f;
            son[a[i].pre]++;
        }
        for (int i=1; i<=n; i++) {
            if (son[i] == 0) q.push(a[i]);
        }
        while(!q.empty()) {
            node now = q.front(); q.pop();
            int f = now.pre;
            if (f == 0) break;
            long long d = now.dist;
            son[f]--;
            if (son[f] == 0) q.push(a[f]);
            while(f != 0) {
                value[f]=max(value[f], value[now.num]+a[f].v-(a[f].f-d)*(a[f].f-d));
                d += a[f].dist;
                f = a[f].pre;
            }
        }
        for (int i=1; i<=n; i++) result = (result+value[i])%MOD;
        cout << result << endl;
    }
}
