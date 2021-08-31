/****************************************
 * 
 * 一个正确的序列必定是101010....或者010101....
 * 只要0在正确的位置，其余位置的1必定也在正确位置了
 * 每个出现0的位置和它应该在的位置的差值就是交换次数，所有0的交换次数和就是结果
 * 
 * *************************************/

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, a[100005];
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i] %= 2;
        }
        long long result = LLONG_MAX;
        for (int i=0; i<2; i++) {
            int b[100005], check=0;
            long long tmp_result=0;
            b[0] = i;
            for (int j=1; j<n; j++) b[j] = b[j-1] ^ 1;
            for (int j=0; j<n; j++) {
                check += a[j] - b[j];
            }
            if (check != 0) continue;
            vector<int> c[2];
            for (int j=0; j<n; j++) {
                if (a[j] == 0) c[0].push_back(j);
                if (b[j] == 0) c[1].push_back(j);
            }
            for (int j=0; j<c[0].size(); j++) {
                tmp_result += abs(c[0][j] - c[1][j]);
            }
            result = min(result, tmp_result);
        }
        if (result == LLONG_MAX) {
            cout << "-1" << endl;
        } else cout << result << endl;
    }
}
