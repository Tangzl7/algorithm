/*******************************
 * 三个解，前两个分组dp超时，最后一个记忆化搜索通过
 * 主要是学习了分组dp
 * dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i-1][j-mat[i][k]] + 1));
 * dp[j] = max(dp[j], dp[j-mat[i][k]] + 1);
 * *****************************/

class Solution {
public:
    int dp[75][4905];

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        for (int i=0; i<75; i++)
            for (int j=0; j<4905; j++)
                dp[i][j] = 0;
        for (int i=0; i<mat.size(); i++) {
            for (int j=1; j<(i+1)*70+1; j++) {
                for (int k=0; k<mat[i].size(); k++) {
                    if (i == 0) {
                        if (j == mat[i][k]) dp[i][j] = 1;
                    } else {
                        if (j >= mat[i][k])
                            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i-1][j-mat[i][k]] + 1));
                        else dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    }
                }
            }
        }
        int result = 1000000000;
        for (int i=1; i<4905; i++) {
            if (dp[mat.size()-1][i] == mat.size()) {
                result = min(result, abs(i - target));
            }
        }
        return result;
    }
};


class Solution {
public:

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int dp[4905];
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<mat.size(); i++) {
            for (int j=(i+1)*70; j>=1; j--) {
                for (int k=0; k<mat[i].size(); k++) {
                    if (i == 0) {
                        if (j == mat[i][k]) dp[j] = 1;
                    }
                    else {
                        if (j >= mat[i][k] && dp[j-mat[i][k]] != 0) 
                            dp[j] = max(dp[j], dp[j-mat[i][k]] + 1);
                    }
                }
            }
        }
        int result = 1000000000;
        for (int i=1; i<4905; i++) {
            if (dp[i] == mat.size()) {
                result = min(result, abs(i - target));
            }
        }
        return result;
    }
};


class Solution {
public:
    int vis[71][4905];
    int result = 10000000000, t;
    vector<vector<int> > v;

    void dfs(int line, int sum) {
        if (vis[line][sum] == 1 || sum - t >= result) return;
        if (line == v.size()) {
            result = min(result, abs(sum - t));
            return;
        }
        for (int i=0; i<v[line].size(); i++) {
            dfs(line+1, sum+v[line][i]);
            vis[line+1][sum+v[line][i]] = 1;
        }
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        v = mat;
        t = target;
        for (int i=0; i<71; i++)
            for (int j=0; j<4905; j++)
                vis[i][j] = 0;
        dfs(0, 0);
        return result;
    }
};