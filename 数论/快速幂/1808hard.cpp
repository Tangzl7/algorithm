/***********

num = a1^k1*a2^k2*...*an^kn
k1+k2+...+kn <= primeFactors
好因子必须含有a1*a2*...*an作为因数
好因子的个数 k = k1*k2*...*kn

问题转换：
正整数 k1+k2+...+kn <= primeFactors（1<=primeFactors<=10^9）
求k1*k2*...*kn的最大值
根据数学推到，尽可能拆为相同的数3。

***********/

class Solution {
public:
    long long MOD = 1e9 + 7;
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 3) return primeFactors;
        long long pow_3 = primeFactors/3;
        primeFactors %= 3;
        if (primeFactors == 1) {
            return quick_pow(3, pow_3-1)*4%MOD;
        } else if (primeFactors == 2) {
            return quick_pow(3, pow_3)*2%MOD;
        } else return quick_pow(3, pow_3);
    }

    long long quick_pow(long long a, long long b) {
        if (b == 0) return 1;
        if (b == 1) return a%MOD;
        if (b % 2 == 1) return (a%MOD*(quick_pow((a%MOD*a%MOD)%MOD, b/2)))%MOD;
        else return quick_pow((a%MOD*a%MOD)%MOD, b/2);
    }
};