/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 *
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (40.95%)
 * Likes:    194
 * Dislikes: 0
 * Total Accepted:    20.6K
 * Total Submissions: 49.7K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
 * 
 * 说明：不允许修改给定的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：tail connects to node index 1
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：tail connects to node index 0
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1], pos = -1
 * 输出：no cycle
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：
 * 你是否可以不用额外空间解决此题？
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

 //思路：相遇之后，一个节点变为头节点，再相遇即为循环首节点
 //第一次相遇时：
 //快指针走了 2n 步，慢指针走了n 步 = 环内走了 in 步 + 环外走了out步
 // 快指针多走了一圈，所以 环长度 = n;
 // 快指针从头再走 out 步，慢指针从相遇点再走 环长度 - in  = out 步，
 // 第二次相遇点必然为起点
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL ) return NULL;

        ListNode  *fast = head,*slow = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                fast = head;
                while(fast!=slow){
                    fast = fast->next;slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
        
    }
};

