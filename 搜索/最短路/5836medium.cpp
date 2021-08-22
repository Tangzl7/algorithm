/***************

dijstra算法，为了记录路径条数，用一个数组nums[i]表示到第i个结点最短路径的条数，当找到i的一个新的最短路径时，则nums[i]为到i的前一个结点的路径条数
如果找打的路径长度和已经找到的最短路长度相同则nums[i]加上到i节点的前一个节点的路径条数。

但是为什么需要下面这个判断还没搞清楚。
if (now.first > dist[now.second]) continue;

***************/

using pil = pair<long long, long long>;
#define INF 1e9

struct node {
    int to;
    long long time;
    node(int to_, long long time_) : to(to_), time(time_) {}
};

class Solution {
public:
    int cnt;
    vector<node> p[205];
    long long dist[205];
    long long nums[205];
    void dijstra(int s) {
        dist[s] = 0;
        nums[0] = 1;
        priority_queue<pil, vector<pil>, greater<pil> > q;
        q.push(pil(0, s));
        while(!q.empty()) {
            pil now = q.top(); q.pop();
            if (now.first > dist[now.second]) continue;
            long long d = now.first, point = now.second;
            for (int i=0; i<p[point].size(); i++) {
                node next = p[point][i];
                if (dist[next.to] > dist[point] + next.time) {
                    dist[next.to] = dist[point] + next.time;
                    q.push(pil(dist[next.to], next.to));
                    nums[next.to] = nums[point];
                } else if (dist[next.to] == dist[point] + next.time) {
                    nums[next.to] = (nums[next.to] + nums[point])%1000000007;
                }
            }
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        cnt = n;
        memset(nums, 0, sizeof(nums));
        for (int i=0; i<205; i++) dist[i] = 9223372036854775800;
        for (int i=0; i<roads.size(); i++) {
            int from = roads[i][0], to = roads[i][1];
            long long time = roads[i][2];
            p[from].push_back(node(to, time));
            p[to].push_back(node(from, time));
        }
        dijstra(0);
        return nums[n-1];
    }
};