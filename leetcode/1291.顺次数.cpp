/*
 * @lc app=leetcode.cn id=1291 lang=cpp
 *
 * [1291] 顺次数
 *
 * https://leetcode-cn.com/problems/sequential-digits/description/
 *
 * algorithms
 * Medium (46.56%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    2.8K
 * Total Submissions: 5.9K
 * Testcase Example:  '100\n300'
 *
 * 我们定义「顺次数」为：每一位上的数字都比前一位上的数字大 1 的整数。
 * 
 * 请你返回由 [low, high] 范围内所有顺次数组成的 有序 列表（从小到大排序）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输出：low = 100, high = 300
 * 输出：[123,234]
 * 
 * 
 * 示例 2：
 * 
 * 输出：low = 1000, high = 13000
 * 输出：[1234,2345,3456,4567,5678,6789,12345]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 10 <= low <= high <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            int num = i;
            for (int j = i + 1; j <= 9; ++j) {
                num = num * 10 + j;
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
                if(num > high) continue;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;


    }
};
// @lc code=end

