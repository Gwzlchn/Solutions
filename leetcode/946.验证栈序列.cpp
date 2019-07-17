/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 *
 * https://leetcode-cn.com/problems/validate-stack-sequences/description/
 *
 * algorithms
 * Medium (50.85%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    2.3K
 * Total Submissions: 4.5K
 * Testcase Example:  '[1,2,3,4,5]\n[4,5,3,2,1]'
 *
 * 给定 pushed 和 popped 两个序列，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回
 * true；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 * 输出：true
 * 解释：我们可以按以下顺序执行：
 * push(1), push(2), push(3), push(4), pop() -> 4,
 * push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
 * 
 * 
 * 示例 2：
 * 
 * 输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 * 输出：false
 * 解释：1 不能在 2 之前弹出。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= pushed.length == popped.length <= 1000
 * 0 <= pushed[i], popped[i] < 1000
 * pushed 是 popped 的排列。
 * 
 * 
 */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push = pushed.size();
        if(!push) return true;
        stack<int> st;
        int p = 0;
        for(int i=0;i<push;i++){
            st.push(pushed[i]);
            
            //当前入栈的元素等于出栈的头元素，则直接出栈
            while(!st.empty() && popped[p] == st.top()){
                st.pop();p++;
            }
        }

        for(int i=p;i<push;i++){
            if(popped[i] == st.top()){
                st.pop();
            }else{
                return false;
            }
        }

        return true;

    }
};

