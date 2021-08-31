/*********************

Almost Sorted

*********************/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
 
 
int main() {
    long long t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if (n < 63 && 1ll<<(n-1) < k) {
            cout << "-1" << endl;
            continue;
        }
        n--;
        long long now = 1, flag = 0, cnt = 0;
        for (int i=n; i>=0; i--) {
            if (i == 0) {
                for (long long j=now+cnt; j>=now; j--) {
                    if (flag == 0) {
                        cout << j;
                        flag = 1;
                    } else {
                        cout << " " << j;
                    }
                }
            }
            if ((i-1)>=63 || k <= 1ll<<(i-1)) {
                for (long long j=now+cnt; j>=now; j--) {
                    if (flag == 0) {
                        cout << j;
                        flag = 1;
                    } else {
                        cout << " " << j;
                    }
                }
                now += cnt+1;
                cnt = 0;
            } else {
                cnt ++;
                k -= 1ll<<(i-1);
            }
        }
        cout << endl;
    }
}
