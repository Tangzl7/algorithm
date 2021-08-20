/********************
 * k=1的情况很简单
 * k=2的情况，便利两个不同的数，如果和字符串的当前位置相同，则移到下一位，如果字符串当前位小于i，则后面全部为i
 * 如果在i和j之间，后面第一位接i，余下接j，如果大于j，从后往前找第一个为i的数，变为j，中间全部变为i，后面也全部接i
 * (反正不会看这个题了，题解就瞎写了，过几天自己也看不懂了)
 * 
 * ******************/

#include<bits/stdc++.h>
using namespace std;

string find_1(string num) {
    string result;
    for (int i='1'; i<='9'; i++) {
        result = string(num.size(), i);
        if (result >= num) return result;
    }
    return result;
}

string find_2(string num) {
    string result = find_1(num);
    for (int i='0'; i<='9'; i++) {
        for (int j=i+1; j<='9'; j++) {
            string tmp = "";
            for (int k=0; k<num.size(); k++) {
                if (num[k] == i || num[k] == j) {
                    tmp += num[k];
                    if (tmp.size() == result.size() && result > tmp) result = tmp;
                } else if (num[k] < i) {
                    tmp += string(result.size() - tmp.size(), i);
                    if (result > tmp) result = tmp;
                    break;
                } else if (num[k] > i && num[k] < j) {
                    tmp += j;
                    tmp += string(result.size() - tmp.size(), i);
                    if (result > tmp) result = tmp;
                    break;
                } else {
                    int flag = 0;
                    for (int h=tmp.size()-1; h>=0; h--) {
                        if (tmp[h] == i) {
                            flag = 1;
                            tmp[h] = j;
                            break;
                        } else tmp[h] = i;
                    }
                    if (flag == 1) {
                        int tmp_size = tmp.size();
                        for (int z=0; z<num.size()-tmp_size; z++) tmp+=i;
                        if (tmp.size() == num.size() && result > tmp) {
                            result = tmp;
                        }
                        break;
                    } else break;
                }
            }
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        int k;
        string num;
        cin >> num >> k;
        if (k == 1) cout << find_1(num) << endl;
        else cout << find_2(num) << endl;
    }
}
