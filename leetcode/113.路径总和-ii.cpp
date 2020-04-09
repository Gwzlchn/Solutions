/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (58.97%)
 * Likes:    198
 * Dislikes: 0
 * Total Accepted:    40.4K
 * Total Submissions: 68.4K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        vector<vector<int>> res;
        TreeNode* prev = root;

        vector<pair<TreeNode*,int>> tree_st;
        tree_st.push_back({root,sum-root->val});

        while(!tree_st.empty()){
            auto cur_pair = tree_st.back();
            auto cur_sum = cur_pair.second;
            auto cur = cur_pair.first;
            if(cur->left && cur->left!= prev && cur->right!=prev){
                tree_st.push_back({cur->left,cur_sum-cur->left->val});
            }else if(cur->right && cur->right!=prev){
                tree_st.push_back({cur->right,cur_sum-cur->right->val});
            }else{
                //res.push_back(cur->val);
                if(!cur->left && !cur->right && cur_sum==0){
                    vector<int> cur_path;
                    for_each(tree_st.cbegin(),tree_st.cend(),
                        [&cur_path](auto& p1){cur_path.push_back(p1.first->val);});
                    
                    res.push_back(cur_path);
                    cur_path.clear();
                }
                
                tree_st.pop_back();
                prev = cur;
            }
        }
        return res;
    }



    
};
// @lc code=end

