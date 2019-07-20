/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 *
 * https://leetcode-cn.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (64.39%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 15.3K
 * Testcase Example:  '[2,2,3,2]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,3,2]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [0,1,0,1,0,1,99]
 * 输出: 99
 * 
 */
 //用一个32的数组，存每个数字1的频次，然后看【i】是否为3的倍数，通用解法
//  //√ Accepted
//   √ 11/11 cases passed (20 ms)
//   √ Your runtime beats 40.22 % of cpp submissions
//   √ Your memory usage beats 79.8 % of cpp submissions (9.5 MB)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32] = {0};
        for(int j=0;j<nums.size();j++){
            for(int i=0;i<32;i++){
                if(nums[j]&0x0001)bits[i]++;
                nums[j] >>=1;
            }
        }
        
        int ret = 0;
        long j =1;
        for(int i=0;i<32;i++){
            cout<<bits[i];
            if(bits[i]%3 != 0) ret |= j;
            j <<=1 ;

        }
        return ret;

        
    }
};

