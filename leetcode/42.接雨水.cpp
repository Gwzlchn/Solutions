/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (49.02%)
 * Likes:    1057
 * Dislikes: 0
 * Total Accepted:    76.6K
 * Total Submissions: 153K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start
//新的栈顶元素就是左边界，当前高度是右边界，
// 只要取二者较小的，减去坑的高度，长度就是右边界坐标减去左边界坐标再减1，
// 二者相乘就是盛水量
// 单调递减栈
class Solution {
public:
    int trap(vector<int>& height) {
       stack<int> mono_st;
       int res= 0;
       for(int i=0;i<height.size();i++){
           while(!mono_st.empty() && height[mono_st.top()] < height[i]){
               int cur_max_idx = mono_st.top();
               mono_st.pop();
               if(mono_st.empty()) continue;
               int cur_length = i - mono_st.top() -1;
               int cur_height = min(height[i],height[mono_st.top()]) - height[cur_max_idx];
               res += cur_length*cur_height;
           }
           mono_st.push(i);
       }

       return res;
    }
};
// @lc code=end

