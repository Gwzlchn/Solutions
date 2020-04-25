/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (57.26%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    53.4K
 * Total Submissions: 91.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    int m_size;
    vector<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
       
        m_size = nums.size();
        vector<bool> visited(m_size,false);

        vector<int> cur_per;
        sort(nums.begin(),nums.end());
        dfs(visited,cur_per,nums);

        return res;
    }

    void dfs(vector<bool>& visited,vector<int>& cur_per,const vector<int>& nums){
        // 满足结束条件
        if(cur_per.size() == m_size){
            
            res.push_back(cur_per);
            return;
        }

        for(int i=0;i<m_size;i++){
            //减枝条件
            if(visited[i] || (i>0  && nums[i] == nums[i-1] && !visited[i-1]))
                continue;

                
                
            // 做出选择
            cur_per.push_back(nums[i]);
            visited[i] = true;
            // 下一层选择
            dfs(visited,cur_per,nums);
            
            //撤销选择
            cur_per.pop_back();
            visited[i] = false;

        }
        return;
    }
};
// @lc code=end

