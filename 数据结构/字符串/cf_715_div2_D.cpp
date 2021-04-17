#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, t;

int get_cnt(string s, int index, char sub) {
    int cnt=0;
    for (int i=index; i<s.size(); i++) {
        if (s[i] == sub) break;
        cnt++;
    }
    return cnt;
}

string bitstring(string a, string b, char sub) {
    string result = "";
    int index_1=0, index_2=0;
    map<int,int> m[2];
    for (int i=index_1; i<a.size(); i++) {
        if (a[i] == sub) {
            index_1 = i+1;
            continue;
        } else {
            m[0][index_1]++;
        }
    }
    for (int i=index_2; i<b.size(); i++) {
        if (b[i] == sub) {
            index_2 = i+1;
            continue;
        } else {
            m[1][index_2]++;
        }
    }
    index_1 = 0, index_2 = 0;
    while (result.size() < 3*n) {
        // int cnt1 = get_cnt(a, index_1, sub);
        int cnt1 = m[0][index_1];
        index_1 = index_1 + cnt1 + 1;
        // int cnt2 = get_cnt(b, index_2, sub);
        int cnt2 = m[1][index_2];
        index_2 = index_2 + cnt2 + 1;
        for (int j=0; j<max(cnt1, cnt2); j++) {
            if (sub == '1') result += "0";
            else result += "1";
        }
        result += (sub == '1' ? "1":"0");
    }
    return result.substr(0, 3*n);
}
 
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        string s[3];
        int cnt[3]={0};
        for (int i=0; i<3; i++) {
            cin >> s[i];
            for (int j=0; j<s[i].size(); j++) {
                if (s[i][j] == '1') cnt[i]++;
            }
        }
        string result;
        if (cnt[0] >= n && cnt[1] >= n) result = bitstring(s[0], s[1], '1');
        else if (cnt[0] >= n && cnt[2] >= n) result = bitstring(s[0], s[2], '1');
        else if (cnt[1] >= n && cnt[2] >= n) result = bitstring(s[1], s[2], '1');
        else if (cnt[0] < n && cnt[1] < n) result = bitstring(s[0], s[1], '0');
        else if (cnt[0] < n && cnt[2] < n) result = bitstring(s[0], s[2], '0');
        else result = bitstring(s[1], s[2], '0');
        cout << result << endl;
    }
}