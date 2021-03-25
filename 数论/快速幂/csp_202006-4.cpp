/***************

dp递推关系转换为矩阵，直接dp会导致数组爆炸

矩阵快速幂，92分解

***************/

#include <bits/stdc++.h>
using namespace std;

struct matrix{
    long long mat[14][14];
};

long long fast_power(int base, int pow) {
    if (pow == 1) return base;
    if (pow % 2 == 1) return base * fast_power(base*base, pow/2);
    else return fast_power(base*base, pow/2);
}

matrix matrix_mult(matrix a, matrix b) {
    matrix result;
    for (int i=0; i<14; i++) {
        for (int j=0; j<14; j++) {
            result.mat[i][j] = 0;
            for (int k=0; k<14; k++) {
                result.mat[i][j] += (a.mat[i][k]%998244353*b.mat[k][j]%998244353)%998244353;
                result.mat[i][j] %= 998244353;
            }
        }
    }
    return result;
}

matrix matrix_pow(matrix a, int pow) {
    if (pow==1) return a;
    if (pow % 2 == 1) return matrix_mult(a, matrix_pow(matrix_mult(a, a), pow/2));
    else return matrix_pow(matrix_mult(a, a), pow/2);
}

int main() {
    int n, s;
    cin >> n;
    cin >> s;
    matrix a = {{
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0}
    }};
    matrix res = matrix_pow(a, n-1);
    int result[14] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int b[14] = {1, 2, 4, 6, 16, 26, 41, 42, 44, 46, 61, 62, 64, 66};
    int find_index;
    for (int i=0; i<14; i++) {
        if (b[i] == s) find_index = i;
    }
    cout << res.mat[find_index][1] << endl;
    return 0;
}