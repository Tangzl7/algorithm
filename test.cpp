#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	int y = 0;
    	if (x < 0) return false;
    	while(x > y) {
    		y = y*10 + x%10;
    		x /= 10;
    	}
    	if (x == y || x == y/10) return true;
    	return false;
    }
};

int main() {
	printf("%d\n", "21" < "3");
	return 0;
}