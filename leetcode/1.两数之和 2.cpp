/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //sort(nums.begin(),nums.end());
        
        for(int i=0,j=nums.size()-1; i<j; ){
            int temp = nums[i] + nums[j];
            if(temp == target){
                return {i,j};
            }else if(temp > target){
                j--;continue;
            }else if(temp<target){
                i++;continue;
            }
        }
        return {0,0};
    }
};

