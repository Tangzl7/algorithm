/****************************************
 * 
 * 数组中的每个组括号开始向右匹配，直到右括号数更多结束
 * 左括号被匹配完并不会使得右边匹配结束，这样能够使得同级多有匹配的括号得到统计
 * 内层左括号被匹配完才会匹配当前的左括号
 * 
 * *************************************/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long a[1005];
    cin >> n;
    long long result = 0;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i+=2) {
        long long left = 0, tmp = a[i];
        for (int j=i+1; j<n; j++) {
            if (j % 2 == 0) {
                left += a[j];
            } else {
                long long right = a[j];
                long long sub = min(left, right);
                left -= sub; right -= sub;
                if (left == 0) {
                    result += min(tmp, right);
                    result += (j > i + 1);
                    sub = min(tmp, right);
                    tmp -= sub; right -= sub;
                    if (right > 0) break;
                }
            }
        }
    }
    cout << result << endl;
}