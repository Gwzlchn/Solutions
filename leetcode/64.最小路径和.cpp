/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (64.80%)
 * Likes:    411
 * Dislikes: 0
 * Total Accepted:    69.3K
 * Total Submissions: 106.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start

// grid(i,j)=grid(i,j)+min(grid(i+1,j),grid(i,j+1))
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col= grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0) continue;
                //左增加量,第一列特殊
                int left_add = j==0? INT_MAX:grid[i][j-1];
                //上增加量，第一行特殊
                int up_add = i==0? INT_MAX:grid[i-1][j];

                grid[i][j] += min(left_add,up_add); 
                
            }
        }
        return grid[row-1][col-1];
    }
};
// @lc code=end

