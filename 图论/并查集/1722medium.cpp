/******
给你两个整数数组 source 和 target ，长度都是 n 。还有一个数组 allowedSwaps ，其中每个 allowedSwaps[i] = [ai, bi] 表示你可以交换数组 source 中下标为 ai 和 bi（下标从 0 开始）的两个元素。注意，你可以按 任意 顺序 多次 交换一对特定下标指向的元素。

相同长度的两个数组 source 和 target 间的 汉明距离 是元素不同的下标数量。形式上，其值等于满足 source[i] != target[i] （下标从 0 开始）的下标 i（0 <= i <= n-1）的数量。

在对数组 source 执行 任意 数量的交换操作后，返回 source 和 target 间的 最小汉明距离 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations
******/

/******

1，2可以相互交换，1，3可以相互交换，则1，3可以相互交换。即问题可以转换为并查集问题，在一个连通图中两两均可交换。

于是，target数组中某下标的值能否找到source中对应的值，问题转换为是否能在相应的连通图中找到相同的值。

由于数组中可能存在相同的值，所以并查集不能通过值维护，应该通过下标维护。

关系的维护方法是通过两层的unordered_map维护的，表示对应的连通图的根节点(下标)，根节点下的值，和该值在连通图的次数。

******/

class Solution {
public:
	int pre[100005];

	int find(int x) {
		if (x == pre[x]) return x;
		return pre[x] = find(pre[x]);
	}

	void join(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return;
		pre[fx] = fy;
		return;
	}

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    	int result = 0;
    	unordered_map<int, unordered_map<int, int> > connect_graph;
    	for (int i=0; i<100005; i++) pre[i] = i;
    	for (int i=0; i<allowedSwaps.size(); i++) {
    		join(allowedSwaps[i][0], allowedSwaps[i][1]);
    	}
    	for (int i=0; i<source.size(); i++) {
    		int find_root = find(i);
    		connect_graph[find_root][source[i]] += 1;
    	}
    	for (int i=0; i<target.size(); i++) {
    		int find_root = find(i);
    		if (connect_graph[find_root][target[i]] > 0) {
    			connect_graph[find_root][target[i]] -= 1;
    		} else {
    			result += 1;
    		}
    	}
    	return result;
    }
};