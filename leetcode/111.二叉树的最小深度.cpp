/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (39.12%)
 * Likes:    130
 * Dislikes: 0
 * Total Accepted:    21.1K
 * Total Submissions: 53.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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

 // 类似层次遍历，但时间不理想
 /*  √ Your runtime beats 20.65 % of cpp submissions
  √ Your memory usage beats 90.64 % of cpp submissions (19.4 MB)
  */
class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        if(!root) return depth;
        queue<TreeNode*> qu;
        qu.push(root);
        depth++;
        int cur_wid = 1;
        while(!qu.empty()){
            while(cur_wid--){
                TreeNode* cur = qu.front();
                qu.pop();
                if(cur->left){
                    qu.push(cur->left);
                }
                if(cur->right){
                    qu.push(cur->right);
                }
                if((cur->left) == NULL && (cur->right)==NULL){
                    return depth ;
                }
            }
            cur_wid = qu.size();
            depth++;
        }
        return depth;
    }
};

