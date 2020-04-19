/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 *
 * https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (61.67%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 6.8K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个字符串s1, s2，找到使两个字符串相等所需删除字符的ASCII值的最小和。
 * 
 * 示例 1:
 * 
 * 
 * 输入: s1 = "sea", s2 = "eat"
 * 输出: 231
 * 解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
 * 在 "eat" 中删除 "t" 并将 116 加入总和。
 * 结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s1 = "delete", s2 = "leet"
 * 输出: 403
 * 解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
 * 将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
 * 结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
 * 如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
 * 
 * 
 * 注意:
 * 
 * 
 * 0 < s1.length, s2.length <= 1000。
 * 所有字符串中的字符ASCII值在[97, 122]之间。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int s1_len = s1.size(),s2_len = s2.size();


        vector<vector<int>> dp(s1_len+1,vector<int>(s2_len+1,0));

        for(int i=1;i<=s1_len;i++){
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        for(int j=1;j<=s2_len;j++){
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }

        for(int i=1;i<=s1_len;i++){
            for(int j=1;j<=s2_len;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int temp1 = dp[i-1][j-1] + s1[i-1]+s2[j-1];
                    int temp2 = dp[i-1][j] + s1[i-1];
                    int temp3 = dp[i][j-1] + s2[j-1];
                    dp[i][j] = min({temp1,temp2,temp3});
                }
            }
        }

        return dp[s1_len][s2_len];

    }
};
// @lc code=end

