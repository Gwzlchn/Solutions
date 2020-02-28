/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (28.74%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    44K
 * Total Submissions: 135.7K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */

// @lc code=start
//埃拉托斯特尼筛法
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> isPrime(n+1,true);
        int cnt = 0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                cnt++;
                for(int j=2; j*i < n ;j++){
                    isPrime[j*i] = false;
                }
            }
        }

        return cnt;

    }
};
// 20/20 cases passed (96 ms)
// Your runtime beats 56.78 % of cpp submissions
// Your memory usage beats 48.14 % of cpp submissions (8.7 MB)
// @lc code=end

