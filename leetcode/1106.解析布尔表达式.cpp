/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 *
 * https://leetcode-cn.com/problems/parsing-a-boolean-expression/description/
 *
 * algorithms
 * Hard (51.60%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    1.7K
 * Total Submissions: 3.2K
 * Testcase Example:  '"!(f)"'
 *
 * 给你一个以字符串形式表述的 布尔表达式（boolean） expression，返回该式的运算结果。
 * 
 * 有效的表达式需遵循以下约定：
 * 
 * 
 * "t"，运算结果为 True
 * "f"，运算结果为 False
 * "!(expr)"，运算过程为对内部表达式 expr 进行逻辑 非的运算（NOT）
 * "&(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 与的运算（AND）
 * "|(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 或的运算（OR）
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：expression = "!(f)"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：expression = "|(f,t)"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 输入：expression = "&(t,f)"
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 输入：expression = "|(&(t,f,t),!(t))"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= expression.length <= 20000
 * expression[i] 由 {'(', ')', '&', '|', '!', 't', 'f', ','} 中的字符组成。
 * expression 是以上述形式给出的有效表达式，表示一个布尔值。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool parseBoolExpr(string expression) {
	int idx = 0;    //当前exo位置；
   // while(expression[idx] != '\"')idx++;

	stack<char> op_st = stack<char>();
	stack<char> oprand_st = stack<char>();

	for (; idx < (expression.size()); idx++) {
		switch (expression[idx]) {
		case ',':
			continue;
		case '&':
		case '|':
		case '!':
			op_st.push(expression[idx]);
			break;

		case 't':
		case 'f':
		case '(':
			oprand_st.push(expression[idx]);
			break;

		case ')': {
			char cur_op = op_st.top();
			op_st.pop();

			//弹第一个操作数
			bool res = (oprand_st.top() == 't');
			oprand_st.pop();

			if (cur_op == '!') {
				res = !res;
			}
			else {
				while (oprand_st.top() != '(') {
					bool cur_oprand = (oprand_st.top() == 't');
					if (cur_op == '&')
						res = res && cur_oprand;
					else if (cur_op == '|')
						res = res || cur_oprand;
					oprand_st.pop();
				}
			}

			//弹最近的括号
			oprand_st.pop();
			//把这次结果压进操作数栈
			oprand_st.push((res) ? 't' : 'f');

			break;
		}
		default:
			break;
		}

	}
	return (oprand_st.top() == 't');
}




};

// 71/71 cases passed (4 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 53.06 % of cpp submissions (9.7 MB)
// @lc code=end

