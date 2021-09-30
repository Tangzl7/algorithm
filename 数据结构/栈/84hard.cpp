/***********
 * 
 * 单调栈
 * 
 * 
************/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> left, right;
        vector<int> l(heights.size());
        vector<int> r(heights.size());
        for (int i=0; i<heights.size(); i++) {
            while (!left.empty() && heights[left.top()] >= heights[i]) left.pop();
            l[i] = left.empty() ? -1 : left.top();
            left.push(i);
        }
        for (int i=heights.size()-1; i>=0; i--) {
            while (!right.empty() && heights[right.top()] >= heights[i]) right.pop();
            r[i] = right.empty() ? heights.size() : right.top();
            right.push(i);
        }
        int result = 0;
        for (int i=0; i<heights.size(); i++) {
            cout << r[i] << " " << l[i] << " " << heights[i] << endl;
            result = max(result, (r[i] - l[i] - 1) * heights[i]);
        }
        return result;
    }
};