/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (60.24%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    60.7K
 * Total Submissions: 98.7K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出: 3
 * 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出: 5
 * 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //P节点的祖先
        vector<TreeNode*> p_anc = TreeNodeAncestor(root,p);
        //Q节点的祖先
        vector<TreeNode*> q_anc = TreeNodeAncestor(root,q);

        //正序遍历两个祖先栈即可，找到第一个不相等的节点退出循环，之后前移一个即为最近祖先。
        auto p_iter = p_anc.cbegin();
        auto q_iter = q_anc.cbegin();
        //节点指针值判等
        while(p_iter!= p_anc.cend() && q_iter != q_anc.cend() && (*p_iter) == (*q_iter)){
            
            p_iter++;
            q_iter++;
        }

        return (*(p_iter-1));
    }

    //非递归后序遍历确定节点的祖先
    vector<TreeNode*> TreeNodeAncestor(TreeNode*  root,TreeNode* target){
        //祖先栈，这里为了主函数正序遍历用了vector，仅非递归后续的话可以采用stack
        vector<TreeNode*> ancestor;
        ancestor.push_back(root);

        //后序遍历的顺序是 左右中，父节点一定在左右节点都访问完毕后再访问
        TreeNode* prev = root;
        while(!ancestor.empty()){
            auto cur_node = ancestor.back();
            if(cur_node == target) return ancestor; 
            auto cur_left = cur_node->left;
            auto cur_right = cur_node->right;
            //左子节点、右子节点均未被访问过，先入左子节点
            if(cur_left && cur_left != prev && cur_right!=prev){
                ancestor.push_back(cur_left);
            }
            //右子节点没有被访问过，再入右子节点
            else if(cur_right && cur_right != prev){
                ancestor.push_back(cur_right);
            }
            //均被访问过
            else{
                //这里本来应该是访问当前父节点的代码，此题省略
                ancestor.pop_back();
                prev = cur_node;
            }
        }
        return ancestor;
    }
};
// @lc code=end

