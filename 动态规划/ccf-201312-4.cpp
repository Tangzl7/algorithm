/**************

　　我们把一个数称为有趣的，当且仅当：
　　1. 它的数字只包含0, 1, 2, 3，且这四个数字都出现过至少一次。
　　2. 所有的0都出现在所有的1之前，而所有的2都出现在所有的3之前。
　　3. 最高位数字不为0。
　　因此，符合我们定义的最小的有趣的数是2013。除此以外，4位的有趣的数还有两个：2031和2301。
　　请计算恰好有n位的有趣的数的个数。由于答案可能非常大，只需要输出答案除以1000000007的余数。

0. 只有2
1. 只有2，3
2. 只有0，2
3. 只有1，2
4. 只有0，1，2
5. 只有0，2，3
6. 只有1，2，3
7. 有0，1，2，3

递推关系如代码描述。

dp[i][j]表示当前i位的数，第j种情况，共7种情况，其中两种无用。

**************/

#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n, dp[1005][10];
    cin >> n;
    for (int i=0; i<1005; i++)
        for (int j=0; j<10; j++)
            dp[i][j] = 0;
    for (int i=0; i<n; i++) {
        dp[i+1][0] = 1;
        dp[i+1][1] = i+1 >= 2 ? (dp[i][0] + dp[i][1])%1000000007 : 0;
        dp[i+1][2] = i+1 >= 2 ? (dp[i][0] + dp[i][2]*2)%1000000007 : 0;
        dp[i+1][4] = i+1 >= 3 ? (dp[i][2] + dp[i][4]*2)%1000000007 : 0;
        dp[i+1][5] = i+1 >= 3 ? (dp[i][2] + dp[i][1] + dp[i][5]*2)%1000000007 : 0;
        dp[i+1][7] = i+1 >= 4 ? (dp[i][4] + dp[i][5] + dp[i][7]*2)%1000000007 : 0;
    }
    cout << dp[n][7] << endl;
    return 0;
}