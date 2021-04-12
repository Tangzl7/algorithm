#include<bits/stdc++.h>
using namespace std;
#define INF 1e8

int n, a[35], b[35];

struct node {
	int l=-1, r=-1;
}c[3000];

int build(int len, int a[], int b[]) {
	if (len <= 0) return -1;
	if (len == 1) return a[0];
	int t=0;
	for (int i=0; i<len; i++) {
		if (b[0] == a[i]) t = i;
	}
	c[b[0]].l = build(t, a, b+1);
	c[b[0]].r = build(len-t-1, a+t+1, b+t+1);
	return b[0];
}

void reverse(int s) {
	swap(c[s].l, c[s].r);
	if (c[s].l != -1) reverse(c[s].l);
	if (c[s].r != -1) reverse(c[s].r);
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int now = q.front(); q.pop();
		if (now == s) cout << now;
		else cout << " " << now;
		if (c[now].l != -1) q.push(c[now].l);
		if (c[now].r != -1) q.push(c[now].r);
	}
}

int main() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	build(n, a, b);
	reverse(b[0]);
	bfs(b[0]);
	return 0;
}
