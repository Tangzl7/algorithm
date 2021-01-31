/******
给你两个字符串 a 和 b ，二者均由小写字母组成。一步操作中，你可以将 a 或 b 中的 任一字符 改变为 任一小写字母 。

操作的最终目标是满足下列三个条件 之一 ：

a 中的 每个字母 在字母表中 严格小于 b 中的 每个字母 。
b 中的 每个字母 在字母表中 严格小于 a 中的 每个字母 。
a 和 b 都 由 同一个 字母组成。
返回达成目标所需的 最少 操作数。

遍历26个字母即可，自己做的时候想复杂了。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions
******/

class Solution {
public:
	int less_funct(string a, string b, char c) {
		int cnt = 0;
		for (int i=0; i<a.size(); i++) {
			if (a[i] > c) cnt++;
		}
		for (int i=0; i<b.size(); i++) {
			if (b[i] <= c) cnt++;
		}
		return cnt;
	}

	int equal_funct(string a, string b, char c) {
		int cnt = 0;
		for (int i=0; i<a.size(); i++) {
			if (a[i] != c) cnt++;
		}
		for (int i=0; i<b.size(); i++) {
			if (b[i] != c) cnt++;
		}
		return cnt;
	}

    int minCharacters(string a, string b) {
    	int result = 1e6;
    	for (char i='a'; i<='z'; i++) {
    		if (i != 'z') {
	    		result = min(result, less_funct(a, b, i));
	    		result = min(result, less_funct(b, a, i));
	    	}
	    	result = min(result, equal_funct(a, b, i));
    	}
    	return result;
    }
};