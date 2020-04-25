/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 *
 * https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/description/
 *
 * algorithms
 * Medium (35.77%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 10.1K
 * Testcase Example:  '"123456579"'
 *
 * 给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。
 * 
 * 形式上，斐波那契式序列是一个非负整数列表 F，且满足：
 * 
 * 
 * 0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
 * F.length >= 3；
 * 对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
 * 
 * 
 * 另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。
 * 
 * 返回从 S 拆分出来的所有斐波那契式的序列块，如果不能拆分则返回 []。
 * 
 * 示例 1：
 * 
 * 输入："123456579"
 * 输出：[123,456,579]
 * 
 * 
 * 示例 2：
 * 
 * 输入: "11235813"
 * 输出: [1,1,2,3,5,8,13]
 * 
 * 
 * 示例 3：
 * 
 * 输入: "112358130"
 * 输出: []
 * 解释: 这项任务无法完成。
 * 
 * 
 * 示例 4：
 * 
 * 输入："0123"
 * 输出：[]
 * 解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
 * 
 * 
 * 示例 5：
 * 
 * 输入: "1101111"
 * 输出: [110, 1, 111]
 * 解释: 输出 [11,0,11,11] 也同样被接受。
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= S.length <= 200
 * 字符串 S 中只含有数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    int m_size;
    bool m_done_flag;
    // 最终的结果数组，满足斐波那契性质
    vector<int> m_res;
    
    vector<int> splitIntoFibonacci(string S) {
        // 传入字符串长度
        m_size = S.size();
        m_done_flag = false;
        // 斐波那契数组中所有元素的位数之和
        int cur_total_size = 0;

        dfs_fib_vec(S,cur_total_size,0);
        
        return m_done_flag? m_res:vector<int>();
    }

        void dfs_fib_vec(const string& S,int& cur_total_size, int idx)
    {
        // 决策树成功的情况：
        // 1、斐波那契数组中元素个数大于2，少于2没有意义，同时满足
        // 2、斐波那契数组中元素位数之和 等于 原始字符串长度
        // 注意这里不可以把 idx == m_size ,即深度搜索到最后一个元素之后（因为idx从0开始，idx==m_size是达到了决策树中的叶节点之后）当做成功，不过，有些回溯题这么判断是可以的。
        // 一个反例：“0123”
        if (cur_total_size == m_size && m_res.size() > 2) {
            m_done_flag = true;
            return;
        }

        for (int i = idx; i < m_size; i++) {
            int cur_num = get_cur_num(S, idx, i);

            // 如果有前导0 或者溢出 直接减枝，之后的数字也不必考虑
            if (cur_num == -1) break;
            // 如果不符合斐波那契额数列定义，下一位置继续寻找
            if (!fab_vec_valid(cur_num)) continue;

            // 1、加入选择
            int cur_num_length = i - idx + 1;
            m_res.push_back(cur_num);
            cur_total_size += cur_num_length;
            // 2、进入下一层决策树
            dfs_fib_vec(S,cur_total_size,i + 1);

            // 3、退出选择，注意，因为这道题可以看成找出一个解即可，所以只要完成标志为真，直接返回上一层即可
            if (m_done_flag) {
                return;
            }
            else {
                // 退出最后的路径选择
                m_res.pop_back();
                // 从 此时元素位数和 减掉 当前元素的位数
                cur_total_size -=  cur_num_length;
            }

        }
        return;
    }


    // 返回 m_input 中[st,ed] 中的数值，左闭右闭区间
    // 如果是 前导零 情况，或者 溢出情况，返回-1
    int get_cur_num(const string& S,int st_idx,int ed_idx)
    {
        long cur_res = 0;
        // 如果 [st,ed] 含有前导0 必然非法
        if((ed_idx - st_idx)>=1 && S[st_idx] == '0') return -1;
        for(int i=st_idx;i<=ed_idx;i++){
            cur_res = cur_res*10 + S[i] - '0';
        }
        if(cur_res > INT_MAX) return -1;
        return cur_res;
    }

    // 对一个满足斐波那契性质的数组，插入当前元素是否合法
    bool fab_vec_valid(int num){
        // 小于2的话插入当前值必然是合法的
        if(m_res.size()==0 || m_res.size() == 1)
            return true;
        //如果倒数两个元素的和 等于现在这个元素，则合法
        else {
            long last = *(m_res.crbegin());
            long last_prev = *(m_res.crbegin()+1);
            // 如果最后两个数 相加之后溢出，必然非法，后面是什么都不可以
            if(last+last_prev > INT_MAX)
                return false;
            else return (last_prev + last) == num;
        }
            
    }
};




// @lc code=end

