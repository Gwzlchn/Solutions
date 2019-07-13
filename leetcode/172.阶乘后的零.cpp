/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (38.72%)
 * Likes:    134
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 36.6K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */

 //思路： 5倍数的个数，25倍数个数，125倍数个数……
class Solution {
public:
    int trailingZeroes(int n) {
        int ret =0;
        while(n)
        {
            
            n/=5;
            ret += n;
        }
        return ret;
    }
};

