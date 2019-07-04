/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
class Solution {
public:
    int romanToInt(string s) {
        int target[256];
        target['I'] = 1;
        target['V'] = 5;
        target['X'] = 10;
        target['L'] = 50;
        target['C'] = 100;
        target['D'] = 500;
        target['M'] = 1000;
        int res = 0;
        for(int i=0;i<s.size();i++){

              if(i < s.length()-1 && target[s[i+1]] > target[s[i]])
                res -= target[s[i]];
            else
                res += target[s[i]]; 

        }
        return res;
    }
};

