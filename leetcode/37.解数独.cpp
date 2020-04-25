/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (59.99%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    25.9K
 * Total Submissions: 42.4K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过已填充的空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * Note:
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> rows;
    vector<vector<bool>> cols;
    vector<vector<bool>> boxes;
    //vector<vector<char>> res;
    int m_board_size;
    bool m_done_flag;

    void solveSudoku(vector<vector<char>>& board) {
        m_board_size = board.size();
        rows = vector<vector<bool>>(m_board_size,vector<bool>(m_board_size,false));
        cols = vector<vector<bool>>(m_board_size,vector<bool>(m_board_size,false));
        boxes = vector<vector<bool>>(m_board_size,vector<bool>(m_board_size,false));
        m_done_flag = false;
        //数组初始化，假设一定是有效的
        for(int i=0;i<m_board_size;i++){
            for(int j = 0;j<m_board_size;j++){
                char& cur_char = board[i][j];
                if(cur_char == '.') continue;

                int cur_int = cur_char - '1';
                // 盒子个数
                int box_idx = (i/3)*3 + j/3;

        
                rows[i][cur_int] = true;
                cols[j][cur_int] = true;
                boxes[box_idx][cur_int] = true;
                
            }
        }
        
        // 开始解数组
        dfs_solve_sudoku(board, 0, 0);
        return;

    }


    void dfs_solve_sudoku(vector<vector<char>>& board,int row,int col)
    {
        int cur_box_idx = (row/3)*3 + col/3;


        // 因为此问题只有一个解，所以可以设置一个全局flag
        if(row==m_board_size){
            m_done_flag = true;
            //res = vector<vector<char>>(board);
            return;
        }
        
           
        
        if(board[row][col] != '.'){
            if((col+1) == m_board_size){
                dfs_solve_sudoku(board, row+1, 0);
            }else{
                dfs_solve_sudoku(board, row, col+1);
            }
        }else{
            for(int i=0;i<m_board_size;i++){
                char cur_char = char(i+'1');
            
                if(!is_pos_valid( row, col, cur_box_idx, i)) continue;

                // 加入队列
                set_board_visited(row,col,cur_box_idx, i, true);
                board[row][col] = cur_char;
                
                // 下一层递归
                //col 是否到了最后一个元素
                if((col+1) == m_board_size){
                    // 到最后一列的话，从下一列头开始
                    dfs_solve_sudoku(board, row + 1, 0);
                }else{

                    dfs_solve_sudoku(board, row, col+1);
                }
                // 退出队列
                // 适用于 回溯问题只有一个解情况
                if(!m_done_flag){
                     set_board_visited(row, col, cur_box_idx, i,false);
                    board[row][col] = '.';
                }
                   
                }
        }

        
    }

    // 设置当前元素 是否被访问
    void set_board_visited(const int& row,const int& col,const int& box_idx,const int& num,bool to_visit_or_not)
    {
        rows[row][num] = to_visit_or_not;
        cols[col][num] = to_visit_or_not;
        boxes[box_idx][num] = to_visit_or_not;
        return;
    }


    // 当前位置放置当前元素是否合法
    bool is_pos_valid(const int& row,const int& col,const int& box_idx,const int& num)
    {
        return (!rows[row][num] && !cols[col][num] && !boxes[box_idx][num]);
    }


};
// @lc code=end

