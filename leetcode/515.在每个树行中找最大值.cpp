/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (58.86%)
 * Likes:    59
 * Dislikes: 0
 * Total Accepted:    9.3K
 * Total Submissions: 15.7K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 您需要在二叉树的每一行中找到最大的值。
 * 
 * 示例：
 * 
 * 
 * 输入: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * 输出: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> tree_queue;
        tree_queue.push(root);
        while(!tree_queue.empty()){
            int size=  tree_queue.size();
            int cur_max = INT_MIN;
            while(size--){
                auto cur = tree_queue.front();
                tree_queue.pop();
                if(cur->val > cur_max) cur_max = cur->val;
                if(cur->left!=NULL) tree_queue.push(cur->left);
                if(cur->right!=NULL) tree_queue.push(cur->right);
            }
            res.push_back(cur_max);

        }

        return res;
    }   
};
// @lc code=end

