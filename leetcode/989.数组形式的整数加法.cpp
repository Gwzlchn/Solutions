/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 *
 * https://leetcode-cn.com/problems/add-to-array-form-of-integer/description/
 *
 * algorithms
 * Easy (41.98%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    4.1K
 * Total Submissions: 9.7K
 * Testcase Example:  '[1,2,0,0]\n34'
 *
 * 对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
 * 
 * 给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = [1,2,0,0], K = 34
 * 输出：[1,2,3,4]
 * 解释：1200 + 34 = 1234
 * 
 * 
 * 解释 2：
 * 
 * 输入：A = [2,7,4], K = 181
 * 输出：[4,5,5]
 * 解释：274 + 181 = 455
 * 
 * 
 * 示例 3：
 * 
 * 输入：A = [2,1,5], K = 806
 * 输出：[1,0,2,1]
 * 解释：215 + 806 = 1021
 * 
 * 
 * 示例 4：
 * 
 * 输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
 * 输出：[1,0,0,0,0,0,0,0,0,0,0]
 * 解释：9999999999 + 1 = 10000000000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * 0 <= A[i] <= 9
 * 0 <= K <= 10000
 * 如果 A.length > 1，那么 A[0] != 0
 * 
 * 
 */
 //大数加法
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ret = {};
        int a_size = A.size(),n = a_size;
        int c = 0;
        while( n>0  || K>0){
            n--;
            int cur_a = (n>=0)?A[n]:0;
            int cur_k = (K==0)?0:K%10;
            int cur = cur_a  + c + cur_k;
            if(cur >= 10){
                cur = cur%10;
                c = 1;
            }
            else{
                c = 0;
            }
            ret.push_back(cur);
            K = (K==0)?0:K/10;
        }
    
        if(c){
            ret.push_back(c);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

