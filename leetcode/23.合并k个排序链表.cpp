/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //思路 分治法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len==0)return NULL;
        int n=len;
        while(n>1){
            int k = (n+1)/2;
            for(int i=0;i<n/2;i++){
                lists[i] = mergeTwoLists(lists[i],lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1),*cur;
        cur = head;
        while(l1&&l2){
            if(l1->val>l2->val){
                cur->next = l2;
                l2 = l2->next;
            }else{
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        if(l1){
            cur->next = l1;
        }
        if(l2){
            cur ->next = l2;
        }

        return head->next;

    }
};

