/******
给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i 个子数组被解释为一个二进制数（从最高有效位到最低有效位）。

返回布尔值列表 answer，只有当 N_i 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-prefix-divisible-by-5
******/

/******

1. (a + b) % p = (a % p + b % p) % p 
2. (a - b) % p = (a % p - b % p) % p 
3. (a * b) % p = (a % p * b % p) % p 
4. (a^b) % p = ((a % p)^b) % p

******/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
    	int tmp = 0;
    	vector<bool> result;
    	for (int i=0; i<A.size(); i++) {
    		tmp = (tmp << 1) + A[i];
    		tmp %= 5;
    		if (tmp % 5 == 0) result.push_back(true);
    		else result.push_back(false);
    	}
    	return result;
    }
};