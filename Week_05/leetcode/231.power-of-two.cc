// 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

// 思路一：每次除以二（右移一位）判断余数是否为 0

// 思路二：2 的幂只有一个比特位为 1
//         利用 n & (n-1) 可消去最低位 1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 ? 0 == (n & (n - 1)) : false;
    }
};
