/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
 *
 * https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (61.86%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    23.2K
 * Total Submissions: 37K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
 * 
 * 例如，从根到叶子节点路径 1->2->3 代表数字 123。
 * 
 * 计算从根到叶子节点生成的所有数字之和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * 输出: 25
 * 解释:
 * 从根到叶子节点路径 1->2 代表数字 12.
 * 从根到叶子节点路径 1->3 代表数字 13.
 * 因此，数字总和 = 12 + 13 = 25.
 * 
 * 示例 2:
 * 
 * 输入: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * 输出: 1026
 * 解释:
 * 从根到叶子节点路径 4->9->5 代表数字 495.
 * 从根到叶子节点路径 4->9->1 代表数字 491.
 * 从根到叶子节点路径 4->0 代表数字 40.
 * 因此，数字总和 = 495 + 491 + 40 = 1026.
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
    int sumNumbers(TreeNode* root) {
        if(!root) return {};
        int res = 0;
        TreeNode* prev = root;
        vector<TreeNode*> tree_st;
        tree_st.push_back(root);

        while(!tree_st.empty()){
            auto cur = tree_st.back();
            if(cur->left && cur->left!= prev && cur->right!=prev){
                tree_st.push_back(cur->left);
            }else if(cur->right && cur->right!=prev){
                tree_st.push_back(cur->right);
            }else{
                //到了叶节点，正序遍历栈
                if(!cur->left && !cur->right){
                    int cur_int = 0;
                    for_each(tree_st.cbegin(),tree_st.cend(),
                        [&cur_int](auto& ptr){cur_int = cur_int*10; cur_int+=ptr->val;});
                    //cout<<cur_int<<endl;
                    res += cur_int;
                }


                tree_st.pop_back();
                prev = cur;
            }
        }
        return res;
    }

};

作者：gwzlchn
链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/solution/c-fei-di-gui-hou-xu-bian-li-by-gwzlchn-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end

