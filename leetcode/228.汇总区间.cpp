class Solution {
public:
    string convert(int i,int j){
        if(i==j) return to_string(i);
        return to_string(i) + "->" + to_string(j);
    }
    vector<string> summaryRanges(vector<int>& nums) {

        //left right 记录前一个应该压入的区间
        int left = nums[0],right = nums[0];
        vector<string> res;
        for(int i=1;i<nums.size();i++){
            if(nums[i] - nums[i-1] >1){
                res.emplace_back(convert(left,right));
                left = right = nums[i];
            }else{
                right = nums[i];
            }
        }
        res.emplace_back(convert(left,right));

        return res;
   
        
    }
};