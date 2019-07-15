/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (49.56%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    5.1K
 * Total Submissions: 10.2K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
 * 
 * 
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 进阶:
 * 
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 * 
 * 示例:
 * 
 * 
 * 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出: 7 -> 8 -> 0 -> 7
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

// 头条，因为这道题挂了！
 //思路：利用栈
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return NULL;
        stack<ListNode*> s1,s2;
        while(l1){
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2);
            l2 = l2->next;
        }

        ListNode* newHead = new ListNode(-1),*temp = newHead;
        newHead->next = NULL;
        int c = 0,cur_l1,cur_l2;
        //两个栈全空才退出
        while(!s1.empty() || !s2.empty()){
            if(s1.empty()){
                cur_l1 = 0;
            }else{
                cur_l1 = s1.top()->val;
                s1.pop();
            }

            if(s2.empty()){
                cur_l2 = 0;
            }else{
                cur_l2 = s2.top()->val;
                s2.pop();
            }

            int cur = cur_l1 + cur_l2 + c;
            cout<<cur<<" ";
            if(cur >= 10){
                c = 1;
                cur %= 10;
            }else{
                c = 0;
            }
           
            ListNode *curNode = new ListNode(cur);
            curNode->next = newHead->next;
            newHead->next = curNode;
        
        }
        
        //如果最后有进位，补一个节点
        if(c){
            ListNode* carry = new ListNode(c);
            carry->next = newHead->next;
            newHead->next = carry;
        }
        return newHead->next;
    }
};

