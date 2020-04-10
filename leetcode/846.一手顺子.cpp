/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 *
 * https://leetcode-cn.com/problems/hand-of-straights/description/
 *
 * algorithms
 * Medium (46.49%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 8K
 * Testcase Example:  '[1,2,3,6,2,3,4,7,8]\n3'
 *
 * 爱丽丝有一手（hand）由整数数组给定的牌。 
 * 
 * 现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。
 * 
 * 如果她可以完成分组就返回 true，否则返回 false。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：hand = [1,2,3,6,2,3,4,7,8], W = 3
 * 输出：true
 * 解释：爱丽丝的手牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
 * 
 * 示例 2：
 * 
 * 输入：hand = [1,2,3,4,5], W = 4
 * 输出：false
 * 解释：爱丽丝的手牌无法被重新排列成几个大小为 4 的组。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= hand.length <= 10000
 * 0 <= hand[i] <= 10^9
 * 1 <= W <= hand.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if(n%W) return false;
        //key->card value->count
        map<int,int> card_map;

        for(auto& h:hand){card_map[h]++;}
        //cout<<"A"<<endl;
        while(!card_map.empty()){
            //cout<<card_map.size()<<endl;
            auto iter  = card_map.begin();
            int cur_first = iter->first;
            for(int cur_card = cur_first; cur_card!=cur_first+W; cur_card++){
                //cout<<cur_card<<endl;
                auto cur_iter = card_map.find(cur_card);
                
                if(cur_iter == card_map.end()) return false;
                if(cur_iter->second == 1) {
                    //cout<<cur_iter->second<<endl;
                    card_map.erase(cur_iter);}
                else {
                    cur_iter->second--;
                }
                
                
            }
        }
        return true;

        

    }
};

// @lc code=end

