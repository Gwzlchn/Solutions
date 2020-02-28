/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (57.15%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 19.7K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * s = "abcd"
 * t = "abcde"
 * 
 * 输出：
 * e
 * 
 * 解释：
 * 'e' 是那个被添加的字母。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for(char& ss:s){
            res ^= ss;
        }
        for(char& tt:t){
            res ^= tt;
        }
        return res;
    }
};

// 54/54 cases passed (8 ms)
// Your runtime beats 53.83 % of cpp submissions
// Your memory usage beats 14.14 % of cpp submissions (9.1 MB)
// @lc code=end

