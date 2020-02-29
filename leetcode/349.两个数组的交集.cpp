/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (63.93%)
 * Likes:    164
 * Dislikes: 0
 * Total Accepted:    52.8K
 * Total Submissions: 77.3K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(),size2 = nums2.size();
        if(size1==0)return {};
        if(size2==0)return {};
        vector<int>& short_nums = (size1>size2)? nums2 : nums1;
        vector<int>& long_nums = (size1<=size2)? nums2 : nums1;
        unordered_set set1(long_nums.begin(),long_nums.end());

        int count = 0;
        for(auto iter = short_nums.begin();
            iter!=short_nums.end();iter++){
             
            if(set1.erase(*iter)){  //判断是否存在并将其在set中删除
                nums2[count] = *iter;
                count++;
            }
            }
        return vector<int>(nums2.begin(), nums2.begin() + count);
    

    
    
    }
};


// 60/60 cases passed (8 ms)
// Your runtime beats 86.31 % of cpp submissions
// Your memory usage beats 5.02 % of cpp submissions (12.7 MB)
// @lc code=end

