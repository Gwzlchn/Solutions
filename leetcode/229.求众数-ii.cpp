/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 *
 * https://leetcode-cn.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (41.49%)
 * Likes:    133
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 25.1K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
 * 
 * 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: [3]
 * 
 * 示例 2:
 * 
 * 输入: [1,1,1,3,3,2,2,2]
 * 输出: [1,2]
 * 
 */

// @lc code=start
// public int majorityElement(int[] nums) { //摩尔投票法
//         int count = 0;
//         int num  = nums[0];
//         for(int i = 1; i< nums.length; i++)
//         {
//             if(nums[i] != num)
//             {
//                 count--;
//                 if(count < 0)
//                 {
//                     count = 0;
//                     num = nums[i];
//                 }
//             }
//             else
//                 count++;
//         }
//         return num;
//     }

// ————————————————
// 版权声明：本文为CSDN博主「shxifs」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/shxifs/article/details/91352407

//摩尔投票变种
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = INT_MAX,b=INT_MAX;
        int counta = 0,countb = 0;
        for(num : nums){
            
        }
    }
};
// @lc code=end

