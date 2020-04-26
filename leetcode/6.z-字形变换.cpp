/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (46.99%)
 * Likes:    643
 * Dislikes: 0
 * Total Accepted:    120.6K
 * Total Submissions: 253.5K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;

        vector<string> res_vec(numRows);
        // 向上还是向下的标志
        bool flag = true;
        int row_idx = 0;
        for(int i=0;i<s.size();i++){

            res_vec[row_idx].push_back(s[i]);
            // 如果到了转折点，则将flag 反转一次
            if(i>0 && i%(numRows-1)==0) flag ^= 1;

            row_idx += (flag)? 1:-1;
            
        }

        string res;
        for(auto& s:res_vec){
            res += s;
        }
        return res;
    }
};
// @lc code=end

