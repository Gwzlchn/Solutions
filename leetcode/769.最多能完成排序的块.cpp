/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 *
 * https://leetcode-cn.com/problems/max-chunks-to-make-sorted/description/
 *
 * algorithms
 * Medium (54.42%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 5.9K
 * Testcase Example:  '[4,3,2,1,0]'
 *
 * 数组arr是[0, 1, ..., arr.length -
 * 1]的一种排列，我们将这个数组分割成几个“块”，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。
 * 
 * 我们最多能将数组分成多少块？
 * 
 * 示例 1:
 * 
 * 输入: arr = [4,3,2,1,0]
 * 输出: 1
 * 解释:
 * 将数组分成2块或者更多块，都无法得到所需的结果。
 * 例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。
 * 
 * 
 * 示例 2:
 * 
 * 输入: arr = [1,0,2,3,4]
 * 输出: 4
 * 解释:
 * 我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
 * 然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。
 * 
 * 
 * 注意:
 * 
 * 
 * arr 的长度在 [1, 10] 之间。
 * arr[i]是 [0, 1, ..., arr.length - 1]的一种排列。
 * 
 * 
 */

// @lc code=start
//断开为新块儿的地方都是当之前出现的最大值正好和当前位置坐标相等的地方，
//比如例子2中，当 i=1 时，之前最大的数字是1，所以可以断开。而在例子1中，
//当 i=4 时，才和之前出现过的最大数字4相等，此时断开也没啥意义了，
//因为后面已经没有数字了，所以还只是一个块儿，参见代码如下： 

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
         int res = 0, n = arr.size(), mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, arr[i]);
            if (mx == i) ++res;
        }
        return res;
    }
};
// @lc code=end

