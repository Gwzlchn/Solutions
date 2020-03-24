/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (29.83%)
 * Likes:    560
 * Dislikes: 0
 * Total Accepted:    47.1K
 * Total Submissions: 157.1K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())return 0;
        
        int n = s.size();
        vector<int> dp(n,0);
        int res_max = 0;
        for(int i=1; i<n;i++){
            //当前是 （
            if(s[i] == '(') continue;

            //当前是），前一个是（
            if(s[i-1] == '('){

                dp[i] =(i<=2? 0:dp[i-2])+ 2;
            }
            //当前是），前一个是）,找到前一个）匹配的（，其之前仍然是（
            //前一个），及其配对（，长度是dp[i-1]
            //再前面那个（之前的长度是dp[i-dp[i-1]-2]，再加上现在配对的（）长度，即2
            else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='(' ){
    
                int temp = i-dp[i-1] >=2 ? dp[i-dp[i-1]-2]:0;
                dp[i] = dp[i-1] + temp + 2;
            }
            res_max = max(dp[i],res_max);
            
            
        }
       

 
        return res_max;
    }
};
// @lc code=end

