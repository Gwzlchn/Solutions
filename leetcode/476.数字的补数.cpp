/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 *
 * https://leetcode-cn.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (67.73%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    17.7K
 * Total Submissions: 26K
 * Testcase Example:  '5'
 *
 * 给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。
 * 
 * 注意:
 * 
 * 
 * 给定的整数保证在32位带符号整数的范围内。
 * 你可以假定二进制数不包含前导零位。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: 5
 * 输出: 2
 * 解释: 5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 1
 * 输出: 0
 * 解释: 1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0。
 * 
 * 
 */

// @lc code=start
//思路： 5 = 0000 0101
//     idx = 0000 0111
class Solution {
public:
    int findComplement(int num) {
        int c = num;
        int idx = 0;
        while(c){
            idx = (idx<<1) +1;
            c >>= 1;
        }

        return idx ^ num;
    }
};
// @lc code=end

// 149/149 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 28.32 % of cpp submissions (8.3 MB)
