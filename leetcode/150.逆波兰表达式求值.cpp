/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 *
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (44.80%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    28.3K
 * Total Submissions: 57.4K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * 根据逆波兰表示法，求表达式的值。
 * 
 * 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 * 
 * 说明：
 * 
 * 
 * 整数除法只保留整数部分。
 * 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 * 
 * 
 * 示例 1：
 * 
 * 输入: ["2", "1", "+", "3", "*"]
 * 输出: 9
 * 解释: ((2 + 1) * 3) = 9
 * 
 * 
 * 示例 2：
 * 
 * 输入: ["4", "13", "5", "/", "+"]
 * 输出: 6
 * 解释: (4 + (13 / 5)) = 6
 * 
 * 
 * 示例 3：
 * 
 * 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * 输出: 22
 * 解释: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int fir = 0,sec = 0;
        stack<int> st = stack<int>();

        for(string token:tokens){
            if(token == "+" || token=="-" || token=="*" || token=="/"){
                char op = token[0];
                sec = st.top();st.pop();
                fir = st.top();st.pop();
                int cur = 0;
                
                switch (op)
                {
                case '+':
                    cur = fir + sec;break;
                case '-':
                    cur = fir - sec;break;
                case '*':
                    cur = fir * sec;break;
                case '/':
                    cur = fir / sec;break;
                default:
                    break;
                }
                st.push(cur);
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};


// 20/20 cases passed (12 ms)
// Your runtime beats 93.06 % of cpp submissions
// Your memory usage beats 5.1 % of cpp submissions (12.9 MB)
// @lc code=end

