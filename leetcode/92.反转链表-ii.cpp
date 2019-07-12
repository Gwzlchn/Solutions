/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (45.12%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    13.6K
 * Total Submissions: 30.1K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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


// 大致思路：1->2->3->4->5->null
// 删除3，在1->2 之间插入，1->3->2->4->5
// 删除4，在1->3 之间插入，1->4->3->2->5

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        head = pre;
        int i = 0;
        while (i < m-1) {
        	pre = pre->next;
        	i++;
        }
        ListNode* start = pre->next;
         ListNode*  then = start->next;

        int cnt = n-m;
        while(cnt--){
            //删除then节点
            start->next = then->next;
            //在pre节点后面插入then节点
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }

    	return head->next;



    }
};

