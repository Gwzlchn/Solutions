/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode-cn.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (65.79%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 6.4K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，在树的最后一行找到最左边的值。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * 输出:
 * 1
 * 
 * 
 * 
 * 
 * 示例 2: 
 * 
 * 
 * 输入:
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 * 
 * 输出:
 * 7
 * 
 * 
 * 
 * 
 * 注意: 您可以假设树（即给定的根节点）不为 NULL。
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

 //层次遍历
//  //√ Accepted
//   √ 74/74 cases passed (20 ms)
//   √ Your runtime beats 81.79 % of cpp submissions
//   √ Your memory usage beats 61.54 % of cpp submissions (20.9 MB)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
         if(!root) return {};
        
        queue<TreeNode*> tree_queue;
        tree_queue.push(root);
        int cur_witdh = 1;

        TreeNode* cur_left = NULL;
        while(!tree_queue.empty()){
            cur_left = tree_queue.front();
            while(cur_witdh--){
                TreeNode* cur = tree_queue.front();
                if(cur->left){
                    tree_queue.push(cur->left);
                }
                if(cur->right){
                    tree_queue.push(cur->right);
                }
                tree_queue.pop();
            }
            cur_witdh = tree_queue.size();

            
        }        
        return cur_left->val;
    }
};

