/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (66.60%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 12.2K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: ["Hello", "Alaska", "Dad", "Peace"]
 * 输出: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你可以重复使用键盘上同一字符。
 * 你可以假设输入的字符串将只包含字母。
 * 
 */
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keyboard = {
            "qwertyuiop","asdfghjkl","zxcvbnm"
        };
        vector<string> ret;
        
        int line = -1;
        for(auto iter = words.begin();iter!=words.end();iter++){
            
            char first = (*iter)[0];
            first = (char)tolower(first);
            if( keyboard[0].find( first ) != -1 )
                line = 0;
            else if( keyboard[1].find( first )  != -1 )
                line = 1;
            else if( keyboard[2].find( first )  != -1 )
                line = 2;

            for(int j = 1;j<iter->size();j++){
               
                if(line==-1)break;
                else if(keyboard[line].find( tolower((*iter)[j]) ) == -1){
                    line = -1;
                    break;
                }
            }

            if(line != -1)
                ret.push_back((*iter));
        }

        return ret;
    }
};

