/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 *
 * https://leetcode-cn.com/problems/minimum-falling-path-sum-ii/description/
 *
 * algorithms
 * Hard (58.19%)
 * Likes:    11
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 2.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个整数方阵 arr ，定义「非零偏移下降路径」为：从 arr 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。
 * 
 * 请你返回非零偏移下降路径数字和的最小值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：13
 * 解释：
 * 所有非零偏移下降路径包括：
 * [1,5,9], [1,5,7], [1,6,7], [1,6,8],
 * [2,4,8], [2,4,9], [2,6,7], [2,6,8],
 * [3,4,8], [3,4,9], [3,5,7], [3,5,9]
 * 下降路径中数字和最小的是 [1,5,7] ，所以答案是 13 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length == arr[i].length <= 200
 * -99 <= arr[i][j] <= 99
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {-1,-1,-1,0,0, 1,1,1};
        int dy[] = {-1, 0, 1,1,-1,-1,0,1};

        //参考题解的做法，用第一个byte存放当前，用第二个byte存放下一轮状态
        for(int i = 0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int sum = 0;    //周围活细胞数
                for(int k = 0;k<8;k++){
                    int x = i + dx[k];  //行
                    int y = j + dy[k];  //列
                    if(x>=0 && x<board.size() &&y>=0 && y<board[0].size()){
                        sum += (board[x][y]&0x1);
                    }
                }
                if(board[i][j] == 0){   //当前死细胞
                    if(sum == 3)
                        board[i][j] |= 0x0100;
                }else{                  //当前活细胞
                    if(sum == 2 || sum==3){
                        board[i][j] |= 0x0100;
                    }
                }
                //cout<<sum<<endl;

            }
        }

        for(auto& iter :board){
            for(auto& i:iter){
                i = i>>8;
            }
        } 



    }
};
// @lc code=end

