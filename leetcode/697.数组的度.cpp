/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 *
 * https://leetcode-cn.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (51.90%)
 * Likes:    107
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 24.8K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * 给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
 * 
 * 你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1, 2, 2, 3, 1]
 * 输出: 2
 * 解释: 
 * 输入数组的度是2，因为元素1和2的出现频数最大，均为2.
 * 连续子数组里面拥有相同度的有如下所示:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组[2, 2]的长度为2，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,2,3,1,4,2]
 * 输出: 6
 * 
 * 
 * 注意:
 * 
 * 
 * nums.length 在1到50,000区间范围内。
 * nums[i] 是一个在0到49,999范围内的整数。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    struct info{
        int m_freq = 0;
        int m_left_pos = 0;
        int m_right_pos = 0;

       
    };
    int findShortestSubArray(vector<int>& nums) {
        
        //key ->nums[i]
        //value -> <频度，第一次出现坐标,最后一次出现坐标>
        map<int,info> nums_map;

        for(int i=0;i<nums.size();i++){
            if(nums_map.find(nums[i]) != nums_map.end()){
                nums_map[nums[i]].m_freq += 1 ;
                nums_map[nums[i]].m_right_pos = i;
            }else{
                nums_map[nums[i]] = {1,i,i};
            }
        }

        //nums[i],freq,degree
        vector<tuple<int,int,int>> nums_vec;
        for(auto& num:nums_map){
            int freq = num.second.m_freq;
            int degree = num.second.m_right_pos - num.second.m_left_pos + 1;
            nums_vec.emplace_back(make_tuple(num.first,freq,degree));
           //cout<<num.first<<" "<<num.second.m_right_pos<<" "<<num.second.m_left_pos<<endl;
        }

        //按频度排序,频度相同按度
        auto min_iter = min_element(nums_vec.begin(),nums_vec.end(),
            [](auto& tuple1,auto& tuple2){
                int t1_f,t1_d;
                int t2_f,t2_d;
                tie(std::ignore,t1_f,t1_d) = tuple1;
                tie(std::ignore,t2_f,t2_d) = tuple2;
                if(t1_f != t2_f){
                    return t1_f > t2_f;
                }else{
                    return t1_d < t2_d;
                }
            });
        


        

        return get<2>(*min_iter);



    }
};
// @lc code=end

