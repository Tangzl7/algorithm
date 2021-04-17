#include<bits/stdc++.h>
using namespace std;

/*********

给三个数a,b,c, 让你找到两个数x和y，使得x，y，gcd(x,y)这三个数的位数分别是a，b，c。

当时想的是gcd(x,y)直接是10的多少次方，然后找两个质数，这两个质数分别乘以这个gcd。结果被pow坑(pow没有定义整数运算)。
看dl的思路是，10^m+7与10^n+3(m>=n)一定互质，然后就能解出来。但是发现pow函数精度差很大，也要错，
所以要用数组存10的次方。

*********/

// 素数晒找质数方法，刚好卡过的样子
 
bool a[100000000]={false};
int find1=-1;
 
void sushu() {
    a[0] = true, a[1] = true;
    for (int i=2; i<100000000; i++) {
        if (a[i] == false) {
            for (int j=i*2; j<100000000; j+=i) a[j] = true;
        }
    }
}
 
long long find(int x) {
    int l = pow(10, x-1)+1;
    for (int i=l; i<(l-1)*10; i++) {
        if (a[i] == false && i != find1) {
            find1 = i;
            return i;
        }
    }
    return l;
}
 
int main() {
    int t, a, b, c;
    cin >> t;
    sushu();
    int mult[15], tmp=1;
    mult[0] = 1;
    for (int i=1; i<15; i++) {
        tmp *= 10;
        mult[i] = tmp;
    }
    while(t--) {
        cin >> a >> b >> c;
        a = a - c + 1;
        b = b - c + 1;
        cout << find(a)*mult[c-1] << " " << find(b)*mult[c-1] << endl;
    }
    return 0;
}

// 参考方法
int main() {
    int t, a, b, c;
    cin >> t;
    int mult[15], tmp=1;
    mult[0] = 0;
    for (int i=1; i<15; i++){
        tmp*=10;
        mult[i] = tmp;
    }
    while(t--) {
        long long re1, re2;
        cin >> a >> b >> c;
        re1 = (mult[a-c]+(a>=b?7:3))*(c-1==0?1:mult[c-1]);
        if (b == 1) re2 = 1;
        re2 = (mult[b-c]+(a<b?7:3))*(c-1==0?1:mult[c-1]);
        cout << re1 << " " << re2 << endl;
    }
    return 0;
}