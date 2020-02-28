/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 *
 * https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation/description/
 *
 * algorithms
 * Easy (62.18%)
 * Likes:    32
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 12.3K
 * Testcase Example:  '842\n888'
 *
 * 给定两个整数 L 和 R ，找到闭区间 [L, R] 范围内，计算置位位数为质数的整数个数。
 * 
 * （注意，计算置位代表二进制表示中1的个数。例如 21 的二进制表示 10101 有 3 个计算置位。还有，1 不是质数。）
 * 
 * 示例 1:
 * 
 * 
 * 输入: L = 6, R = 10
 * 输出: 4
 * 解释:
 * 6 -> 110 (2 个计算置位，2 是质数)
 * 7 -> 111 (3 个计算置位，3 是质数)
 * 9 -> 1001 (2 个计算置位，2 是质数)
 * 10-> 1010 (2 个计算置位，2 是质数)
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: L = 10, R = 15
 * 输出: 5
 * 解释:
 * 10 -> 1010 (2 个计算置位, 2 是质数)
 * 11 -> 1011 (3 个计算置位, 3 是质数)
 * 12 -> 1100 (2 个计算置位, 2 是质数)
 * 13 -> 1101 (3 个计算置位, 3 是质数)
 * 14 -> 1110 (3 个计算置位, 3 是质数)
 * 15 -> 1111 (4 个计算置位, 4 不是质数)
 * 
 * 
 * 注意:
 * 
 * 
 * L, R 是 L <= R 且在 [1, 10^6] 中的整数。
 * R - L 的最大值为 10000。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
    
        vector<bool> isPrime(33,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i=2;i<33;i++){
            if(isPrime[i]){
                for(int j = 2;j*i<33;j++){
                    isPrime[i*j] = false;
                }
            }else{
                continue;
            }
        }
        int res = 0;
        for(int i=L;i<=R;i++){
            int cur = countBit(i);
            //cout << cur<<" ";
            if(isPrime[cur])
                res++;
        }
        return res;
    }

    int countBit(int x){
        int b;
        for (b = 0; x != 0; x &= (x-1))
            b++;
        return b;

    }
    
};

// //200/200 cases passed (8 ms)
// Your runtime beats 94.88 % of cpp submissions
// Your memory usage beats 27.49 % of cpp submissions (8.4 MB)
// @lc code=end

