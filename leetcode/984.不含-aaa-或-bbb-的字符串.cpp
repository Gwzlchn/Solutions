/*
 * @lc app=leetcode.cn id=984 lang=cpp
 *
 * [984] 不含 AAA 或 BBB 的字符串
 *
 * https://leetcode-cn.com/problems/string-without-aaa-or-bbb/description/
 *
 * algorithms
 * Medium (36.10%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    4K
 * Total Submissions: 10.8K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数 A 和 B，返回任意字符串 S，要求满足：
 * 
 * 
 * S 的长度为 A + B，且正好包含 A 个 'a' 字母与 B 个 'b' 字母；
 * 子串 'aaa' 没有出现在 S 中；
 * 子串 'bbb' 没有出现在 S 中。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = 1, B = 2
 * 输出："abb"
 * 解释："abb", "bab" 和 "bba" 都是正确答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：A = 4, B = 1
 * 输出："aabaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A <= 100
 * 0 <= B <= 100
 * 对于给定的 A 和 B，保证存在满足要求的 S。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res;
        // 如果当前 A>B 则让 AABAAB 去消耗A
        // 如果A== B 一个A一个B
        while(A || B){
            if(A>B){
                if(A>1){
                    res += "aa";A-=2;
                }else{
                    res += "a";A--;
                }
                if(B>0){
                    res += 'b';B--;
                }
            }else if(A==B){
                res += "ab";A--;B--;
            }else if(A<B){
                if(B>1){
                    res += "bb";B-=2;
                }else{
                    res += 'b';B--;
                }
                if(A>0){
                    res += 'a';A--;
                }
            }
        }
        return res;

    }
};
// @lc code=end

