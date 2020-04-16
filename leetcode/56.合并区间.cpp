/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (40.53%)
 * Likes:    302
 * Dislikes: 0
 * Total Accepted:    57.7K
 * Total Submissions: 142.5K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //vector<vector<int>> res;
        if(intervals.empty())return vector<vector<int>>();
        sort(intervals.begin(),intervals.end());
        
        //res.emplace_back(intervals[0]);
        vector<vector<int>> ret;
        for (auto &i : intervals) {
            if (ret.empty() || i[0] > ret.back()[1]) ret.push_back(i);
            else ret.back()[1] = max(i[1], ret.back()[1]);
        }
        return ret;
            //找第一个区域的左区间大于现在的右区间
            //若小于，则合并
        }
        
            
};
// @lc code=end

