/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//双指针思路：先让快指针走n步，再快慢指针一起走
//最后慢指针停留的位置就是pre节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tempn = n;
        ListNode* hhead = new ListNode(-1);
        hhead->next = head;
        ListNode* fast,*slow;
        fast = slow = hhead;

        while(tempn--){
            fast = fast->next;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return hhead ->next;
    }
};

