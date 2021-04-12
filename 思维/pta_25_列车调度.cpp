#include<bits/stdc++.h>
using namespace std;
#define INF 1e8

int main() {
	int n, sum=1, a[100005];
	set<int> s;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	s.insert(a[0]);
	for (int i=1; i<n; i++) {
		if (s.upper_bound(a[i]) != s.end()) {
			s.erase(s.upper_bound(a[i]));
			s.insert(a[i]);
		} else {
			s.insert(a[i]);
		}
	}
	cout << s.size() << endl;
	return 0;
}