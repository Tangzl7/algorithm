// #include <bits/stdc++.h>
// using namespace std;

// struct node {
//     int time=0;
//     vector<int> neg, link[1005];
// }nodes[505];

// int vis[505]={0};

// void query(int a, int b) {
//     for (int i=0; i<nodes[a].link[b].size(); i++){
//         if (i == 0) printf("%d", nodes[a].link[b][i]);
//         else printf(" %d", nodes[a].link[b][i]);
//     }
//     printf("\n");
// }

// void bfs(int a, int b, int c, int t) {
//     queue<node> q;
//     q.push(nodes[a]);
//     while(!q.empty()) {

//     }
// }

// int main() {
//     int n, m, u, v, t, k;
//     cin >> n >> m;
//     for (int i=0; i<m; i++) {
//         cin >> u >> v;
//         nodes[u].neg.push_back(v);
//         nodes[v].neg.push_back(u);
//     }
//     cin >> t >> k;
//     cin.get();
//     string str;
//     for (int i=0; i<k; i++) {
//         int a, b, c;
//         getline(cin, str);
//         if (str.size()==5) c = str[4]-'0';
//         a = str[0]-'0';
//         b = str[2]-'0';
//         if (str.size() == 3) query(a, b);
//         else bfs(a, b, c, t);
//     }
//     return 0;
// }

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