// 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
// 示例 1:
//    输入: 1
//    输出: true
//    解释: 2^0 = 1
// https://leetcode.com/problems/power-of-two/submissions/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        else if (n <= 2) return true;
        return (0 == n % 2) && isPowerOfTwo(n / 2);
    }
};

// 减少递归函数内的判断
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return helper(n);
    }
    bool helper(int n) {
        if (n <= 2) return true;
        return (0 == n % 2) && helper(n / 2);
    }
};
