/******
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
******/

/******

假设 x ≤ y

如果我们保持左指针的位置不变，那么无论右指针在哪里，这个容器的容量都不会超过 x * t

这个左指针对应的数不会作为容器的边界了，那么我们就可以丢弃这个位置，将左指针向右移动一个位置

此时的左右指针，就指向了一个新的、规模减少了的问题的数组的左右边界

******/


class Solution {
public:
    int maxArea(vector<int>& height) {
    	int result = 0;
    	int l=0, r=height.size()-1;
    	while(l < r) {
    		result = max(result, min(height[l], height[r])*(r-l));
    		if (height[l] < height[r]) l++;
    		else r--;
    	}
    	return result;
    }
};