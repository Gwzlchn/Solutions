/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (44.41%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    31.8K
 * Total Submissions: 71.7K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回滑动窗口中的最大值。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7] 
 * 解释: 
 * 
 * ⁠ 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 
 * 提示：
 * 
 * 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 * 
 * 
 * 
 * 进阶：
 * 
 * 你能在线性时间复杂度内解决此题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        if(len*k == 0) return {};
        
        vector<int> left(len,0);
        vector<int> right(len,0);
        
        left[0] = nums[0];
        right[len-1] = nums[len-1];
        int i=1,j=len-2;
        for(;i<len;i++){
            if(i%k == 0) left[i] = nums[i];
            else left[i] = max(left[i-1],nums[i]);

            if(j%k == 0) right[j] = nums[j];
            else right[j] = max(right[j+1],nums[j]);
            j--;
        }
        vector<int> res(len-k+1,0);
        for(int i=0;i<len-k+1;i++){
            res[i]=max(left[i+k-1],right[i]);
        }
        return res;
    }
};
// @lc code=end

