#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<string, string> m;
    set<string> s;

    bool join_judge(string s1, string s2) {
        int dif1=-1, dif2=-1, dif_cnt=0;
        for (int i=0; i<s1.size(); i++) {
            if (s1[i] != s2[i]) dif_cnt++;
            if (s1[i] != s2[i] && dif1 == -1) dif1 = i;
            else if (s1[i] != s2[i] && dif2 == -1) dif2 = i;
        }
        if (dif_cnt == 0) return true;
        if (dif_cnt != 2) return false;
        char tmp = s1[dif1];
        s1[dif1] = s1[dif2];
        s1[dif2] = tmp;
        return s1 == s2;
    }

    string find(string s1) {
        if (m[s1] == s1) return s1;
        return m[s1] = find(m[s1]);
    }

    void join(string x, string y) {
        string fx = find(x);
        string fy = find(y);
        m[fx] = fy;
    }

    int numSimilarGroups(vector<string>& strs) {
        for (int i=0; i<strs.size(); i++) {
            m[strs[i]] = strs[i];
        }
        for (int i=0; i<strs.size()-1; i++) {
            for (int j=i+1; j<strs.size(); j++) {
                if (join_judge(strs[i], strs[j])) {
                    join(strs[i], strs[j]);
                }
            }
        }
        for (int i=0; i<strs.size(); i++) {
            string tmp = find(strs[i]);
            set.insert(tmp);
        }
        return set.size();
    }
};

int main() {
	printf("%d\n", "21" < "3");
	return 0;
}