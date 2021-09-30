/***********
 * 
 * 递归形式的动态规划，卧槽，写了一个纯暴力的递归，直接tle了
 * 正确做法：每个节点维护选择它和不选择它的情况下的最优解
 * 
************/

class Solution {
public:
    pair<int,int> get_result(TreeNode* node) {
        if (node == nullptr) return pair<int,int>(0, 0);
        pair<int,int> result;
        pair<int,int> left = get_result(node->left);
        pair<int,int> right = get_result(node->right);
        result.first = node->val + left.second + right.second;
        result.second = max(left.first, left.second) + max(right.first, right.second);
        return result;
    }

    int rob(TreeNode* root) {
        pair<int,int> result = get_result(root);
        return max(result.first, result.second);
    }
};