/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 *
 * https://leetcode-cn.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (51.69%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    23K
 * Total Submissions: 42.7K
 * Testcase Example:  '1\n2'
 *
 * 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
 * 
 * 示例 1:
 * 
 * 输入: a = 1, b = 2
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = -2, b = 3
 * 输出: 1
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        //a & b 是产生进位的位，<<1 是应该进到位

        while(b != 0){
            int sum   = a ^ b;
            int carry = ((unsigned int)(a & b) << 1);
            a = sum;
            b = carry;
        }
        return a; 
    }
};

// @lc code=end
