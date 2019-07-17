/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (56.98%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    32.6K
 * Total Submissions: 56.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
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

 // 层次遍历，根节点出对的时候子节点入队
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ret;
        queue<TreeNode*> tree_queue;
        tree_queue.push(root);
        int cur_witdh = 1;
        vector<int> cur_level = {};
        while(!tree_queue.empty()){
            
            while(cur_witdh--){
                TreeNode* cur = tree_queue.front();
                if(cur->left){
                    tree_queue.push(cur->left);
                }
                if(cur->right){
                    tree_queue.push(cur->right);
                }
                cur_level.push_back(cur->val);
                tree_queue.pop();
            }
            cur_witdh = tree_queue.size();
            ret.push_back(cur_level);
            cur_level.clear();
            
        }        
        return ret;
    }
};

