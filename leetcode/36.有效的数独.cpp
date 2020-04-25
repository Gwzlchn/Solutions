/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 *
 * https://leetcode-cn.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (53.98%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    29.2K
 * Total Submissions: 53.8K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 
 * 
 * 上图是一个部分填充的有效的数独。
 * 
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * 输出: false
 * 解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
 * ⁠    但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
 * 
 * 说明:
 * 
 * 
 * 一个有效的数独（部分已被填充）不一定是可解的。
 * 只需要根据以上规则，验证已经填入的数字是否有效即可。
 * 给定数独序列只包含数字 1-9 和字符 '.' 。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */
class Solution {
public:
    vector<vector<bool>> rows;
    vector<vector<bool>> cols;
    vector<vector<bool>> boxes;

    int m_board_size;
    bool isValidSudoku(vector<vector<char>>& board) {
        m_board_size = board.size();
        rows = vector<vector<bool>>(m_board_size,vector<bool>(m_board_size,false));
        cols = vector<vector<bool>>(m_board_size,vector<bool>(m_board_size,false));
        boxes = vector<vector<bool>>(m_board_size,vector<bool>(m_board_size,false));

        for(int i=0;i<m_board_size;i++){
            for(int j = 0;j<m_board_size;j++){
                char cur_char = board[i][j];
                if(cur_char == '.') continue;

                int cur_int = cur_char - '0';
                
                
                int box_idx = (i/3)*3 + j/3;

                //cout<<cur_int<<" "<<i<<" "<<j<<" "<<box_idx<<endl;
                
                if( rows[i][cur_int - 1] == false &&
                    cols[j][cur_int - 1] == false &&
                    boxes[box_idx][cur_int - 1] == false ){

                    rows[i][cur_int - 1] = true;
                    cols[j][cur_int - 1] = true;
                    boxes[box_idx][cur_int - 1] = true;
                }   else{
                    
                    return false;
                }             
            }
        }
        return true;
   }
};

// 504/504 cases passed (20 ms)
// Your runtime beats 45.61 % of cpp submissions
// Your memory usage beats 29.01 % of cpp submissions (11 MB)
