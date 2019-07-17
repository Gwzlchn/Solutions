/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (69.56%)
 * Likes:    307
 * Dislikes: 0
 * Total Accepted:    55.1K
 * Total Submissions: 79.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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

 //也是类似层次遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(!root) return depth;
        queue<TreeNode*> qu;
        qu.push(root);
        
        int cur_wid = 1;
        while(!qu.empty()){
            depth++;
            while(cur_wid--){
                TreeNode* cur = qu.front();
                qu.pop();
                if(cur->left){
                    qu.push(cur->left);
                }
                if(cur->right){
                    qu.push(cur->right);
                }
            }
            cur_wid = qu.size();
        }
        return depth;
    }
};


