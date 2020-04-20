/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (47.25%)
 * Likes:    457
 * Dislikes: 0
 * Total Accepted:    75.1K
 * Total Submissions: 156.7K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */


// @lc code=start
class Solution {
public:
    //验证坐标正确
    bool is_valid(int row,int col,int new_x,int new_y){
        return new_x>=0 &&  new_x < row && new_y >=0 && new_y < col;
    }



    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        if(row==0) return 0;

        int col = grid[0].size();
        //坐标的队列，BFS
        queue<pair<int,int>> bfs_queue;
        int res = 0;

        int dx[] = {0,1,-1,0};
        int dy[] = {1,0,0,-1};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                if(grid[i][j] == '0') continue;
                //如果是1，入队
                bfs_queue.push({i,j});
                res++;
                //在1周围找所有的1，找到1置零，避免重复
                while(!bfs_queue.empty()){
                    auto cur_pos = bfs_queue.front();
                    bfs_queue.pop();
                    
                    for(int i=0;i<4;i++){
                        int new_x = cur_pos.first + dx[i];
                        int new_y = cur_pos.second + dy[i];
                        if(is_valid(row,col,new_x,new_y) && grid[new_x][new_y] == '1'){
                            bfs_queue.push({new_x,new_y});
                            grid[new_x][new_y] = '0';
                        }
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

