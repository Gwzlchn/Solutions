/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 * 
 * 双指针
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        int i=0,j=0;
        for(;i<len;i++){
            if(nums[i]!=val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j ;
    }
};

