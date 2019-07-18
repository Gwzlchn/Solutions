/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (45.92%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 21.8K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 16
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */
 //二进制中只有一个1（1在奇数位置），
 // 并且1后面跟了偶数个0； 因此问题可以转化为判断1后面是否跟了偶数个0就可以了。
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0 || num & (num-1))return false;
        //看1是不是在奇数位上
        return num & 0x55555555;
    }
};

