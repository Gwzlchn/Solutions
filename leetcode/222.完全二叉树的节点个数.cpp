/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (52.19%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    5.7K
 * Total Submissions: 10.5K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给出一个完全二叉树，求出该树的节点个数。
 * 
 * 说明：
 * 
 * 
 * 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第
 * h 层，则该层包含 1~ 2^h 个节点。
 * 
 * 示例:
 * 
 * 输入: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * 输出: 6
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

//  //√ Accepted
//   √ 18/18 cases passed (40 ms)
//   √ Your runtime beats 95.69 % of cpp submissions
//   √ Your memory usage beats 58.53 % of cpp submissions (28.7 MB)
class Solution {
public:
    int countNodes(TreeNode* root) {
       return count(root,-1,-1);
    }
private:
    int count(TreeNode* root,int left_depth,int right_depth){
        if(!root) return 0;
        TreeNode* temp = root;
        if(left_depth<0){
            left_depth = 0;
            while(temp){
                left_depth++;temp= temp->left;
            }
        }
        temp = root;
        if(right_depth<0){
            right_depth=0;
            while(temp){
                right_depth++;temp=temp->right;
            }
        }
        if(right_depth==left_depth){
            return (1<<left_depth) - 1;
        }else{
            return 1 + count(root->left,left_depth-1,right_depth-1) + 
            count(root->right,left_depth-1,right_depth-1);
        }
    }
};

