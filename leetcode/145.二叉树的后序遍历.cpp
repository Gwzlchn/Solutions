/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (70.42%)
 * Likes:    269
 * Dislikes: 0
 * Total Accepted:    65.8K
 * Total Submissions: 92.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        TreeNode* prev = root;
        stack<TreeNode*> tree_st;
        tree_st.push(root);

        while(!tree_st.empty()){
            auto cur = tree_st.top();
            if(cur->left && cur->left!= prev && cur->right!=prev){
                tree_st.push(cur->left);
            }else if(cur->right && cur->right!=prev){
                tree_st.push(cur->right);
            }else{
                res.push_back(cur->val);
                tree_st.pop();
                prev = cur;
            }
        }
        return res;
    }
};
// @lc code=end

