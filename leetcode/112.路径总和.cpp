/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (46.94%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    22.8K
 * Total Submissions: 48.4K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        stack<pair<TreeNode*,int>> tree_st;

        int cur_sum = sum-root->val;
        tree_st.push({root,cur_sum});

       
        while(!tree_st.empty()){
            auto cur_pair = tree_st.top();
            tree_st.pop();
            
            auto cur_node = cur_pair.first;
            if(cur_node->left ==NULL && cur_node->right==NULL && cur_pair.second == 0){
                return true;
            }
            if(cur_node->left){
                tree_st.push({cur_node->left,cur_pair.second - cur_node->left->val});
            }
            if(cur_node->right){
                tree_st.push({cur_node->right,cur_pair.second - cur_node->right->val});
            }
        }

        return false;
    }
};

