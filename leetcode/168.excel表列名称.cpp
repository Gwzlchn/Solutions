/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (33.25%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 29.3K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */
class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while(n){
            int k = n%26;
            if(k == 0){
                n-=26;
                k=26;
            }
            char c = (char)((k-1) + (int)'A');
            ret = c + ret;
            n /= 26;
        }
        return ret;
    }
};

