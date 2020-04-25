/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (49.83%)
 * Likes:    366
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 62.2K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
class Solution {
public:
    vector<string> phone = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    int m_digits_size;
    vector<string> letterCombinations(string digits) {
        string cur_per;
        m_digits_size = digits.size();
        if(m_digits_size == 0) return {};

        dfs(cur_per,digits,0);
        return res;
    }

    void dfs(string& cur_per,const string& digits,int digits_index){
        // 回溯到达叶节点
        if(cur_per.size() ==m_digits_size ){
            res.push_back(cur_per);
            return;
        }
        
        //当前数字
        int cur_digit = digits[digits_index]-'0';
        // 当前层所有可能节点
        string cur_level = phone[cur_digit-2];
        
        for(auto& c:cur_level){
            //做选择
            cur_per.push_back(c);
            // 下一层选择
            dfs(cur_per,digits,digits_index+1);
            //撤销这个选择
            cur_per.pop_back();

        }
    }
};s

