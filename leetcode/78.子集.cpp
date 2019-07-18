/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (73.97%)
 * Likes:    279
 * Dislikes: 0
 * Total Accepted:    25.8K
 * Total Submissions: 34.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

 //位运算：顺序无关紧要
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int set_size = nums.size(),ret_size = 1<<set_size;
        if(set_size==0)return {};
        vector<vector<int>> ret;
        
        for(int i=0;i<ret_size;i++){
            vector<int> cur = {};
            for(int j=0;j<set_size;j++){
                if((1<<j)&i) cur.push_back(nums[j]);
            }
            ret.push_back(cur);
        }
        return ret;
    }
};

