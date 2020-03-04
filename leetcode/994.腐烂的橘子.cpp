/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 *
 * https://leetcode-cn.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Easy (45.12%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 26.8K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的网格中，每个单元格可以有以下三个值之一：
 * 
 * 
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 * 
 * 
 * 每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
 * 
 * 返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[2,1,1],[0,1,1],[1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
 * 
 * 
 * 示例 3：
 * 
 * 输入：[[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] 仅为 0、1 或 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    struct pos{
        int _x;
        int _y;
        int _min;
        pos(int x,int y, int min){
            _x = x;_y = y;_min = min;
        }
    };



    int orangesRotting(vector<vector<int>>& grid) {
        int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

        int R = grid.size();
        int C = grid[0].size();
        int minute = 0;
        queue<pos*> rotten = queue<pos*>();

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j] == 2)
                    rotten.push(new pos(i,j,minute));
            }
        }

        while(!rotten.empty()){
            pos* cur_pos = rotten.front();
            rotten.pop();
            minute = cur_pos->_min;

            for(int i = 0;i<4;i++){
                int newX = cur_pos->_x + dir[i][0];
                int newY = cur_pos->_y + dir[i][1];
                if(newX >= 0 && newX < R &&
                    newY >=0 && newY < C &&
                    grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        rotten.push(new pos(newX,newY,minute+1));
                    }
            }
        }

        for(auto i : grid){
            for(int j : i){
                if( j == 1)return -1;
            }
        }

        return minute;
    }
};
// @lc code=end

