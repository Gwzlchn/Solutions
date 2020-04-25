/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (48.38%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 63.8K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        

        string s = string("123456789").substr(0,n);
        string res = "";
        // k-1 
        k--;
        for(int i=n-1;i>=0;i--){
            int fac = factorial(i);

            int cur_idx = k/fac;

            char c = s[cur_idx];
            s.erase(s.begin() + cur_idx);
            res.push_back(c);

            k = k%fac;
        }
        return res;
    }

    //计算阶乘
    int factorial(int n){
         
        return (n==1 || n==0) ? 1: n * factorial(n - 1);  
    }
};
// @lc code=end

