/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size()==0)return res;

        //用了GOTO
        for(int i=0;i<strs[0].size();i++){
            char cur = strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(i >= strs[j].size() || strs[j][i]!=cur){
                    goto RET;
                }
            }
            res += cur;
        }
RET:    return res;
    }
};

