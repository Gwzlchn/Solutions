/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 *
 * https://leetcode-cn.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (40.43%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    20K
 * Total Submissions: 44.2K
 * Testcase Example:  '["time", "me", "bell"]'
 *
 * 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
 * 
 * 例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes =
 * [0, 2, 5]。
 * 
 * 对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
 * 
 * 那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: words = ["time", "me", "bell"]
 * 输出: 10
 * 说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * 每个单词都是小写字母 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        std::sort(words.begin(),words.end(),
            [](string& s1,string& s2){
                return s1.size() > s2.size();
            });
        int len = 0;
        Trie* tr = new Trie();
        for(auto& word:words){
            len += tr->insert(word);
        }
        return len;
    }



class TrieNode{
public:
    char val;
    TrieNode* children[26];

    TrieNode(){    
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    };
    

};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        this->root = new TrieNode();
    }
    int insert(string word){
        TrieNode* cur = root;
        bool isNew = false;
        for(int i = word.size()-1;i>=0;i--){
            int c = word[i] - 'a';
            if(cur->children[c] == nullptr){
                isNew = true;
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        return isNew? word.size() + 1 : 0;
    }
    
};
};




// @lc code=end

