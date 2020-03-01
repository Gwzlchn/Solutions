/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        stack<ImmutableListNode*> m_st = stack<ImmutableListNode*>();
        while(head){
            m_st.push(head);
            head = head->getNext();
        }
        while(!m_st.empty()){
            m_st.top()->printValue();
            m_st.pop();
        }
        return;
    }
};