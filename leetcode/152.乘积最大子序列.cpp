/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (37.43%)
 * Likes:    425
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 110.2K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int cur_min = 1,cur_max = 1;
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0) swap(cur_min,cur_max);

            cur_min = min(cur_min*nums[i],nums[i]);
            cur_max = max(cur_max*nums[i],nums[i]);

            res = max(res,cur_max);
            //cout<<res<<endl;
        }
        return res;
    }
};
// @lc code=end

