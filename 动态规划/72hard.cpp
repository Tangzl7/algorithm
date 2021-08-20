/**************

对第二个单词的操作都能变换到对第一个单词的操作
dp[i][j]为对第一个单词的1:i变换到对第二单词的1:j需要的最少操作数
则dp[i][j]可能为dp[i-1][j]对第二个单词的一个增加操作增加或dp[i][j-1]对第一个单词的一个增加操作或dp[i-1][j-1]的某一个单词的一个变换操作
如果word1[i] = word2[j]，则dp[i][j] = dp[i-1][j-1]，即不需要变换，否则进行一次变换
递推方程：
第一个单词的第i个字母和第二个单词的第j个字母相同： dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1])
否则： dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + 1);

**************/

#include <bits/stdc++.h>
using namespace std;

int dp[505][505];

int main() {
	string word_1, word_2;
	cin >> word_1 >> word_2;
	for (int i=0; i<=word_1.size(); i++) dp[i][0] = i;
	for (int i=0; i<=word_2.size(); i++) dp[0][i] = i;
	for (int i=1; i<=word_1.size(); i++) {
		for (int j=1; j<=word_2.size(); j++) {
			if (word_1[i-1] == word_2[j-1]) {
				dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1]);
			} else {
				dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + 1);
			}
		}
	}
	cout << dp[word_1.size()][word_2.size()] << endl;
	return 0;
}