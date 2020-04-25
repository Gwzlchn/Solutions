/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (73.08%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    46.4K
 * Total Submissions: 63.1K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
vector<vector<int>> res;
int m_n;
int m_k;
    vector<vector<int>> combine(int n, int k) {
        m_n = n;
        m_k= k;
        vector<int> cur_combine;
        backtrace(cur_combine, 1);

        return res;
    }

    void backtrace(vector<int>& cur_combine,int idx){
        if(cur_combine.size() == m_k ){
            res.push_back(cur_combine);
            return;
        }

        for(int i=idx;i<=m_n;i++){
            cur_combine.push_back(i);
            //cout<<i<<endl;
            backtrace(cur_combine, i+1);
            cur_combine.pop_back();
        }
        return;
    }
};
// @lc code=end

