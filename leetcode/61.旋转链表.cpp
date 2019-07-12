/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 思路：循环链表，然后找到最末尾节点
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(temp == NULL || temp->next==NULL)
            return temp;
        int cnt = 1;
        while(temp->next){
            temp = temp->next;
            cnt++;
        }
        temp->next = head;

        int cnt_right = cnt-k%cnt;
        
        //此时temp是尾节点
        ListNode* shift = temp;
       
        while(cnt_right--){
            shift = shift->next;
            cout<<shift->val<<" ";
        }

        ListNode* res = shift->next;
        shift->next = NULL;

        return res;


    }
};

