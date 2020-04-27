/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.44%)
 * Likes:    646
 * Dislikes: 0
 * Total Accepted:    102.9K
 * Total Submissions: 277.5K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int low = 0;
        int high = len - 1;
        

        while(low <= high){
            int mid = low + (high - low)/2;
            if(target == nums[mid]){
                return mid;
            }
            // 左半部分有序
            if(nums[low] <= nums[mid]){
                // target 在有序的那段区间里面
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                }else{// target 在无序的那段区间里面
                    low = mid+1;
                }
            }else// 右半部分有序
            {
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }

        return -1;

    }
};
// @lc code=end

