/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while(x!=0){
            //考虑边界
            if (abs(res) > INT_MAX/10 ) return 0;
            res = res * 10 + x%10;
            x /=10;
        }
        return res;
    }
};

