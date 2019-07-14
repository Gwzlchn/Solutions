/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (62.48%)
 * Likes:    483
 * Dislikes: 0
 * Total Accepted:    71.6K
 * Total Submissions: 114.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
 //思路：头插法重建
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* rehead = new ListNode(-1),*cur,*next;
        rehead->next = NULL;

        cur=head;
        while(cur){
            next = cur->next;
            cur->next = rehead->next;
            rehead->next = cur;
            cur = next;   
        }
        return rehead->next;
    }
};

