/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 *
 * https://leetcode-cn.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (51.38%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    25.4K
 * Total Submissions: 49.1K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 
 * 示例 1:
 * 
 * 输入: [3,0,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 
 * 
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 * 
 */
//  仍然，做异或，但有点慢
//  √ Accepted
//   √ 122/122 cases passed (32 ms)
//   √ Your runtime beats 60.47 % of cpp submissions
//   √ Your memory usage beats 44.18 % of cpp submissions (9.8 MB)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        for(int i=0;i<nums.size();i++){
            ret ^= i;ret^=nums[i];
        }
        return ret^nums.size();
    }
};

