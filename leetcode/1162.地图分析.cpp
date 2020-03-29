/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 *
 * https://leetcode-cn.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (38.34%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    16.7K
 * Total Submissions: 36.8K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * 你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1
 * 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
 * 
 * 我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 -
 * x1| + |y0 - y1| 。
 * 
 * 如果我们的地图上只有陆地或者海洋，请返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[[1,0,1],[0,0,0],[1,0,1]]
 * 输出：2
 * 解释： 
 * 海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[[1,0,0],[0,0,0],[0,0,0]]
 * 输出：4
 * 解释： 
 * 海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] 不是 0 就是 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //queue
        queue<pair<int,int>> bfs;
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){
               if(grid[i][j] == 1)
                    bfs.push({i,j});
           }
       }

       bool has_ocean = false;
       pair<int,int> point = {-1,-1};
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        while(!bfs.empty()){
            point = bfs.front();
            bfs.pop();
            int x = point.first,y=point.second;
            for(int i =0;i<4;i++){
                int cur_x = x + dx[i],cur_y = y+dy[i];
                if(cur_x<0 || cur_y<0 || \
                    cur_x>=grid.size() || cur_y>=grid[0].size() ||\
                     grid[cur_x][cur_y] >= 1)
                    continue;
                grid[cur_x][cur_y] = grid[x][y] + 1;
                bfs.push({cur_x,cur_y});
                has_ocean = true;
            }
        }

        if(!has_ocean || point == make_pair(-1,-1) ){
            return -1;
        }
        return grid[point.first][point.second] - 1;
       
    }
};
// @lc code=end

