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



/***********
 * 
 * 堆排序
 * 
************/
class Solution {
public:

    int h_size = 0, heap[10005];

    void push(int x) {
        heap[++h_size] = x;
        int now = h_size;
        while(now > 1 && heap[now] > heap[now>>1]) {
            swap(heap[now], heap[now>>1]);
            now >>= 1;
        }
    }

    void push_down(int x) {
        int now = x;
        while(now <= h_size/2) {
            int min_index = now * 2;
            if (now * 2 + 1 <= h_size && heap[now*2+1] > heap[now*2]) min_index = now * 2 + 1;
            if (heap[now] < heap[min_index]) {
                swap(heap[now], heap[min_index]);
                now = min_index;
            }
            else break;
        }
    }

    void pop() {
        heap[1] = heap[h_size--];
        push_down(1);
    }

    void build() {
        int now = h_size/2;
        while(now > 0) {
            push_down(now);
            now--;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        for (int i=0; i<nums.size(); i++) heap[++h_size] = nums[i];
        build();
        for (int i=0; i<k-1; i++) pop();
        return heap[1];
    }
};



/***********
 * 
 * 归并排序
 * 
************/
void merge_sort(vector<int> &a, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, r);
    int k = 0, i = l, j = mid+1;
    vector<int> tmp;
    while(i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }
    while(i <= mid) tmp.push_back(a[i++]);
    while(j <= r) tmp.push_back(a[j++]);
    for (int i=l; i<=r; i++) a[i] = tmp[i-l];
}