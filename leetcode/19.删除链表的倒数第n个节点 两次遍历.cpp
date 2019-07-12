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


//两次扫描思路：制作头节点
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return NULL;

        int cnt = -1;
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *pre = temp;

        while (pre)
        {
            pre = pre->next;
            cnt++;
        }

        cout << cnt;
        pre = temp;
        int cnt2 = cnt - n;
        while (cnt2--)
        {
            pre = pre->next;
        }

        
        pre->next = pre->next->next;
    

        return temp->next;
    }
};
