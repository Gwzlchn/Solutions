/*
 * @lc app=leetcode.cn id=522 lang=cpp
 *
 * [522] 最长特殊序列 II
 *
 * https://leetcode-cn.com/problems/longest-uncommon-subsequence-ii/description/
 *
 * algorithms
 * Medium (31.58%)
 * Likes:    30
 * Dislikes: 0
 * Total Accepted:    2.6K
 * Total Submissions: 7.8K
 * Testcase Example:  '["aba","cdc","eae"]'
 *
 * 给定字符串列表，你需要从它们中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。
 * 
 * 子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。
 * 
 * 输入将是一个字符串列表，输出是最长特殊序列的长度。如果最长特殊序列不存在，返回 -1 。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: "aba", "cdc", "eae"
 * 输出: 3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有给定的字符串长度不会超过 10 。
 * 给定字符串列表的长度将在 [2, 50 ] 之间。
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool IsSunStr(string s1, string s2)
    {
        int cIndex = 0;
        bool flag = true;
        for (int i = 0; i < s1.size(); i++) {
            cIndex = s2.find(s1[i], cIndex);
            if (cIndex == s2.npos) {
                flag = false;
                break;    
            }
            cIndex++;
        }
        return flag;
    }
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        for (int i = 0; i < strs.size(); i++) {
            bool flag = true;
            for (int j = 0; j < strs.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (IsSunStr(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                int length =  strs[i].size();
                ans = max(ans, length);
            }
        }
        return ans;
    }
};


// @lc code=end

