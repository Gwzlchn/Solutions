class ZigzagIterator {
public:
    //vector<int> m_v1,m_v2;
    vector<int>::const_iterator m_iter1,m_iter2;
    vector<int>::const_iterator m_v1_cend,m_v2_cend;
    bool m_flag; //flag = true v1,   flag=false v2;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        m_v1_cend = v1.cend();
        m_v2_cend = v2.cend(); 
        m_iter1 = v1.cbegin();
        m_iter2 = v2.cbegin();
        m_flag = true;
    }

    int next() {
        bool prev = m_flag;
        m_flag = !m_flag;
        if(m_iter1!=m_v1_cend && m_iter2!=m_v2_cend){
            
            return prev? (*(m_iter1++)):(*(m_iter2++));
        }
        if(m_iter1==m_v1_cend)
            return *(m_iter2++);
        
        return *(m_iter1++);
    }

    bool hasNext() {
        return !(m_iter1==m_v1_cend && m_iter2==m_v2_cend);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */


//执行用时 4 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户