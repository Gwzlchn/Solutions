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
    int largestBSTSubtree(TreeNode* root) {
        if(root==NULL)return 0;
        if(isBST(root)) return get_count(root);
        int L = largestBSTSubtree(root->left);
        int R = largestBSTSubtree(root->right);
        return max(L,R);
    }

    int get_count(TreeNode* root){
        if(root==NULL) return 0;
        return 1+ get_count(root->left) + get_count(root->right);
    }
    bool isBST(TreeNode* root) {
      // Just use the inOrder traversal to solve the problem.
        if (root == NULL) {
            return true;
        }
        
        return dfs(root, INT_MIN,INT_MAX);
    }
    
     bool dfs(TreeNode* root, int min, int max) {
        if(root == NULL)
            return true;
        
        if(root->val <= min || root->val >= max)
            return false;
        
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }
};