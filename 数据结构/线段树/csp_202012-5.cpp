/***************

错误解 有空再改

***************/

#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MOD 1000000007

struct point{
    long long x=0, y=0, z=0;
}a[MAXN], result;

struct node{
    int l, r;
    long long sum_x=0, sum_y=0, sum_z=0;
    long long plz_x=0, plz_y=0, plz_z=0, mlz=1, rlz=-1;
}tree[4*MAXN];

void rot_node(int i, int cnt) {
    cnt %= 3;
    for (int i=-1; i<cnt; i++) {
        swap(tree[i].sum_x, tree[i].sum_z);
        swap(tree[i].sum_x, tree[i].sum_y);
        swap(tree[i].plz_x, tree[i].plz_z);
        swap(tree[i].plz_x, tree[i].plz_y);
    }
}

void build(int i, int l, int r) {
    tree[i].l = l; tree[i].r = r;
    if (l == r) {
        tree[i].sum_x = a[l].x;
        tree[i].sum_y = a[l].y;
        tree[i].sum_z = a[l].z;
        return;
    }
    int mid = (l + r) / 2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    tree[i].sum_x = tree[i*2].sum_x + tree[i*2+1].sum_x;
    tree[i].sum_y = tree[i*2].sum_y + tree[i*2+1].sum_y;
    tree[i].sum_z = tree[i*2].sum_z + tree[i*2+1].sum_z;
}

void push_down(int i) {
    long long m = tree[i].mlz, px = tree[i].plz_x, py = tree[i].plz_y, pz = tree[i].plz_z, r = tree[i].rlz;
    tree[i*2].mlz = (tree[i*2].mlz * m)%MOD; tree[i*2].rlz += (r+1);
    // rot_node(i*2, r);
    tree[i*2].plz_x = (tree[i*2].plz_x * m + px)%MOD;
    tree[i*2].plz_y = (tree[i*2].plz_y * m + py)%MOD;
    tree[i*2].plz_z = (tree[i*2].plz_z * m + pz)%MOD;
    tree[i*2+1].mlz = (tree[i*2+1].mlz * m)%MOD; tree[i*2+1].rlz += (r+1);
    // rot_node(i*2+1, r);
    tree[i*2+1].plz_x = (tree[i*2+1].plz_x * m + px)%MOD;
    tree[i*2+1].plz_y = (tree[i*2+1].plz_y * m + py)%MOD;
    tree[i*2+1].plz_z = (tree[i*2+1].plz_z * m + pz)%MOD;
    tree[i*2].sum_x = (tree[i*2].sum_x * m + px*(tree[i*2].r - tree[i*2].l + 1))%MOD;
    tree[i*2].sum_y = (tree[i*2].sum_y * m + py*(tree[i*2].r - tree[i*2].l + 1))%MOD;
    tree[i*2].sum_z = (tree[i*2].sum_z * m + pz*(tree[i*2].r - tree[i*2].l + 1))%MOD;
    tree[i*2+1].sum_x = (tree[i*2+1].sum_x * m + px*(tree[i*2+1].r - tree[i*2+1].l + 1))%MOD;
    tree[i*2+1].sum_y = (tree[i*2+1].sum_y * m + py*(tree[i*2+1].r - tree[i*2+1].l + 1))%MOD;
    tree[i*2+1].sum_z = (tree[i*2+1].sum_z * m + pz*(tree[i*2+1].r - tree[i*2+1].l + 1))%MOD;
    tree[i].mlz = 1;
    tree[i].rlz = -1;
    tree[i].plz_x = 0;
    tree[i].plz_y = 0;
    tree[i].plz_z = 0;
}

void add(int i, int l, int r, int a, int b, int c) {
    if (tree[i].l >= l && tree[i].r <= r) {
        tree[i].sum_x = (tree[i].sum_x + (a%MOD*(tree[i].r - tree[i].l + 1)%MOD)%MOD)%MOD;
        tree[i].sum_y = (tree[i].sum_y + (b%MOD*(tree[i].r - tree[i].l + 1)%MOD)%MOD)%MOD;
        tree[i].sum_z = (tree[i].sum_z + (c%MOD*(tree[i].r - tree[i].l + 1)%MOD)%MOD)%MOD;
        tree[i].plz_x = (tree[i].plz_x + a%MOD)%MOD;
        tree[i].plz_y = (tree[i].plz_y + b%MOD)%MOD;
        tree[i].plz_z = (tree[i].plz_z + c%MOD)%MOD;
        return;
    }
    push_down(i);
    if (tree[i*2].r >= l) add(i*2, l, r, a, b, c);
    if (tree[i*2+1].l <= r) add(i*2+1, l, r, a, b, c);
    tree[i].sum_x = (tree[i*2].sum_x%MOD + tree[i*2+1].sum_x%MOD)%MOD;
    tree[i].sum_y = (tree[i*2].sum_y%MOD + tree[i*2+1].sum_y%MOD)%MOD;
    tree[i].sum_z = (tree[i*2].sum_z%MOD + tree[i*2+1].sum_z%MOD)%MOD;
}

