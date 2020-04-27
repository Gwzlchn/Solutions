/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 *
 * https://leetcode-cn.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (62.85%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    25.5K
 * Total Submissions: 39.7K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
 * 编写一个算法来重建这个队列。
 * 
 * 注意：
 * 总人数少于1100人。
 * 
 * 示例
 * 
 * 
 * 输入:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * 输出:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
/**
     * 解题思路：先排序再插入
     * 1.排序规则：按照先H高度降序，K个数升序排序
     * 2.遍历排序后的数组，根据K插入到K的位置上
     *
     * 核心思想：高个子先站好位，矮个子插入到K位置上，前面肯定有K个高个子，矮个子再插到前面也满足K的要求
     *
     * @param people
     * @return
     */
        // [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]
        // 再一个一个插入。
        // [7,0]
        // [7,0], [7,1]
        // [7,0], [6,1], [7,1]
        // [5,0], [7,0], [6,1], [7,1]
        // [5,0], [7,0], [5,2], [6,1], [7,1]
        // [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 按身高降序，人数升序排序
        sort(people.begin(),people.end(),\
            [](auto& p1, auto& p2)
            {
                if(p1[0] > p2[0]) return true;
                if(p1[0] == p2[0]) return p1[1] < p2[1];
                return false;
            });
        
        deque<vector<int>> result;

        for(auto& p:people){
            result.insert((result.begin() + p[1]), p);
        }

        return vector<vector<int>>(result.begin(),result.end());
    }
};
// @lc code=end

