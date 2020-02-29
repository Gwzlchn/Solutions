/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (39.42%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    18K
 * Total Submissions: 42.9K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {

        //split
        vector<string> words;
        string word;
        stringstream out(str);
        while(out>>word){
            words.push_back(word);
        }
        if(words.size()!=pattern.size()){
            return false;
        }


        map<char,string> iso_map;
        for(int i=0;i<pattern.size();i++){
            if(iso_map.count(pattern[i]) &&
                iso_map[pattern[i]] == words[i]){
                    continue;
            }else if(iso_map.count(pattern[i])==0){
                iso_map.insert({pattern[i],words[i]});
            }else{
                return false;
            }
        }

        map<string,char> iso_map2;
        for(int i=0;i<pattern.size();i++){
            if(iso_map2.count(words[i]) &&
                iso_map2[words[i]] == pattern[i]){
                    continue;
            }else if(iso_map2.count(words[i])==0){
                iso_map2.insert({words[i],pattern[i]});
            }else{
                return false;
            }
        }

        return true;
    }
};


// 33/33 cases passed (4 ms)
// Your runtime beats 68.43 % of cpp submissions
// Your memory usage beats 5.15 % of cpp submissions (9.1 MB)
// @lc code=end

