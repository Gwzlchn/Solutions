/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (77.40%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    21.1K
 * Total Submissions: 27.1K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或七步，可进可退。（引用自
 * 百度百科 - 皇后 ）
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //vector<vector<bool>> valid_board;
    int m_size;
    int res;

    int totalNQueens(int n) {
        m_size = n;
        //valid_board = vector<vector<bool>>(m_size,vector<bool>(m_size,false));
        res = 0;
        vector<int> one_board;
        dfs_n_queen(one_board);
        return res;
    }

    void dfs_n_queen(vector<int>& one_board)
    {   

        //回溯达到叶子节点，放入结果数组
        if(one_board.size() == m_size){
            res++;
            return;
        }
        // 每行都探测每个位置，是否合法，合法进入下一层节点
        for(int i=0;i<m_size;i++)
        {
            if(!is_cur_pos_valid(one_board,i)) continue;
            // 合法，加入路径
            one_board.push_back(i);
            // 进入下一层探测
            dfs_n_queen(one_board);
            // 删除该节点
            one_board.pop_back();
        }
        return;



    }

    bool is_cur_pos_valid(const vector<int> prev_board,int cur_pos)
    {
        // 深度 从 1 开始
        int cur_depth = prev_board.size();
        int prev_depth = cur_depth-1;
        
        for(int i=0;i<cur_depth;i++)
        {   //在同一列
            if(prev_board[i] == cur_pos ) return false;
            //在同一对角线
            if( abs(prev_board[i] - cur_pos) == (cur_depth-i)) return false;;
        }
        return true;
    }


    vector<string> vec_int_2_board(const vector<int>& pos_vec)
    {
        string one_line(m_size,'.');
        vector<string> res(m_size,one_line);
        for(int i=0;i<m_size;i++){
            res[i][pos_vec[i]] = 'Q';
        }
        return res;

    }
};
// @lc code=end

