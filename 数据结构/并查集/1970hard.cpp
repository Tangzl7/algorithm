/******
你能穿过矩阵的最后一天
通过增加一个顶和一个底来确定并查集从上到下是否联通，增加变量的并查集小trick

******/

class Solution {
public:

    // key:x,y  val:info,index
    map<pair<int,int>, pair<int,int> > m;

    int pre[200005];

    int find(int x) {
        if (pre[x] == x) return x;
        return pre[x] = find(pre[x]);
    }

    void join(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        pre[fx] = fy;
    }


    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        for (int i=0; i<200005; i++) pre[i] = i;
        m[pair<int,int>(-5,0)] = pair<int,int>(2,0); // top
        m[pair<int,int>(-5,1)] = pair<int,int>(2,1); // down
        int k=2;
        int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};
        for (int i=cells.size()-1; i>=0; i--) {
            m[pair<int,int>(cells[i][0], cells[i][1])] = pair<int,int>(2,k++);
            if (cells[i][0] == 1) join(0, k-1);
            if (cells[i][0] == row) join(1, k-1);
            for (int j=0; j<4; j++) {
                pair<int,int> neber;
                neber.first = cells[i][0] + dx[j];
                neber.second = cells[i][1] + dy[j];
                if (m[neber].first == 2) join(k-1, m[neber].second);
            }
            if (find(0) == find(1)) return i;
        }
        return 0;
    }
};