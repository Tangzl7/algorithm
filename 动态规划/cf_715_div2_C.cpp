#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, s[2005], re=INF;
long long dp[2005][2005];
 
int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> s[i];
    for (int i=0; i<2005; i++)
        for (int j=0; j<2005; j++)
            dp[i][j] = 0;
    sort(s, s+n);
    for (int l=1; l<=n; l++) {
        for (int j=0; j<n; j++) {
            if (j+l >= n) break;
            dp[j][j+l] = min(s[j+l]-s[j]+dp[j+1][j+l], s[j+l]-s[j]+dp[j][j+l-1]);
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}