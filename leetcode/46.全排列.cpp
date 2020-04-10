/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.24%)
 * Likes:    598
 * Dislikes: 0
 * Total Accepted:    100.6K
 * Total Submissions: 134.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    int m_size;
    vector<vector<int>> permute(vector<int>& nums) {
        m_size = nums.size();
        vector<vector<int>> res;
        vector<int> one_permute;
        dfs(res,one_permute,nums);
        return res;
    }

    void dfs(vector<vector<int>>& res,vector<int>& cur_permute,const vector<int>& nums){
        if(cur_permute.size() == m_size){
            res.push_back(cur_permute);
            return;
        }

        for(int i=0;i<m_size;i++){
            if(find(cur_permute.begin(),cur_permute.end(),nums[i]) == cur_permute.end()){
                cur_permute.push_back(nums[i]);
                dfs(res,cur_permute,nums);
                cur_permute.pop_back();
            }
        }
        return;
    }
};
// @lc code=end

