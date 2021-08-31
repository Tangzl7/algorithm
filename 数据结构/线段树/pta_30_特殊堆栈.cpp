/****************

权值线段树，求第k大的值

****************/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

struct node {
    int l, r, sum=0, lz=0;
}tree[400005];
int a[100005], len=0;

void build(int i, int l, int r) {
    tree[i].l = l, tree[i].r = r;
    if (l == r) {
        tree[i].sum = 0;
        return;
    }
    int mid = (l+r)/2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
}

void push_down(int i) {
    if (tree[i].lz > 0) {
        tree[i*2].lz += tree[i].lz;
        tree[i*2+1].lz += tree[i].lz;
        tree[i*2].sum = tree[i*2].sum + tree[i].lz*(tree[i*2].r-tree[i*2].l+1);
        tree[i*2+1].sum = tree[i*2+1].sum + tree[i].lz*(tree[i*2+1].r-tree[i*2+1].l+1);
        tree[i].lz = 0;
    }
}

void add(int i, int l, int r, int k) {
    if (tree[i].l >= l && tree[i].r <= r) {
        tree[i].sum += k*(tree[i].r-tree[i].l+1);
        return;
    }
    if (tree[i*2].r >= l) add(i*2, l, r, k);
    if (tree[i*2+1].l <= r) add(i*2+1, l, r, k);
    tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
}

int search(int i, int l, int r) {
    if (tree[i].l >= l && tree[i].r <= r) {
        return tree[i].sum;
    }
    int sum=0;
    if (tree[i*2].r >= l) sum += search(i*2, l, r);
    if (tree[i*2+1].l <= r) sum += search(i*2+1, l, r);
    return sum;
}

int find(int i, int k) {
    if (tree[i].l == tree[i].r) {
        return tree[i].l;
    }
    if (tree[i*2].sum >= k) return find(i*2, k);
    else return find(i*2+1, k-tree[i*2].sum);
}
 
int main() {
    int n;
    cin >> n;
    build(1, 1, 100000);
    while(n--) {
        string s;
        cin >> s;
        if (s == "Pop") {
            if (len <= 0) {
                cout << "Invalid" << endl;
                continue;
            } else {
                cout << a[--len] << endl;
                add(1, a[len], a[len], -1);
            }
        } else if (s == "PeekMedian") {
            if (len <= 0) {
                cout << "Invalid" << endl;
                continue;
            }
            if (len % 2 == 0) cout << find(1, len/2) << endl;
            else cout << find(1, (len+1)/2) << endl;
        } else {
            int t;
            cin >> t;
            a[len++] = t;
            add(1, a[len-1], a[len-1], 1);
        }
    }
}