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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        //BFS
        deque<TreeNode*> bfs;
        bfs.push_back(root);
        int max_dep = 0;

        while(!bfs.empty()){
            max_dep++;

            int cur_len = bfs.size();
            for(int i=0;i<cur_len;i++){
                auto& cur_node = bfs.front();
                
                if(cur_node->left) bfs.push_back(cur_node->left);
                if(cur_node->right) bfs.push_back(cur_node->right);
                bfs.pop_front();
            }
        }

        return max_dep;
    }
};


