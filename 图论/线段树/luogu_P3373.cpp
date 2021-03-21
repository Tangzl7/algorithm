/*******

加法乘法混合线段树模板

*******/

#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int a[MAXN];
int n, m, p;
struct node {
    int l, r;
    long long sum, lz=0, mlz=1;
}tree[4*MAXN];

void build(int i, int l, int r) {
    tree[i].l = l; tree[i].r = r;
    if (tree[i].l == tree[i].r) {
        tree[i].sum = a[l] % p;
        return;
    }
    int mid = (l + r) / 2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
}

void push_down(int i) {
    if (tree[i].lz != 0 || tree[i].mlz != 1) {
        tree[i*2].lz = (tree[i*2].lz*tree[i].mlz + tree[i].lz)%p;
        tree[i*2+1].lz = (tree[i*2+1].lz*tree[i].mlz + tree[i].lz)%p;
        tree[i*2].mlz = (tree[i*2].mlz * tree[i].mlz)%p;
        tree[i*2+1].mlz = (tree[i*2+1].mlz * tree[i].mlz)%p;
        tree[i*2].sum = (tree[i*2].sum*tree[i].mlz + tree[i].lz * (tree[i*2].r - tree[i*2].l + 1))%p;
        tree[i*2+1].sum = (tree[i*2+1].sum * tree[i].mlz + tree[i].lz * (tree[i*2+1].r - tree[i*2+1].l + 1))%p;
        tree[i].lz = 0;
        tree[i].mlz = 1;
    }
}

void add(int i, int l, int r, int k) {
    if (tree[i].l >= l && tree[i].r <= r) {
        tree[i].sum = (tree[i].sum + k*(tree[i].r - tree[i].l + 1))%p;
        tree[i].lz = (tree[i].lz + k)%p;
        return;
    }
    push_down(i);
    if (tree[i*2].r >= l) add(i*2, l, r, k);
    if (tree[i*2+1].l <= r) add(i*2+1, l, r, k);
    tree[i].sum = (tree[i*2].sum + tree[i*2+1].sum)%p;
}

void mult(int i, int l, int r, int k) {
    if (tree[i].l >= l && tree[i].r <= r) {
        tree[i].sum = (tree[i].sum * k)%p;
        tree[i].mlz = ((tree[i].mlz) * k)%p;
        tree[i].lz = (tree[i].lz * k)%p;
        return;
    }
    push_down(i);
    if (tree[i*2].r >= l) mult(i*2, l, r, k);
    if (tree[i*2+1].l <= r) mult(i*2+1, l, r, k);
    tree[i].sum = (tree[i*2].sum + tree[i*2+1].sum)%p;
}

long long search(int i, int l, int r) {
    if (tree[i].l >= l && tree[i].r <= r) {
        return tree[i].sum % p;
    }
    if (tree[i].r < l || tree[i].l > r) return 0;
    push_down(i);
    long long s = 0;
    if (tree[i*2].r >= l) s += search(i*2, l, r)%p;
    if (tree[i*2+1].l <= r) s += search(i*2+1, l, r)%p;
    return s%p;
}

int main() {
    cin >> n >> m >> p;
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    int t, x, y, k;
    for (int i=0; i<m; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d %d", &x, &y, &k);
            mult(1, x, y, k);
        } else if(t == 2) {
            scanf("%d %d %d", &x, &y, &k);
            add(1, x, y, k);
        } else if(t == 3) {
            scanf("%d %d", &x, &y);
            printf("%lld\n", search(1, x, y));
        }
    }
    return 0;
}
