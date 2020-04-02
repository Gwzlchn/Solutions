class Vector2D {
private:
    vector<vector<int>>::const_iterator m_2d_end , m_2d_iter;
    vector<int>::const_iterator m_1d_iter,m_1d_end;
public:
    void set_iter(){   
        while(m_2d_iter != m_2d_end){
            if(m_2d_iter->empty())
                m_2d_iter++;
            else{
                m_1d_iter = m_2d_iter->cbegin();
                m_1d_end = m_2d_iter->cend();
                break;
            }
        }
    }

    Vector2D(vector<vector<int>>& v) {
        m_2d_iter = v.cbegin();
        m_2d_end = v.cend();     
        set_iter();
    }
    
    int next() {
        int temp = *(m_1d_iter++);
        if(m_1d_iter == m_1d_end){
            m_2d_iter++;
            set_iter();
        }
        return temp;
    }
    
    bool hasNext() {
        return !((m_1d_iter == m_1d_end) && (m_2d_iter == m_2d_end));
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
