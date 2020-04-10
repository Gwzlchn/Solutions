/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 *
 * https://leetcode-cn.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (50.40%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 16.2K
 * Testcase Example:  '2'
 *
 * 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10^n 。
 * 
 * 示例:
 * 
 * 输入: 2
 * 输出: 91 
 * 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0){
            return 1;
        }

        if(n == 1){
            return 10;
        }

        
        int prev = 9;
        int sum = 10;
        for (int i = 2; i <= min(n, 10);i++){
           int temp = prev * (10 - (i - 1));
            sum += temp;
            prev = temp;
        }

        return sum;
    }
};


// @lc code=end

