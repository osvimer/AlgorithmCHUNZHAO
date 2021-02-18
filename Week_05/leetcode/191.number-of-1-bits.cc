// 编写一个函数，输入是一个无符号整数（以二进制串的形式），
// 返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。

// 思路一：从低位到高位，依次取出第 i 位

// 思路二：利用 n & (n -1) 可消掉 n 的最末位 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return n == 0 ? 0 : 1 + hammingWeight(n & (n - 1));
    }
};
