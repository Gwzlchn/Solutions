/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (63.70%)
 * Likes:    182
 * Dislikes: 0
 * Total Accepted:    28.6K
 * Total Submissions: 44.7K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
         vector<int> res;

        deque<TreeNode*> bfs;
        bfs.push_back(root);

        while(!bfs.empty()){
            int cur_level_len = bfs.size();

            auto right = bfs.back();
            res.push_back(right->val);
            for(int i=0;i<cur_level_len;i++){
                auto cur_top = bfs.front();
                bfs.pop_front();
                if(cur_top->left) bfs.push_back(cur_top->left);
                if(cur_top->right) bfs.push_back(cur_top->right);
            }
        }

        return res;

    }
};
// @lc code=end

