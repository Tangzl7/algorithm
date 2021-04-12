#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m, a[100005];

bool judge(int x) {
	int cnt=1, dis=0, pre=0;
	for (int i=1; i<n; i++) {
		if (a[i] - a[pre] >= x) cnt++, pre=i;
	}
	return cnt >= m;
}

int get_result(int x) {
	int cnt=1, dis=0, re=0;
	for (int i=0; i<n-1; i++) {
		if (a[i+1]-a[i]+dis <= x) {
			dis += (a[i+1]-a[i]);
			re = max(re, dis);
		} else {
			dis = 0;
			cnt++;
		}
	}
	return re;
}

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	int l=-1, r=a[n-1]-a[0];
	for (int i=0; i<n-1; i++) {
		l = min(l, a[i+1]-a[i]);
	}
	while(l <= r) {
		int mid = (l+r)/2;
		if (judge(mid)) l = mid+1;
		else r = mid-1;
	}
	cout << r << endl;
}