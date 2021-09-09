/*********************

思路正确了，但是不会逆元，思路就不写了，记一下逆元的求法
a/b % c = a*(b的逆元) % c
如果c素数，则b的逆元为b^(c-2) % c
即问题转化为快速幂

*********************/

#include <bits/stdc++.h>
using namespace std;

long long p[200005];
int a[200005];

long long quick_pow(long long base, long long pow) {
    long long ans = 1;
    while(pow) {
        if (pow & 1) ans = (base * ans) % 998244353;
        pow >>= 1;
        base = (base * base) % 998244353;
    }
    return ans;
}


int main(){
    int t;
    cin >> t;
    for (int i=1; i<200005; i++) {
        if (i == 1) p[i] = 1;
        else p[i] = (p[i-1] * i)%998244353;
    }
    while(t--) {
        int n;
        cin >> n;
        int max_1 = 0, max_2 = 0;
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        max_1 = a[n-1];
        max_2 = a[n-2];
        if (max_1 - max_2 > 1) {
            cout << "0" << endl;
        } else if (max_1 == max_2) {
            cout << p[n] << endl;
        } else {
            long long cnt = 0;
            for (int i=n-1; i>=0; i--) {
                if (a[i] < max_2) break;
                cnt ++;
            }
            long long inverse = quick_pow(cnt, 998244351);
            cout << (p[n] * (((cnt - 1) * inverse)%998244353))%998244353 << endl;
        }
    }
}
