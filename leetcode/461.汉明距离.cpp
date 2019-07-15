/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 *
 * https://leetcode-cn.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (70.62%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    21.4K
 * Total Submissions: 30.2K
 * Testcase Example:  '1\n4'
 *
 * 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
 * 
 * 给出两个整数 x 和 y，计算它们之间的汉明距离。
 * 
 * 注意：
 * 0 ≤ x, y < 2^31.
 * 
 * 示例:
 * 
 * 
 * 输入: x = 1, y = 4
 * 
 * 输出: 2
 * 
 * 解释:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 
 * 上面的箭头指出了对应二进制位不同的位置。
 * 
 * 
 */

 //思路：x y 异或 算1 的个数
class Solution {
public:
    int hammingDistance(int x, int y) {
        int xxor = x^y;
        int cnt = 0,total = 32,mask = 0x01;
        while(total--){
            if(xxor & mask)cnt++;
            xxor >>= 1;
        }
        return cnt;
    }
};

