class Solution {
public:
    int minCount(vector<int>& coins) {
        int res = 0;
        for(auto& i:coins){
            res += (i+1)>>1;
        }
        return res;
    }
};