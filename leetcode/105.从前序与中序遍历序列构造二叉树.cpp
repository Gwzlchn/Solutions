/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.28%)
 * Likes:    418
 * Dislikes: 0
 * Total Accepted:    59K
 * Total Submissions: 90.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int pre_len = preorder.size();
        int in_len = inorder.size();
        if(pre_len==0 || in_len==0 || pre_len!=in_len) return NULL;

        return buildTreehelper(preorder,0,inorder,0,in_len-1);    
    
    }

    TreeNode* buildTreehelper(const vector<int>& preorder,int p_st,\
                            const vector<int>& inorder,int in_st,int in_ed)
    {
        TreeNode* root = new TreeNode(preorder[p_st]);

        //中序中寻找根节点
        int in_root = in_st;
        while(in_root <= in_ed && inorder[in_root]!=preorder[p_st]){
            in_root++;
        }

        int left_len = in_root - in_st;
        int right_len = in_ed - in_root;

        if(left_len){
            root->left = buildTreehelper(preorder, p_st+1,inorder,in_st,in_st + left_len - 1);
        }
        if(right_len){
            root->right = buildTreehelper(preorder, p_st+1 + left_len,inorder, in_st + left_len+1, in_ed);
        }
        return  root;

    }
};
// @lc code=end

