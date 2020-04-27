class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        int i = 0;
        int sum=0;
        sort(arr.begin(),arr.end());
        for(;i<arr.size();i++){
            sum += arr[i];
            if(sum>5000) return i; 
        }
        return i;
    }
};