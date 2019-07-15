/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (50.13%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 12.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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
 //注意：前半段断链！！！！
class Solution {
public:
    void reorderList(ListNode* head) {
        //空链表或者只有一个节点，返回
        if(!head || !(head->next)) return;

        //找中点偏上一个
        ListNode *midHead = head,*temp = head->next;
        while(temp && temp->next){
            temp = temp->next->next;
            midHead = midHead->next;
        }
        
        //midhead 是倒置后的后半段头节点
        ListNode* newHead = new ListNode(-1),*cur,*next;
        newHead->next = NULL;
        cur = midHead->next;
        midHead->next = NULL;//断链！！
        while(cur){
            next = cur->next;
            cur->next = newHead->next;
            newHead->next = cur;
            cur = next;
        }
        midHead = newHead;

        //重组
        ListNode* left = head,*right = midHead->next;
        
        while(right && left){
            ListNode *rr = right->next,*lr = left->next;
            right->next = lr;
            left->next = right;
            right = rr;
            left  = lr;
        }
        

        return;
    }



};

