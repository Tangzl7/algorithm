/********************
 * 、
 * 每个对应位的进位只会影响它的前面第二位 所以将n的奇数位和偶数位提取出来就是正常的加分操作
 * 所有奇数位和偶数位连起来的数为a和b，则a和b分别有a+1和b+1个pair
 * 但是(0, a), (0, b), (a, 0), (b, 0)的组合中有三个相同的组合结果，即减2
 * 
 * ******************/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        string s, a = "", b = "";
        cin >> s;
        if (s.size() == 1) {
            cout << stoi(s) - 1 << endl;
            continue;
        }
        for (int i=0; i<s.size(); i++) {
            if (i % 2 == 0) a += s[i];
            else b += s[i];
        }
        int t1 = stoi(a), t2 = stoi(b);
        cout << (t1 + 1) * (t2 + 1) - 2 << endl;
    }
}