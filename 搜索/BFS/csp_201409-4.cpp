/*************

最开始看到这个题，多个出发点到多个配送点，考虑是用三重循环的多源最短路，但由于n*n的网格，
每个格子需要转化为一个节点，则达到10^6个节点，二维数组直接爆炸。只能拿30分。
然后看题解说用bfs，我用bfs得到每个节点到配送点的最短距离，然后取每个节点到配送点的最小值，
但是有10^6个餐厅，需要10^6次bfs，显然是错的。拿到40分。
最后看题解bfs具体写法，发现是bfs开始直接把所有餐厅push进队列，这样每次找到配送点，可以
直接计算这个配送的的花费，并且只需要一次bfs。拿到100分。

*************/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

struct node {
    int x, y, step=0;
};

int n, m, k, d;
long long result=0;
int vis[1005][1005];
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, 1, -1};
vector<node> s, obs;
set<pair<int, int> > cnt;
map<pair<int, int>, long long> w;

void bfs() {
    int sum=0;
    queue<node> q;
    for (int i=0; i<s.size(); i++) q.push(s[i]);
    while(!q.empty()) {
        node now = q.front(); q.pop();
        if (cnt.count(pair<int,int>(now.x, now.y))) {
            result += w[pair<int,int>(now.x, now.y)] * now.step;
            if (++sum == k) return;
        }
        for (int i=0; i<4; i++) {
            node tmp = now;
            tmp.x += dx[i]; tmp.y += dy[i];
            if (tmp.x>0&&tmp.x<=n&&tmp.y>0&&tmp.y<=n && vis[tmp.x][tmp.y]==0) {
                vis[tmp.x][tmp.y] = 1;
                tmp.step = now.step + 1;
                q.push(tmp);
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d",&n,&m,&k,&d);
    int x, y; long long c;
    node tmp;
    for (int i=0; i<1005; i++)
        for (int j=0; j<1005; j++)
            vis[i][j] = 0;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        tmp.x = x; tmp.y = y;
        s.push_back(tmp);
        vis[x][y] = 1;
    }
    for (int i=0; i<k; i++) {
        scanf("%d %d %lld", &x, &y, &c);
        w[pair<int, int>(x, y)] += c;
        cnt.insert(pair<int, int>(x, y));
    }
    for (int i=0; i<d; i++) {
        scanf("%d %d", &x, &y);
        tmp.x = x; tmp.y = y;
        obs.push_back(tmp);
        vis[x][y] = 1;
    }
    bfs();
    cout << result << endl;
    return 0;
}