void mult(int i, int l, int r, int k) {
    if (tree[i].l >= l && tree[i].r <= r) {
        tree[i].sum_x = (tree[i].sum_x * k)%MOD;
        tree[i].sum_y = (tree[i].sum_y * k)%MOD;
        tree[i].sum_z = (tree[i].sum_z * k)%MOD;
        tree[i].plz_x = (tree[i].plz_x * k)%MOD;
        tree[i].plz_y = (tree[i].plz_y * k)%MOD;
        tree[i].plz_z = (tree[i].plz_z * k)%MOD;
        tree[i].mlz = (tree[i].mlz * k)%MOD;
        return;
    }
    push_down(i);
    if (tree[i*2].r >= l) mult(i*2, l, r, k);
    if (tree[i*2+1].l <= r) mult(i*2+1, l, r, k);
    tree[i].sum_x = (tree[i*2].sum_x + tree[i*2+1].sum_x)%MOD;
    tree[i].sum_y = (tree[i*2].sum_y + tree[i*2+1].sum_y)%MOD;
    tree[i].sum_z = (tree[i*2].sum_z + tree[i*2+1].sum_z)%MOD;
}

void rot(int i, int l, int r) {
    if (tree[i].l >= l && tree[i].r <= r) {
        rot_node(i, 1);
        tree[i].rlz += 1;
        return;
    }
    push_down(i);
    if (tree[i*2].r >= l) rot(i*2, l, r);
    if (tree[i*2+1].l <= r) rot(i*2+1, l, r);
    tree[i].sum_x = (tree[i*2].sum_x + tree[i*2+1].sum_x)%MOD;
    tree[i].sum_y = (tree[i*2].sum_y + tree[i*2+1].sum_y)%MOD;
    tree[i].sum_z = (tree[i*2].sum_z + tree[i*2+1].sum_z)%MOD;
}

void search(int i, int l, int r) {
    if (tree[i].l >= l && tree[i].r <= r) {
        result.x = (result.x + tree[i].sum_x)%MOD;
        result.y = (result.y + tree[i].sum_y)%MOD;
        result.z = (result.z + tree[i].sum_z)%MOD;
        return;
    }
    if (tree[i].l > r || tree[i].r < l) return;
    push_down(i);
    if (tree[i*2].r >= l) search(i*2, l, r);
    if (tree[i*2+1].l <= r) search(i*2+1, l, r);
    return;
}

long long search1(int i, int l, int r) {
    if (tree[i].l >= l && tree[i].r <= r) {
        return tree[i].sum_x % MOD;
    }
    if (tree[i].l > r || tree[i].r < l) return 0;
    push_down(i);
    long long s = 0;
    if (tree[i*2].r >= l) s += search1(i*2, l, r);
    if (tree[i*2+1].l <= r) s += search1(i*2+1, l, r);
    return s%MOD;
}

long long search2(int i, int l, int r) {
    if (tree[i].l >= l && tree[i].r <= r) {
        return tree[i].sum_y % MOD;
    }
    if (tree[i].l > r || tree[i].r < l) return 0;
    push_down(i);
    long long s = 0;
    if (tree[i*2].r >= l) s += search2(i*2, l, r);
    if (tree[i*2+1].l <= r) s += search2(i*2+1, l, r);
    return s%MOD;
}

long long search3(int i, int l, int r) {
    if (tree[i].l >= l && tree[i].r <= r) {
        return tree[i].sum_z % MOD;
    }
    if (tree[i].l > r || tree[i].r < l) return 0;
    push_down(i);
    long long s = 0;
    if (tree[i*2].r >= l) s += search3(i*2, l, r);
    if (tree[i*2+1].l <= r) s += search3(i*2+1, l, r);
    return s%MOD;
}

int main() {
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    for (int i=0; i<m; i++) {
        long long t, l, r, a, b, c, k;
        scanf("%lld", &t);
        if (t == 1) {
            scanf("%lld %lld %lld %lld %lld", &l, &r, &a, &b, &c);
            add(1, l, r, a, b, c);
        } else if (t == 2) {
            scanf("%lld %lld %lld", &l, &r, &k);
            mult(1, l, r, k);
        } else if (t == 3) {
            scanf("%lld %lld", &l, &r);
            // rot(1, l, r);
        } else if (t == 4) {
            scanf("%lld %lld", &l, &r);
            long long x = search1(1, l, r);
            long long y = search2(1, l, r);
            long long z = search3(1, l, r);
            // long long res = ((result.x*result.x)%MOD + (result.y*result.y)%MOD + (result.z*result.z)%MOD)%MOD;
            // result.x = 0; result.y = 0; result.z = 0;
            printf("%lld\n", (x%MOD*x%MOD + y%MOD*y%MOD + z%MOD*z%MOD)%MOD);
        }
    }
}