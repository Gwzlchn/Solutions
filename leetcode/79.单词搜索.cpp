/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (40.78%)
 * Likes:    373
 * Dislikes: 0
 * Total Accepted:    50.3K
 * Total Submissions: 122.3K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m_row = board.size();
        m_col = board[0].size();
        if(!m_row || !m_col) return false;

        for(int i=0;i<m_row;i++){
            for(int j=0;j<m_col;j++){
                if(board[i][j] == word[0] && dfs(board,word,i,j,0))
                    return true;
            }
        }

        return false;
    }
private:
    int m_row;
    int m_col;
    bool dfs(vector<vector<char>>& board,string& word , int cur_x,int cur_y,int cur_str_idx){
        if(board[cur_x][cur_y] != word[cur_str_idx])
            return false;
        
        if(word.size()-1 == cur_str_idx)
            return true;
        
        char temp = board[cur_x][cur_y];
        board[cur_x][cur_y] = 0;
        cur_str_idx++;

        bool up = cur_x>0 && dfs(board,word,cur_x-1,cur_y,cur_str_idx);
        bool down = cur_x < m_row-1 &&  dfs(board,word,cur_x+1,cur_y,cur_str_idx);
        bool left = cur_y>0 && dfs(board,word,cur_x,cur_y-1,cur_str_idx);
        bool right = cur_y< m_col-1 && dfs(board,word,cur_x,cur_y+1,cur_str_idx);

        if(up || down || left || right) 
            return true;
    
        //回溯
        board[cur_x][cur_y] = temp;

        return false;

    }
};
// @lc code=end

