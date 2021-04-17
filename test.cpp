#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

struct node {
    int l, r, sum=0, lz=0;
}tree[400005];

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
        tree[i].sum = tree[i].sum + tree[i].lz*(tree[i].r-tree[i].l+1);
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

}
 
int main() {
    
}