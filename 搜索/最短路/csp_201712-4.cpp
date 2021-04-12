/***************

单源最短路可解。如果不考虑相交的小路，最直接的dij就能拿60分。
正解：用dist[i]表示到路口i的总疲劳，由于需要考虑大路和小路，大路直接加上该段路的长度即可，
小路需要考虑走到当前路口前面已经连续走过了多少小路，并且前面小路开始的路口，所以使用pre[i]
表示路口i前面的连续小路，如果前面是大路则pre[i]=i，同时使用path[i]表示走到路口i时前面已
经连续走的小路长度。

***************/

#include <bits/stdc++.h>
using namespace std;
using pil = pair<long long, long long>;
#define INF 1e9

struct node {
    int to, t;
    long long c;
};

long long ll=1;
long long dist[505];
long long path[505];
int pre[505];
vector<node> p[505];

void dijstra(int s) {
    dist[s] = 0;
    priority_queue<pil, vector<pil>, greater<pil> > q;
    q.push(pil(0, s));
    while(!q.empty()) {
        pil now = q.top(); q.pop();
        for (int i=0; i<p[now.second].size(); i++) {
            int next = p[now.second][i].to;
            int little = path[now.second];
            int kind = p[now.second][i].t, cost = p[now.second][i].c;
            if (kind == 0) {
                if (dist[next] > dist[now.second] + cost) {
                    dist[next] = dist[now.second] + cost;
                    pre[next] = next; path[next] = 0;
                    q.push(pil(dist[next], next));
                }
            } else if (kind == 1) {
                if (dist[next] > dist[pre[now.second]] + ll*(path[now.second]+cost)*(path[now.second]+cost)) {
                    dist[next] = dist[pre[now.second]] + ll*(path[now.second]+cost)*(path[now.second]+cost);
                    pre[next] = pre[now.second]; path[next] = path[now.second] + cost;
                    q.push(pil(dist[next], next));
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(path, 0, sizeof(path));
    for (int i=0; i<505; i++) {
        dist[i] = INF;
        pre[i] = i;
    }
    int t, a, b; long long c;
    node tmp;
    for (int i=0; i<m; i++) {
        cin >> t >> a >> b >> c;
        tmp.to = b; tmp.t = t; tmp.c = c;
        p[a].push_back(tmp);
        tmp.to = a;
        p[b].push_back(tmp);
    }
    dijstra(1);
    cout << dist[n] << endl;
    return 0;
}