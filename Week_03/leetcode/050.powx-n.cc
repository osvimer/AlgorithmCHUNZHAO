// 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）

// 思路一：循环迭代，每次乘 X，时间复杂度 O(n)
// 思路二：分治；转而求 pow(x, n/2), 然后组合（平方），注意 N 的奇偶
class Solution {
public:
    double myPow(double x, int n) {
        if (0 == x) return 0;
        if (0 == n) return 1;
        return n > 0 ? fastPow(x, n) : 1.0f / fastPow(x, -1L * n);
    }
    double fastPow(double x, long n) {
        if (1 == n) return x;
        double half = fastPow(x, n / 2);
        return (n % 2) ? (x * half * half) : (half * half);
    }
};