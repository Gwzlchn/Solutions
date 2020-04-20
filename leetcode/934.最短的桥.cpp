/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 *
 * https://leetcode-cn.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (43.14%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 10.6K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）
 * 
 * 现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。
 * 
 * 返回必须翻转的 0 的最小数目。（可以保证答案至少是 1。）
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[0,1],[1,0]]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[0,1,0],[0,0,0],[0,0,1]]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * 输出：1
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length = A[0].length <= 100
 * A[i][j] == 0 或 A[i][j] == 1
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int m_col;
    int m_row;

    bool is_position_valid(const int &x, const int &y) const
    {
        return (x >= 0 && y >= 0 && x < m_row && y < m_col);
    }

    int shortestBridge(vector<vector<int>> &A)
    {
        int ans = 0;
        if (A.empty())
            return ans;

        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};

        m_row = A.size();
        m_col = A[0].size();
        //第一个岛屿的BFS队列
        queue<pair<int, int>> first_island_queue;
        //边缘节点队列，tuple = （i，j,与第一个岛屿之间的距离）
        queue<tuple<int,int,int>> edge_queue;

        int min_dis = 0;
        for (int i = 0; i != m_row; ++i)
            for (int j = 0; j != m_col; ++j)
            {

                if (A[i][j] == 0 || A[i][j] == -1)
                    continue;

                //首次找到的必然是第一个岛屿，将其内容改成-1
                first_island_queue.push({i, j});
                A[i][j] = -1;
                //BFS 访问第一个岛屿全部内容
                while (!first_island_queue.empty())
                {
                    auto cur_pos = first_island_queue.front();
                    first_island_queue.pop();

                    int cur_i = cur_pos.first, cur_j = cur_pos.second;
                    //统计邻居1个数，如果邻居不满四个必然是第一个岛屿边缘点
                    int neighbors = 0;
                    for (int index = 0; index != 4; ++index)
                    {

                        int new_i = cur_i + di[index];
                        int new_j = cur_j + dj[index];

                        if (is_position_valid(new_i, new_j))
                        {
                            if (A[new_i][new_j] == 1)
                            {
                                first_island_queue.push({new_i, new_j});
                                A[new_i][new_j] = -1;
                            }
                            if (A[new_i][new_j] == -1)
                            {
                                neighbors++;
                            }
                        }
                    }
                    //如果是边缘点，入边缘队列
                    if (neighbors != 4)
                    {
                        edge_queue.push({cur_i, cur_j, 0});
                    }
                }

                
               
               int cur_i,cur_j,step;
               //对边界点进行BFS扩散， 这里保证一定会返回结果，实际应该用队列为空判断
                while (true)
                {
                    tie(cur_i,cur_j,step) = edge_queue.front();
                    edge_queue.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int new_i = cur_i + di[i];
                        int new_j = cur_j + dj[i];
                        if (is_position_valid(new_i, new_j))
                        {
                            if (A[new_i][new_j] == 0)
                            {
                                edge_queue.push({new_i, new_j, step + 1});
                                A[new_i][new_j] = -1;
                            }
                            // 找到第二个岛屿了
                            else if (A[new_i][new_j] == 1)
                            {
                                return step;
                            }
                        }
                    }
                }
            }
        return 0;
    }
};
