/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 *
 * https://leetcode-cn.com/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (21.10%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 47.4K
 * Testcase Example:  '1\n2'
 *
 * 你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
 * 
 * 每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
 * 
 * 你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
 * 
 * 每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
 * 
 * 你的目标是确切地知道 F 的值是多少。
 * 
 * 无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：K = 1, N = 2
 * 输出：2
 * 解释：
 * 鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
 * 否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
 * 如果它没碎，那么我们肯定知道 F = 2 。
 * 因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
 * 
 * 
 * 示例 2：
 * 
 * 输入：K = 2, N = 6
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 输入：K = 3, N = 14
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= K <= 100
 * 1 <= N <= 10000
 * 
 * 
 */

// @lc code=start
class Solution {
    int fun(int K, int T)	// 计算 K 个鸡蛋，扔 T 次，可以覆盖多少个区间
{
	if (T == 1 )    // K个鸡蛋扔1次，只能确定一层
        return 1 ;
    if(K==1)
        return T;   //一个鸡蛋扔K次，线性探查，能确定K层
	return fun(K - 1, T - 1) + fun(K, T - 1) + 1;
}



public:
int superEggDrop(int K, int N) 
{
	int T = 1;	// 扔鸡蛋的机会
	while (fun(K, T) < N ) 
        T++;
	return T;
}
};




如果鸡蛋没有碎，那么对应的是 f(T - 1, K)，也就是说在这一层的上方可以有 f(T - 1, K) 层；

如果鸡蛋碎了，那么对应的是 f(T - 1, K - 1)，也就是说在这一层的下方可以有 f(T - 1， K - 1) 层。

因此我们就可以写出状态转移方程：

f(T, K) = 1 + f(T-1, K-1) + f(T-1, K)
f(T,K)=1+f(T−1,K−1)+f(T−1,K)

边界条件为：当 T≥1 的时候 f(T, 1) = T ，当 K≥1 时，f(1, K) = 1.


// @lc code=end

