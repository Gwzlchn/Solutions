/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (40.41%)
 * Likes:    265
 * Dislikes: 0
 * Total Accepted:    31.2K
 * Total Submissions: 75.9K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash_set;
        for_each(wordList.cbegin(),wordList.cend(),[&hash_set](auto v1){
            hash_set.insert(v1);
        });

        queue<pair<string,int>> word_queue;
        word_queue.push({beginWord,1});

        while(!word_queue.empty()){
            auto cur_word = word_queue.front().first;
            auto cur_step = word_queue.front().second;
            if(cur_word == endWord) return cur_step;
            word_queue.pop();


            for(auto& ch:cur_word){
                char temp = ch;
                for(char to_replace = 'a';to_replace!='z';to_replace++){
                    ch=to_replace;
                    if(temp == to_replace) continue;
                    auto iter = hash_set.find(cur_word);
                    if(iter!=hash_set.end()){
                        word_queue.push({cur_word,cur_step+1});
                        hash_set.erase(cur_word);
                    }

                }
                ch = temp;
            }
        }

        return 0;
    }
};
// @lc code=end

