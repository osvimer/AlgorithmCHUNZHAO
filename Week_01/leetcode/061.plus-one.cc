// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。

// 思路：末位 +1 从后往前处理进位并原地更新结果
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1; //小技巧：省去末位判断
        int sum = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            if (0 == carry) { // 优化操作：遇到不进位，直接返回结果
                return digits;
            }
        }
        digits.insert(digits.begin(), 1); // 首位进位，则需要插入 1
        return digits;
    }
};