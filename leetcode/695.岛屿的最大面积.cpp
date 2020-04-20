/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 *
 * https://leetcode-cn.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (59.68%)
 * Likes:    257
 * Dislikes: 0
 * Total Accepted:    42K
 * Total Submissions: 66.3K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * 给定一个包含了一些 0 和 1 的非空二维数组 grid 。
 * 
 * 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被
 * 0（代表水）包围着。
 * 
 * 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
 * 
 * 
 * 
 * 示例 1:
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * 
 * 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
 * 
 * 示例 2:
 * 
 * [[0,0,0,0,0,0,0,0]]
 * 
 * 对于上面这个给定的矩阵, 返回 0。
 * 
 * 
 * 
 * 注意: 给定的矩阵grid 的长度和宽度都不超过 50。
 * 
 */

// @lc code=start
class Solution {
public:
    int m_row;
    int m_col;

    bool is_position_valid(int x,int y){
        return (x >= 0 && y >= 0 && x < m_row && y < m_col);
    }

    int cur_area = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.empty()) return ans;
        
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        

        m_row = grid.size();
        m_col = grid[0].size();
        vector<vector<bool>> visited(m_row,vector<bool>(m_col,false));
        queue<pair<int,int>> cur_island_queue;

       
        for (int i = 0; i != m_row; ++i)
            for (int j = 0; j != m_col; ++j) {
                if(grid[i][j] == 0 || visited[i][j]) continue;


                
                
                cur_island_queue.push({i,j});
                cur_area = 1;
                visited[i][j] = true;

                while (!cur_island_queue.empty()) {
                    auto cur_pos = cur_island_queue.front();
                    cur_island_queue.pop();
                    
                    
                    
                    int cur_i = cur_pos.first,cur_j = cur_pos.second;
                    for (int index = 0; index != 4; ++index) {
                        
                        //cout<<cur_i<<" "<<cur_j<<endl;
                        int new_i = cur_i + di[index];
                        int new_j = cur_j + dj[index];

                        if(is_position_valid(new_i,new_j) && !visited[new_i][new_j] && grid[new_i][new_j] == 1){
                            cur_island_queue.push({new_i,new_j});
                            
                            visited[new_i][new_j] = true;
                            cur_area++;
                        }
                        
                    }
                }

                ans = max(ans, cur_area);
                
            }
        return ans;
    }
};
// @lc code=end

