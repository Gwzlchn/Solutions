/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (49.30%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    27K
 * Total Submissions: 54.6K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        string ret = s;
        while(i < j){
            while(i<j && !isVowel(ret[i])) i++;
            while(i<j && !isVowel(ret[j])) j--;

            swap(ret[i],ret[j]);
            i++;j--;
        }

        return ret;
    }


    bool isVowel(char ch){
        switch (ch){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
        }
        return false;
    }
};
// @lc code=end

