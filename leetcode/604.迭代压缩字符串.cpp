class StringIterator {
public:
    StringIterator(string compressedString) {
        m_idx = 0;
        m_str = compressedString;
        while(m_idx < m_str.size()){
            char ch = m_str[m_idx];
            m_ch.emplace_back(ch);
            m_idx++;
            int idx = getNextNum();
            m_cnt.emplace_back(idx);
            
        }
        // for(int i:m_cnt){
        //     cout<<i<<endl;
        // }
        m_vec_idx = 0;
    }
    
    char next() {
        if(!hasNext())
            return ' ';
        
        int i = m_cnt[m_vec_idx];
        char ch = m_ch[m_vec_idx];
        //cout<<ch<<endl;
        if(i==1){
            m_vec_idx++;
        }else{
            m_cnt[m_vec_idx]--;
        }
        return ch;

    }
    
    bool hasNext() {
        return m_cnt.size() != m_vec_idx;
    }

    int getNextNum(){
        int res = 0;
        while(isdigit(m_str[m_idx])){
            res = res*10 + m_str[m_idx] - '0';
            m_idx++;
        }
        return res;
    }

    int  m_idx;
    string m_str;
    vector<char> m_ch;
    vector<int> m_cnt;
    int m_vec_idx;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */