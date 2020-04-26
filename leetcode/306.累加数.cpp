/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 *
 * https://leetcode-cn.com/problems/additive-number/description/
 *
 * algorithms
 * Medium (31.49%)
 * Likes:    63
 * Dislikes: 0
 * Total Accepted:    5.5K
 * Total Submissions: 17.5K
 * Testcase Example:  '"112358"'
 *
 * 累加数是一个字符串，组成它的数字可以形成累加序列。
 * 
 * 一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
 * 
 * 给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。
 * 
 * 说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
 * 
 * 示例 1:
 * 
 * 输入: "112358"
 * 输出: true 
 * 解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * 
 * 
 * 示例 2:
 * 
 * 输入: "199100199"
 * 输出: true 
 * 解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
 * 
 * 进阶:
 * 你如何处理一个溢出的过大的整数输入?
 * 
 */

// @lc code=start
class Solution {
public:
    

    int m_size;
    bool m_done_flag;
    vector<long double> m_res;
    
   bool isAdditiveNumber(string num) {
        
        m_size = num.size();
        m_done_flag = false;
        int cur_total_size = 0;

        dfs_fib_vec(num,cur_total_size,0);
       
        return m_done_flag;
    }

        void dfs_fib_vec(const string& S,int& cur_size, int idx)
    {
        if (cur_size == m_size && m_res.size() > 2) {
            //cout<<"done";
            m_done_flag = true;
            return;
        }

        for (int i = idx; i < m_size; i++) {
            long double cur_num = get_cur_num(S, idx, i);

            // 如果有前导0 或者溢出 直接减枝，之后的数字也不必考虑
            if (cur_num == -1) break;
            // 如果不符合斐波那契额数列定义，下一位置继续寻找
            if (!fab_vec_valid(cur_num)) continue;

            // 1、加入选择
            int cur_num_length = i - idx + 1;
            m_res.push_back(cur_num);
            cur_size += cur_num_length;
            // 2、进入下一层决策树
            dfs_fib_vec(S,cur_size,i + 1);
            // 3、退出选择，注意，因为这道题可以看成找出一个解即可，所以只要完成标志为真直接返回上一层即可
            if (m_done_flag) {
                return;
            }
            else {
                m_res.pop_back();
                cur_size -=  cur_num_length;
                //cout << m_cur_size << endl;
            }

        }
        return;
    }



    // 返回 m_input 中[st,ed] 中的数值，左闭右闭区间
    long double get_cur_num(const string& S,int st_idx,int ed_idx)
    {
        long double cur_res = 0;
        // 如果 [st,ed] 含有前导0 必然非法
        if((ed_idx - st_idx)>=1 && S[st_idx] == '0') return -1;
        for(int i=st_idx;i<=ed_idx;i++){
            cur_res = cur_res*10 + S[i] - '0';
        }
        //if(cur_res > INT_MAX) return -1;
        return cur_res;
    }

    bool fab_vec_valid(long double num){
        // 小于2的话插入当前值必然是合法的
        if(m_res.size()==0 || m_res.size() == 1)
            return true;
        //如果倒数两个元素的和 等于现在这个元素，则合法
        else {
            auto last = *(m_res.crbegin());
            auto last_prev = *(m_res.crbegin()+1);
            // 如果最后两个数 相加之后溢出，必然非法，后面是什么都不可以
            //if(last+last_prev > INT_MAX)
                //return false;
            //else 
                return (last_prev + last) == num;
        }
            
    }
};
// @lc code=end

