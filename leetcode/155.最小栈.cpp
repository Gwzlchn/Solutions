/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (51.82%)
 * Likes:    447
 * Dislikes: 0
 * Total Accepted:    93.5K
 * Total Submissions: 177.9K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) —— 将元素 x 推入栈中。
 * pop() —— 删除栈顶的元素。
 * top() —— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */

// @lc code=start
class MinStack {
public:
    int m_min;
    stack<int> m_min_st;

    /** initialize your data structure here. */
    //
    MinStack() {
        m_min = INT_MAX;
    }
    //如果新来的元素更小，把当前最小值保存
    void push(int x) {
        if(m_min >= x ){
            m_min_st.push(m_min);
            m_min = x;
        }
        m_min_st.push(x);
    }
    
    void pop() {
        
        if(m_min_st.top() == m_min){
            m_min_st.pop();
            m_min = m_min_st.top();
        }
        m_min_st.pop();
    }
    
    int top() {
        return m_min_st.top();
    }
    
    int getMin() {
        return m_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

