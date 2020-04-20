/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (54.34%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    52.6K
 * Total Submissions: 94.6K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */

// @lc code=start
class Solution 
{
public:
    /*返回小于n的平方序列: 1, 4, 9...*/
    vector<int> getSquares(int n)
    {
        vector<int> res;
        for(int i = 1; i*i <= n; ++i)
        {
            res.push_back(i*i);
        }
        //reverse(res.begin(), res.end());
        return res;
    }

    int numSquares(int n) 
    {
        vector<int> squares = getSquares(n);
        vector<bool> visited(n+1);    //记录已访问过的节点
        queue<int> q;

        q.push(n);
        int res = 0;
        visited[n] = true;
        while(!q.empty())
        {
            int size = q.size();
            res++;
            while(size--)
            {
                int curr = q.front();
                q.pop();
                /*每次跨越的间隔为平方数*/
                for(int num: squares)
                {
                    int next = curr - num;
                    if(next < 0)
                    {
                        break;
                    }
                    if(next == 0)
                    {
                        return res;
                    }
                    if(visited[next])
                    {
                        continue;
                    }
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        return n;
    }
};

// @lc code=end

