#include<bits/stdc++.h>
using namespace std;
#define INF 1e8

int flag = 0;
int n, a[1005];
vector<int> tree;
void find(int l, int r) {
	if (l > r) return;
	int tl = l+1, tr = r;
	if (flag == 0) {
		while (tl <= r && a[tl] < a[l]) tl++;
		while (tr > l && a[tr] >= a[l]) tr--;
	} else {
		while (tl <= r && a[tl] >= a[l]) tl++;
		while (tr > l && a[tr] < a[l]) tr--;
	}
	if (tr - tl + 2 != 1) return;
	find(l+1, tl-1);
	find(tr+1, r);
	tree.push_back(a[l]);
}

int main() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	find(0, n-1);
	if (tree.size() != n) {
		tree.clear();
		flag = 1;
		find(0, n-1);
	}
	if (tree.size() == n) {
		cout << "YES" << endl;
		for (int i=0; i<tree.size(); i++) {
			if (i == 0) cout << tree[i];
			else cout << " " << tree[i];
		}
	} else cout << "NO" << endl;
	return 0;
}