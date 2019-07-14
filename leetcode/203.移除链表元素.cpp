/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (41.69%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    29.9K
 * Total Submissions: 71.6K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //各种边界条件的考虑
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head && head->val == val) head = head->next;
        if(!head) return head;

        ListNode  *temp = head;

        while(temp && temp->next){
            if(val == temp->next->val){
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
            
        }
        return head;
    }
};

