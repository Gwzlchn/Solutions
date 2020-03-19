/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (52.13%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    26.3K
 * Total Submissions: 49K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(58,0);
        for(char ch:s)
            cnt[ch-'A']++;

        size_t odd = count_if(cnt.begin(),cnt.end(),[](int i){ return i%2 == 1;});
        size_t sum = accumulate(cnt.begin(),cnt.end(),0);
        return (odd==0)?sum:sum-odd+1;
    }
};
// @lc code=end

