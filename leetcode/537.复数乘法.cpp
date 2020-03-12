/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 *
 * https://leetcode-cn.com/problems/complex-number-multiplication/description/
 *
 * algorithms
 * Medium (67.80%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 6.5K
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 * 给定两个表示复数的字符串。
 * 
 * 返回表示它们乘积的字符串。注意，根据定义 i^2 = -1 。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "1+1i", "1+1i"
 * 输出: "0+2i"
 * 解释: (1 + i) * (1 + i) = 1 + i^2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "1+-1i", "1+-1i"
 * 输出: "0+-2i"
 * 解释: (1 - i) * (1 - i) = 1 + i^2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
 * 
 * 
 * 注意:
 * 
 * 
 * 输入字符串不包含额外的空格。
 * 输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    struct complex{
        int m_re;
        int m_im;
        complex(int re,int im){
            m_re = re;
            m_im = im;
        }
         complex operator * (const complex& other) {
            int r = m_re * other.m_re - m_im * other.m_im;
            int i = m_re * other.m_im + m_im * other.m_re;
            return complex(r, i);
        }


        string serial(){
            return to_string(m_re) + '+' + to_string(m_im) + 'i';
        }

        

        
    };

    complex parse(const string& str){
            int i = str.find_first_of('+');
            int re = stoi(str.substr(0,i));
            int im = stoi(str.substr(i+1,str.size()-1-i));
        return complex(re,im);
    }

    string complexNumberMultiply(string a, string b) {

        return (parse(a)*parse(b)).serial();
    }
};
// @lc code=end

