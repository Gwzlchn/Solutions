/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 *
 * https://leetcode-cn.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (47.82%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 13.6K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: "sea", "eat"
 * 输出: 2
 * 解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定单词的长度不超过500。
 * 给定单词中的字符只含有小写字母。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1_len = word1.size(),s2_len = word2.size();


        vector<vector<int>> dp(s1_len+1,vector<int>(s2_len+1,0));

        for(int i=1;i<=s1_len;i++){
            dp[i][0] = i;
            //cout<<dp[i][0]<<endl;
        }
        for(int j=1;j<=s2_len;j++){
            dp[0][j] = j;
            //cout<<dp[0][j]<<endl;
        }

        for(int i=1;i<=s1_len;i++){
            for(int j=1;j<=s2_len;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{

                    dp[i][j] = min(dp[i-1][j] ,dp[i][j-1] )+1;
                }
            }
        }

        return dp[s1_len][s2_len];

    }
};




// @lc code=end

