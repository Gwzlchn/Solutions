class ZigzagIterator {
public:
    vector<int> m_v1,m_v2;
    vector<int>::iterator m_iter1,m_iter2;
    bool m_flag; //flag = true v1,   flag=false v2;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        m_v1 = v1;
        m_v2 = v2; 
        m_iter1 = m_v1.begin();
        m_iter2 = m_v2.begin();
        m_flag = true;
    }

    int next() {
        bool prev = m_flag;
        m_flag = !m_flag;
        if(m_iter1!=m_v1.end() && m_iter2!=m_v2.end()){
            
            return prev? (*(m_iter1++)):(*(m_iter2++));
        }
        if(m_iter1==m_v1.end())
            return *(m_iter2++);
        
        return *(m_iter1++);
    }

    bool hasNext() {
        return !(m_iter1==m_v1.end() && m_iter2==m_v2.end());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */


//执行用时 4 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户