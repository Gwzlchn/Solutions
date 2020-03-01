/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (44.42%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    115K
 * Total Submissions: 245.4K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// @lc code=start
class Solution {
public:
//从后面考虑
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return;
        int len1 = m-1, len2 = n-1, len = m + n - 1;

        while(len1>=0 && len2>=0){
            if (nums1[len1] > nums2[len2]){
                nums1[len--] = nums1[len1--];  
            }else{
                nums1[len--] = nums2[len2--];
            }
            
        }
        std::copy(nums2.begin(),nums2.begin()+len2+1,nums1.begin());
        return;
    }
};
// 59/59 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 5.55 % of cpp submissions (11.5 MB)
// @lc code=end

