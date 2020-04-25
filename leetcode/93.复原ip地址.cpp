/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.00%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    38.2K
 * Total Submissions: 81.9K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */

// @lc code=start
class Solution {
public:
int m_str_size;
string m_ip_str;
vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        m_str_size = s.size();
        m_ip_str = s;
        //cout<<m_str_size<<endl;
        vector<int> cur_ip;
        backtrace(cur_ip, 0);
        return res;
    }

    bool is_valid(int x){
        return x>=0 && x<=255;
    }
    // 非法返回-1
    int ip_valid_seg(int cur_idx,int cur_end_idx)
    {
        int res = 0;
        int i = cur_idx;
        if(m_ip_str[cur_idx] == '0'){
            //只有一位为0 才合法，前导0的情况均为非法
            if(cur_end_idx - cur_idx == 1){
                return 0;
            }else{
                return -1;
            }
        }
        
        while(i<cur_end_idx){
            res = res*10 + m_ip_str[i]-'0';
            i++;
        }
        
        return is_valid(res)? res:-1;
    }

    void backtrace(vector<int>& cur_ip,int cur_idx){
        // 退出回溯的条件：达到第四层节点
        if(cur_ip.size() == 4){
            if(cur_idx == m_str_size){
                res.push_back(vec_2_ip(cur_ip));
            }
            return;
        }
        // 减枝，剩余字符串按每个隔断3个字符分，仍然不够分，减枝
       int cur_left = m_str_size - cur_idx -1;
        if((4-cur_ip.size())*3<cur_left) return;

        //每个节点最多有三个子节点,因为一段ip最多3位
        for(int i=1;i<=3;i++){
            if(cur_idx + i > m_str_size) break;
            //当前ip段是否合法，不合法减枝
            int cur_ip_seg = ip_valid_seg(cur_idx,cur_idx+i);           
            if(cur_ip_seg == -1) continue;
            
            // 合法，加入路径
            cur_ip.push_back(cur_ip_seg);
           
            // 下一层回溯
            backtrace(cur_ip, cur_idx + i);
            // 退出该路径
            cur_ip.pop_back();

        }
        return;








    }

    string vec_2_ip(const vector<int>& cur_ip){
        string res;
        for(auto& i:cur_ip){
            res += to_string(i);
            res += '.';
        }
           
        res.pop_back();
        //cout<<res<<endl;
        return res;
    }
};
// @lc code=end

