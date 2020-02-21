/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (40.16%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    79.2K
 * Total Submissions: 186.8K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<=j){
            if(!isalnum(s[i])) {i++;continue;}
            if(!isalnum(s[j])) {j--;continue;}
            
            if((s[i]| 0x20)!=(s[j]|0x20)){
                return false;
            }
            i++;j--;
        }
        return true;
    }
};
// @lc code=end

// 统一转成大写：ch & 0b11011111 简写：ch & 0xDF
// 统一转成小写：ch | 0b00100000 简写：ch | 0x20
