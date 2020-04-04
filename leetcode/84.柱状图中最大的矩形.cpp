/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (39.14%)
 * Likes:    509
 * Dislikes: 0
 * Total Accepted:    37.3K
 * Total Submissions: 95.2K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int res = 0;
        stack<int> mono_st;
        heights.push_back(0);
        for(int i =0;i<heights.size();i++){
            while(!mono_st.empty() && heights[mono_st.top()] >= heights[i]){
                int cur_max_idx = mono_st.top();
                mono_st.pop();
                if(mono_st.empty()){
                    res = max(res,heights[cur_max_idx]*i);
                }else{
                    res = max(res, heights[cur_max_idx]*(i-mono_st.top()-1));
                }
                //printf("i:%d\tidx:%d\t\tmax:%d\n",i,cur_max_idx,res);
                
            }
            mono_st.push(i);
        }
        return res;
    }
};
// @lc code=end

