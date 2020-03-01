/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 *
 * https://leetcode-cn.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (59.49%)
 * Likes:    133
 * Dislikes: 0
 * Total Accepted:    34.7K
 * Total Submissions: 54.6K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用队列实现栈的下列操作：
 * 
 * 
 * push(x) -- 元素 x 入栈
 * pop() -- 移除栈顶元素
 * top() -- 获取栈顶元素
 * empty() -- 返回栈是否为空
 * 
 * 
 * 注意:
 * 
 * 
 * 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty
 * 这些操作是合法的。
 * 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
 * 
 * 
 */

// @lc code=start
class MyStack {
public:
    queue<int> m_queue;
    /** Initialize your data structure here. */
    MyStack() {
        m_queue = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        m_queue.push(x);
        int size = m_queue.size();
        while(size>1){
            m_queue.push(this->pop());
            size--;
        }
        return;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = m_queue.front();
        m_queue.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return m_queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return m_queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

