/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (37.54%)
 * Likes:    237
 * Dislikes: 0
 * Total Accepted:    29.2K
 * Total Submissions: 77.5K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(!head) return true;
        ListNode* fast = head,*slow = head;
        //  slow指针指向中间点偏下
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            cout<<slow->val<<" ";
        }

        //倒置后半段
        ListNode* midhead = new ListNode(-1);
        midhead->next = NULL;

        ListNode  *cur = slow,*next = NULL;
        while(cur){
            next = cur->next;
            cur->next = midhead->next;
            midhead->next = cur;
            cur = next;
        }
        midhead = midhead->next;
        
        //比较
        while(midhead){
            if(head->val != midhead->val){  
                return false;
            }
            head = head->next;
            midhead = midhead->next;
        }
        return true;

    }
};

