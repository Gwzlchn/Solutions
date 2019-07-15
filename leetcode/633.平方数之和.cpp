/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 *
 * https://leetcode-cn.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (30.89%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 21.4K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c。
 * 
 * 示例1:
 * 
 * 
 * 输入: 5
 * 输出: True
 * 解释: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: 3
 * 输出: False
 * 
 * 
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        long int a = 1;
        long int b = sqrt(c)+1;
        if((b-1)*(b-1) == c) return true;
        while(a <= b) {
            long long int temp = a*a + b*b;
            if(temp < c) {
                a++;
            }
            else if(temp > c) {
                b--;
            }
            else {
                return true;
            }
        }
        return false;
    }
};


