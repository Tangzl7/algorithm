/*******************

简单BFS题，需要考虑的是新建最多k个中间结点
最开始一直没想通为什么能用BFS做，因为考虑到BFS过程可能把一些新建结点标记为vis了，但此时这条路径新建了多余k个中间结点
此时这条路径无效，又会把一些后面路径会用到的结点标记了。但只要从结点编号小的路径开始搜索，即尽可能先用已有的结点，就不会
存在上面的问题。(另：如果直接用三重循环的最短路，不考虑k个新建结点的条件也能骗80分，dfs暴搜也能骗40分)

*******************/

#include<bits/stdc++.h>
using namespace std;

#define INF 1e9;

int vis[205];
long long n, m, k, r, result=INF;
pair<int, int> p[205];
vector<int> rout[205];

struct node{
    int num;
    int step=0, k=0;
}nodes[205];

int bfs(int s, int e) {
    queue<node> q;
    q.push(nodes[s]);
    vis[s] = 1;
    while(!q.empty()) {
        node now = q.front();
        q.pop();
        if (now.num == 1) return now.step - 1;
        for (int i=0; i<rout[now.num].size(); i++) {
            int next_point = rout[now.num][i];
            int now_num = now.num;
            if (!vis[next_point]) {
                if (next_point >= n) nodes[next_point].k = nodes[now_num].k + 1;
                else nodes[next_point].k = nodes[now_num].k;
                if (nodes[next_point].k > k) continue;
                vis[next_point] = 1;
                nodes[next_point].step = nodes[now_num].step + 1;
                q.push(nodes[next_point]);
            }
        }
    }
    return 0;
}

int main() {
    memset(vis, 0, sizeof(vis));
    cin >> n >> m >> k >> r;
    for (int i=0; i<n; i++) cin >> p[i].first >> p[i].second;
    for (int i=n; i<m+n; i++) cin >> p[i].first >> p[i].second;
    for (int i=0; i<m+n; i++) {
        for (int j=0; j<m+n; j++) {
            nodes[i].num = i;
            long long x1 = p[i].first, x2 = p[j].first;
            long long y1 = p[i].second, y2 = p[j].second;
            if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=r*r && i != j) {
                rout[i].push_back(j);
            }
        }
    }
    result = bfs(0, 1);
    cout << result << endl;
}
