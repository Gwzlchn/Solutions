/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 *
 * https://leetcode-cn.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (32.55%)
 * Likes:    107
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 32.8K
 * Testcase Example:  '"3+2*2"'
 *
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 * 
 * 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
 * 
 * 示例 1:
 * 
 * 输入: "3+2*2"
 * 输出: 7
 * 
 * 
 * 示例 2:
 * 
 * 输入: " 3/2 "
 * 输出: 1
 * 
 * 示例 3:
 * 
 * 输入: " 3+5 / 2 "
 * 输出: 5
 * 
 * 
 * 说明：
 * 
 * 
 * 你可以假设所给定的表达式都是有效的。
 * 请不要使用内置的库函数 eval。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        
    }

    vector<string>  
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
// @lc code=end

