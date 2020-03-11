/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode-cn.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (34.01%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    13.3K
 * Total Submissions: 39K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 
 * 
 */

// @lc code=start

//前一个为空格且自身不是空格的数量
class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if((i == 0 || s[i-1] == ' ' )&& s[i] != ' ')cnt++;
        }
        return cnt;
    }
};
// @lc code=end

