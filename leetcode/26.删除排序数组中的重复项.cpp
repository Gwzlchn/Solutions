/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.empty()){
            int cnt = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[cnt] != nums[i]){
                    cnt++;
                    nums[cnt] = nums[i];
                    
                }
            }
            return cnt +1;
        }
        return 0;
    }
};

