/********************
 * 从后往前可以得到删除顺序，然后原始字符串的每个字符出现次数乘以一个数就是最后字符串中的字符出现次数
 * 而乘以的数可以从删除顺序得到，删除的第i个字符乘以i
 * 
 * ******************/

#include<bits/stdc++.h>
using namespace std;
 
bool check(string org, string s1, string s2) {
    string s = "";
    for (int i=0; i<s2.size(); i++) {
        s += s1;
        s1.erase(remove(s1.begin(), s1.end(), s2[i]), s1.end());
    }
    return s == org;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        set<char> set_;
        string s1, s2 = "";
        map<char, int> m;
        for (int i=s.size()-1; i>=0; i--) {
            m[s[i]] ++;
            if (set_.count(s[i]) == 0) {
                set_.insert(s[i]);
                s2 = s.substr(i, 1) + s2;
            }
        }
        if (set_.size() == 1) {
            cout << s << " " << s2 << endl;
            continue;
        }
        int len = 0, flag = 0;
        for (int i=0; i<s2.size(); i++) {
            len += m[s2[i]] / (i+1);
            // m[s2[i]]必定是(i+1)的倍数，否则直接-1结果(如果没有这步会错)
            // 可能是如果无这一部判断，check还是可能为true，从而错误
            if (m[s2[i]] / (i+1) == 0) {
                flag = 1;
                cout << "-1" << endl;
                break;
            }
        }
        if (flag == 1) continue;
        s1 = s.substr(0, len);
        if (check(s, s1, s2) == true) {
            cout << s1 << " " << s2 << endl;
        } else {
            cout << "-1" << endl;
        }
    }
}
