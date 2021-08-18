/***********
 * 最长递增子序列(题目来自牛客和leetcode的300题差不多，除了该题要求输出数组结果)
 * 比较容易想到的一个dp方法是(我都没想到 cao)：dp[i]从第i位往前，找小于a[i]的，设为j1，j2，j3等，则dp[i] = max(dp[j1]+1, dp[j2]+1, ....)
 * 上面那个方法O(n^2)会超时。正确方法是：
初始情况下，vec为[2]，maxLen[1]
接下来遇到3，由于vec最后一个元素小于3，直接更新，vec为[2,3]，maxLen[1,2]
接下来遇到1，由于vec最后的元素大于1, 我们在vec中查找大于等于1的第一个元素的下标，并用1替换之，此时vec为[1,3], maxLen[1,2,1]
接下来遇到2，由于vec最后的元素大于2，我们在vec中查找大于等于2的第一个元素的下标，并用2替换之，此时vec为[1,2], maxLen[1,2,1,2]
接下来遇到3，由于vec最后一个元素小于3，直接更新，vec为[1,2,3]，maxLen为[1,2,1,2,3]
此时vec的大小就是整个序列中最长递增子序列的长度（但是vec不一定是本题的最终解）（引用牛客网用户华科不平凡
 * 
 * 最后从后往前，找到最小字典序的序列即可，从后往前可以保证字典序最小(证明略)
************/

class Solution {
public:
    int a[100005], dp[100005], k=0;

    vector<int> LIS(vector<int>& arr) {
        a[k++] = arr[0];
        dp[0] = k;
        int max_len = 0;
        for (int i=1; i<arr.size(); i++) {
            if (arr[i] > a[k-1]) {
                a[k++] = arr[i];
                dp[i] = k;
                max_len = max(max_len, dp[i]);
            } else {
                int find = lower_bound(a, a+k, arr[i]) - a;
                a[find] = arr[i];
                dp[i] = find+1;
            }
        }
        vector<int> result(max_len);
        for (int i=arr.size()-1; i>=0; i--) {
            if (max_len == 0) break;
            if (dp[i] == max_len) {
                result[max_len-1] = arr[i];
                max_len--;
            }
        }
        return result;
    }
};