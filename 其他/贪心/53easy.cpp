/******
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

要求：时间复杂度为O(n)，空间复杂度为O(1)
******/

/******

满足时间复杂度要求的解方法首先想到的是线段树，但是空间复杂度也不满足(主要是不会写线段树了。。。。
正确方法：从前往后开始累加，如果当前累加和小于0了，说明前面的所有值都不会对后面的子数组产生作用，所以将累加和变为0，
后面继续进行这种操作。记录中间产生的和的最大值就是最后结果。
dp[i-1] > 0:  dp[i] = dp[i-1] + a[i]
dp[i-1] <= 0:  dp[i] = a[i]

******/



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_num = -100000, sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            max_num = max(max_num, sum);
            if (sum < 0) sum = 0;
        }
        return max_num;
    }
};