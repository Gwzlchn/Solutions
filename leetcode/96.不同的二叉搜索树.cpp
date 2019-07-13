/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (60.85%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 17.4K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

 //思路 计算卡特兰数
class Solution {
public:
    int numTrees(int n) {
        long Cat = 1;
        for (int i = 1; i <= n; ++i) {
            Cat = Cat * (4*i-2) / (i+1);
        }
        return (int) Cat;

    }

    //计算卡特兰递归方法会超时
    // long catalan(long n){

    //     if (n == 0)return 1;
    //     if (n == 1)return 1;
    //     long res = 0;
    //     for (int i = 1; i <= n ;i++){
    //         res += catalan(i-1)*catalan(n - i);
    //     }
    //     return res;
    // }

};

