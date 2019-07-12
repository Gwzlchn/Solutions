/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//思路：两条链表，最后拼接

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* below = new ListNode(-1);

        ListNode* up = new ListNode(-1);

        ListNode *below_head = below, *up_head = up;
        while(head){
            if(head->val >= x){
                up->next = head;
                up = up->next;
            }else{
                below->next = head;
                below = below->next;
            }
            head = head->next;
        }
        
        up->next = NULL;
        below->next = up_head->next;

        return below_head->next;

    }
};

