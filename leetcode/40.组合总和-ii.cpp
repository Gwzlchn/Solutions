/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.52%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    53.1K
 * Total Submissions: 86.6K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    int candidates_size;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        candidates_size = candidates.size();
        sort(candidates.begin(),candidates.end());

        vector<int> candidate_array;
        getCombination(res, candidates, candidate_array, 0, target, 0);
        return res;
    }
    void getCombination(vector<vector<int>> &res,const vector<int>& candidates, vector<int> &candidate_array, \
                        const int& partial_sum, const int &target, const int& idx){
        //退出条件
        if(partial_sum == target){
            res.push_back(candidate_array);
        // 减枝
        }else if(partial_sum > target){
            return;
        }else{
            // partial_sum < target
            // 不能在idx 之后做选择，否则每次第一个idx 被错过递归
            for(int i = idx; i <candidates_size; ++i){
                //1. 因为已经排序，当前比目标大，之后一定也比目标大，直接减枝
                if(candidates[i] > target) break;
                // 1、i > index 表明剪枝的分支一定不是当前层的第 1 个分支
                // 2、input[i - 1] == input[i] 表明当前选出来的数等于当前层前一个分支选出来的数
                // 因为前一个分支的候选集合一定大于后一个分支的候选集合
                // 故后面出现的分支中一定包含了前面分支出现的结果，因此剪枝
                if(i>idx && candidates[i] == candidates[i-1]) continue;

                
                // 加入路径
                candidate_array.push_back(candidates[i]);
                // 下一层回溯减枝
                getCombination(res, candidates, candidate_array, partial_sum + candidates[i], target, i+1);
                // 退出路径
                candidate_array.pop_back();
            }
        }
    }
};
// @lc code=end

