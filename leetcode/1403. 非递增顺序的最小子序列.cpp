class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<>());
        int sum = accumulate(nums.cbegin(), nums.cend(), 0) /2;

        vector<int> res;
        for(auto& i:nums){
            res.push_back(i);
            sum -= i;
            if(sum<0) break;
        }
        return res;

    }
};