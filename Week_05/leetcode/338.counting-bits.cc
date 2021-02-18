// 给定一个非负整数 num。
// 对于 0 ≤ i ≤ num 范围中的每个数字 i ，
// 计算其二进制数中的 1 的数目并将它们作为数组返回。
// 进阶:
//    给出时间复杂度为O(n*sizeof(integer))的解答非常容易。
//    但你可以在线性时间O(n)内用一趟扫描做到吗？
//    要求算法的空间复杂度为O(n)。
//    你能进一步完善解法吗 ？
//    要求在 C++ 或任何其他语言中不使用任何内置函数来执行此操作。
// https://leetcode-cn.com/problems/counting-bits

// 思路一：分奇偶判断
// 对于所有的数字，只有两类：
// 奇数：二进制表示中，奇数比前面那个偶数多一个 1，因为多的就是最低位的 1。
// 偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。
//       因最低位是 0，除以 2 就是右移一位，即把末位 0 抹掉，1 的个数不变。
class Solution {
public:
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

// 思路二：利用 n & (n-1) 消去 n 最后一个 1 的性质，迭代计算
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        result[0] = 0;
        for (int i = 1; i <= num; ++i) {
            result[i] = result[i & (i - 1)] + 1;
        }
        return result;
    }
};
