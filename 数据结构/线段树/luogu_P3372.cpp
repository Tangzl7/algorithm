/*******

加法线段树模板

*******/

#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int a[MAXN];

struct node{
    int l, r;
    long long sum, lz=0;
}tree[4*MAXN];

void build(int i, int l, int r) {
    tree[i].l = l; 
    tree[i].r = r;
    if (l == r) {
        tree[i].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
    return;
}

void push_down(int i) {
    if (tree[i].lz != 0) {
        tree[i*2].lz += tree[i].lz;
        tree[i*2+1].lz += tree[i].lz;
        int mid = (tree[i].r + tree[i].l) / 2;
        tree[i*2].sum += tree[i].lz * (mid- tree[i*2].l + 1);
        tree[i*2+1].sum += tree[i].lz * (tree[i*2+1].r - mid);
        tree[i].lz = 0;
    }
}

long long search(int i, int l, int r) {
    if (tree[i].l >= l && tree[i].r <= r) 
        return tree[i].sum;
    if (tree[i].r < l || tree[i].l > r) return 0;
    push_down(i);
    long long sum = 0;
    if (tree[i*2].r >= l) sum += search(i*2, l, r);
    if (tree[i*2+1].l <= r) sum += search(i*2+1, l, r);
    return sum;
}


void add(int i, int l, int r, int k) {
    if (tree[i].l >= l && tree[i].r <= r) {
        tree[i].sum += k*(tree[i].r - tree[i].l + 1);
        tree[i].lz += k;
        return;
    }
    push_down(i);
    if (tree[i*2].r >= l) add(i*2, l, r, k);
    if (tree[i*2+1].l <= r) add(i*2+1, l, r, k);
    tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
    return;
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    int t, x, y, k;
    for (int i=0; i<m; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d %d", &x, &y, &k);
            add(1, x, y, k);
        }
        else if(t == 2) {
            scanf("%d %d", &x, &y);
            printf("%lld\n", search(1, x, y));
        }
    }
    return 0;
}
