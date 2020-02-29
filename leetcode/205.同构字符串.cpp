/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (44.86%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    29.1K
 * Total Submissions: 61.5K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /**定义两个数组用于记录两个字符串中出现字母的位置，
        通过计数既计算了出现次数也计算了出现的位置**/
        // 128个ascii字符，所以数组大小为128
        char sc[128] = {0};
        char tc[128] = {0};
        int size = s.size();
        for(int i = 0; i<size; ++i) {
            sc[s[i]] += i+1;
            tc[t[i]] += i+1;
            if(sc[s[i]] != tc[t[i]])
                return false;
        }
        return true;
    }
};
// 30/30 cases passed (8 ms)
// Your runtime beats 91.34 % of cpp submissions
// Your memory usage beats 86.39 % of cpp submissions (9 MB)
// @lc code=end

