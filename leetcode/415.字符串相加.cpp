/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (49.62%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    25.6K
 * Total Submissions: 51.5K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = 0,j = 0;
        int m = num1.size()-1,n = num2.size()-1;
        string res = "";
        bool flag = false;
        while(m>=0 && n>=0){
            int cur = num1[m] + num2[n] - '0' - '0';
            cur = (flag)? (cur+1) : cur;
            res.push_back((cur%10) + '0');
            flag = cur/10;
            m--;n--;
        }

        while(m>=0){
            int cur = num1[m]  - '0' ;
            cur = (flag)? (cur+1) : cur;
            res.push_back((cur%10) + '0');
            flag = cur/10;
            m--;
        }

         while(n>=0){
            int cur =  num2[n] - '0' ;
            cur = (flag)? (cur+1) : cur;
            res.push_back((cur%10) + '0');
            flag = cur/10;
            n--;
        }

        if(flag)res.push_back('1');

        reverse(res.begin(),res.end());
       
        return res;

    }
};
// @lc code=end

