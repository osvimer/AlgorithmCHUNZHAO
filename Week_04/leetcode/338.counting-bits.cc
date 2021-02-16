// 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，
// 计算其二进制数中的 1 的数目并将它们作为数组返回。

class Solution {
public:
    // 对于所有的数字，只有两类：
    // 奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
    //      举例:  0 = 0       1 = 1
    // 偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。
    //      因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，
    //      所以 1 的个数是不变的。
    //      举例： 2 = 10      4 = 100       8 = 1000
    // 另外，0 的 1 个数为 0，于是就可以根据奇偶性开始遍历计算了。
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        result[0] = 0;
        for (int i = 1; i <= num; ++i) {
            if (i % 2) {
                result[i] = result[i - 1] + 1;
            } else {
                result[i] = result[i / 2];
            }
        }
        return result;
    }
};