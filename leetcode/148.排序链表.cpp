/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (64.02%)
 * Likes:    467
 * Dislikes: 0
 * Total Accepted:    50.5K
 * Total Submissions: 78K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL )
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        return quicksort(dummy, NULL);
    }
private:
    //带头结点的快排
    ListNode* quicksort(ListNode* head,ListNode* end){
        if(head == end || head->next == end || head->next->next == end)
            return head;
        //临时链表头节点
        ListNode* dummy = new ListNode(-1);
        //划分点
        ListNode* partition = head->next;
        //cur 传入链表当前节点，new_cur 临时链表当前节点
        ListNode* cur = partition,*new_cur = dummy;

        //按划分点进行划分，临时链表<划分点<原链表
        while(cur->next != end){
            int par = partition->val;
            if(cur->next->val < par){ //临时链表尾插
                new_cur->next = cur->next;
                new_cur = new_cur->next;
                cur->next = cur->next->next;//在原链表删除此节点
            }else{
                cur = cur->next;
            }
        }
        //划分点还在原链表里面，合并：临时链表<划分点<原链表
        new_cur->next = head->next;
        head->next = dummy->next;

        
        quicksort(head, partition);
        quicksort(partition,end);

        return head->next;

    }
};
// @lc code=end

