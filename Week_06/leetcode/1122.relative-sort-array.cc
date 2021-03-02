// 给你两个数组，arr1 和 arr2，
//    arr2 中的元素各不相同
//    arr2 中的每个元素都出现在 arr1 中
// 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。
// 未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
// 示例：
//    输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
//    输出：[2,2,2,1,4,3,3,9,6,7,19]
//
// 提示：
//    1 <= arr1.length, arr2.length <= 1000
//    0 <= arr1[i], arr2[i] <= 1000
//    arr2 中的元素 arr2[i] 各不相同
//    arr2 中的每个元素 arr2[i] 都出现在 arr1 中
//
// https://leetcode-cn.com/problems/relative-sort-array

// 思路一：先用哈希表统计 arr1 中的词频；然后将在出现在 arr2 中的数字
//         按词频重复若干次依次加入排序数组中；最后将放入未出现在 arr2
//         中的数字，并对其进行排序。
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result(arr1);
        if (arr1.empty() || arr2.empty()) return result;
        unordered_map<int, int> frequency;
        for (int num : arr1) {
            frequency[num]++;
        }
        int i = 0;
        for (int num : arr2) {
            while (frequency[num]) {
                result[i++] = num;
                frequency[num]--;
            }
            frequency.erase(num);
        }
        int diff_start = i; //记录未在 arr2 中出现的数字的起始位置
        for (auto& p : frequency) {
            while (p.second) {
                result[i++] = p.first;
                p.second--;
            }
        }
        // 对尾部未出现在 arr2 中的的部分进行排序
        sort(result.begin() + diff_start, result.end());
        return result;
    }
};
