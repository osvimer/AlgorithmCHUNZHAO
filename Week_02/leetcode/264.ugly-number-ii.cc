// 编写一个程序，找出第 n 个丑数。
// 丑数就是质因数只包含 2, 3, 5 的正整数。
// 示例:
//      输入: n = 10
//      输出: 12
//      解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
// 说明:  
//      1 是丑数。
//      n 不超过1690。
// 链接：https://leetcode-cn.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n);
        int two = 0, three = 0, five = 0;
        arr[0] = 1;
        for (int i = 1; i < n; ++i) {
            int t1 = arr[two] * 2;
            int t2 = arr[three] * 3;
            int t3 = arr[five] * 5;
            arr[i] = min(min(t1, t2), t3);
            if (t1 == arr[i]) two++;
            if (t2 == arr[i]) three++;
            if (t3 == arr[i]) five++;
        }
        return arr[n-1];
    } 
};