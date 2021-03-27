/**********

40分解
代码能力太垃圾了， 哭了
加数字写到一半就写不下去了，难受

**********/

#include <bits/stdc++.h>
using namespace std;

map<string, long long> left_map;
map<string, long long> right_map;

void set_map(string s) {
    left_map.clear(); right_map.clear();
    int equal;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '=') {
            equal = i;
            break;
        }
        if (s[i]>='A' && s[i]<='Z' && s[i+1]>='a' && s[i+1]<='z') {
            left_map[s.substr(i, 2)]++;
            i++;
        } else if(s[i]>='A' && s[i]<='Z'){
            left_map[s.substr(i, 1)]++;
        }
    }
    for (int i=equal+1; i<s.size(); i++) {
        if (s[i]>='A' && s[i] <= 'Z' && i<s.size()-1) {
            if (s[i+1]>='a' && s[i+1]<='z') {
                right_map[s.substr(i, 2)]++;
                i++;
            } else right_map[s.substr(i, 1)]++;
        } else if(s[i] >= 'A' && s[i] <= 'Z') 
            right_map[s.substr(i, 1)]++;
    }
}

int get_num(string s, int index) {
    int result=0;
    while(s[index] < '1' || s[index] > '9') {
        result = result*10 + (s[index] - '0');
        index++;
    }
    return result;
}

string get_element(string s, int index) {
    for (int i=index; i<s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z' && i<s.size()-1) {
            if (s[i+1] >= 'a' && s[i+1] <= 'z') return s.substr(i, 2);
            else return s.substr(i, 1);
        } else if(s[i] >= 'A' && s[i] <= 'Z')
            return s.substr(i, 1);
    }
}

void mult(string s) {
    int equal;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '=') {
            equal = i;
            break;
        }
        if (i==0 && s[i]>='1' && s[i]<='9') {
            int num = get_num(s, i);
            string elememt = get_element(s, i+1);
            left[elememt] *= num;
        }
    }
}

bool is_equal(map<string, long long> left, map<string, long long> right) {
    for (auto iter=left.begin(); iter != left.end(); iter++) {
        if (right[iter->first] != iter->second) return false;
    }
    for (auto iter=right.begin(); iter != right.end(); iter++) {
        if (left[iter->first] != iter->second) return false;
    }
    return true;
}

int main() {
    int n;
    string s[105];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        set_map(s[i]);
        if (is_equal(left_map, right_map)) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}