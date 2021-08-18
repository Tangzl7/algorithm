/***********
 * 数组中的第K个最大元素
 * 主要通过这个题来学习写快排
 * 这个题的一个更快的思路应该是通过优先队列来维护只有k个元素的堆，小于堆顶元素则不考虑，大于则替换堆顶元素
************/

class Solution {
public:
    int quick_sort(vector<int> a, int left, int right, int k) {
        if (left < right) {
            int pivot = a[left];
            int low = left, high = right;
            while(low < high) {
                while(a[high] >= pivot && low < high) high--;
                a[low] = a[high];
                while(a[low] <= pivot && low < high) low++;
                a[high] = a[low];
            }
            a[low] = pivot;
            if (low == k) return a[low];
            else if (low < k) return quick_sort(a, low+1, right, k);
            else return quick_sort(a, left, low-1, k);
        }
        return a[left];
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size()-1, nums.size()-k);
    }
};