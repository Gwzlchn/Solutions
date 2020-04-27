/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 *
 * https://leetcode-cn.com/problems/assign-cookies/description/
 *
 * algorithms
 * Easy (53.19%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    34.7K
 * Total Submissions: 64.2K
 * Testcase Example:  '[1,2,3]\n[1,1]'
 *
 * 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子 i ，都有一个胃口值 gi
 * ，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i
 * ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 * 
 * 注意：
 * 
 * 你可以假设胃口值为正。
 * 一个小朋友最多只能拥有一块饼干。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,3], [1,1]
 * 
 * 输出: 1
 * 
 * 解释: 
 * 你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
 * 虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
 * 所以你应该输出1。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2], [1,2,3]
 * 
 * 输出: 2
 * 
 * 解释: 
 * 你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
 * 你拥有的饼干数量和尺寸都足以让所有孩子满足。
 * 所以你应该输出2.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        auto& kids = g;
        auto& biscuit = s;
        // 贪心 ，先排序
        sort(g.begin(),g.end(),less<>());
        sort(s.begin(),s.end(),less<>());




        // 尽可能用少的饼干满足孩子
        auto b = lower_bound(biscuit.begin(), biscuit.end(), (*kids.begin()));
        auto k = kids.begin();

        
        int cnt = 0;
        while(k != kids.end() && b != biscuit.end() ){
            if((*b) >= (*k)){
                b++;
                k++;
                //cout<< (*k) << (*b)<<endl; 
                cnt++;
            }else{
                b++;
            }
            
           
        }

        
        return cnt;
    }
};
// @lc code=end

