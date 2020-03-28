/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (39.08%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    27.7K
 * Total Submissions: 70.3K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int col = matrix[0].size();
        int max_res = 0,prev = 0; //prev = dp[i][j-1]
        vector<int> dp(col+1,0);

//dp 表示上一行的状态，prev表示当前位置左侧的最大值
       for(int i=0;i<matrix.size();i++){
           for(int j=1;j<=col;j++){
               int temp = dp[j];
               if(matrix[i][j-1] == '1') {
                   dp[j] = min({dp[j-1],dp[j],prev}) + 1;
                   max_res = max(max_res,dp[j]);
                   //cout<<max_res<<endl;
               }else{
                   dp[j] = 0;
               }
               prev = temp;
               
           }
           prev = 0;
       }
       return max_res*max_res;
    }
};
// @lc code=end

