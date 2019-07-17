/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (49.17%)
 * Likes:    219
 * Dislikes: 0
 * Total Accepted:    30.6K
 * Total Submissions: 61.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
 //  √ Your runtime beats 75.39 % of cpp submissions
 // √ Your memory usage beats 42.66 % of cpp submissions (8.7 MB)

 //思路：类似链表求和
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        ret.reserve(a.size()+b.size());
        int i = a.size()-1,j=b.size()-1;
        int c = 0;
        while(i>=0 || j>=0){
            int aa = (i<0)?0:(a[i]-'0');i--;
            int bb = (j<0)?0:(b[j]-'0');j--;
            c += aa + bb;
            //和1 做与，结果为2的时候入字符串的是0
            ret.push_back((c&1)+'0');
            c >>= 1;
        }
        if(c){
            ret.push_back('1');
        }
        reverse(ret.begin(),ret.end());

        return ret;
    }
};

