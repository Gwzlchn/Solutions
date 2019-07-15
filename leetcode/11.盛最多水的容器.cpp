/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (56.25%)
 * Likes:    644
 * Dislikes: 0
 * Total Accepted:    56.3K
 * Total Submissions: 100K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 * 
 */
//思路： 要么宽度长，要么最短边变高，才有可能达到最大面积
class Solution {
public:
    int maxArea(vector<int>& height) {

        int len = height.size();
        if(!len) return 0;
        int i=0, j=len-1,max_area = 0;;
        while(i<j){
            int cur_h = (height[i]>height[j])?height[j]:height[i];
            int cur_size = cur_h * (j-i);
            max_area = (max_area > cur_size)?max_area:cur_size;
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return max_area;
    }
};

