class ValidWordAbbr {
private:
    //key->addr   value->count
    unordered_map<string,int> addr_dic;
    //key->word  
    set<string> words_set;
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for_each(dictionary.begin(),dictionary.end(),
        [this](auto& w){
            string addr = this->to_addr(w);
            
            this->addr_dic[addr]++;
            this->words_set.insert(w);
        });
    }
    string to_addr(const string& word) const {
        int len = word.size();
        if(len>2){
            return word[0] + to_string(len-2) + word[len-1];
        }
        return word;
    }
    bool isUnique(string word) {
        string a = to_addr(word);
        auto dic_iter = addr_dic.find(a);
        auto set_iter = words_set.find(word);

        if(dic_iter!=addr_dic.end() && set_iter!= words_set.end()){
            if(dic_iter->first == word) return true;
             return dic_iter->second == 1;
        }
           

        if(dic_iter!=addr_dic.end())
            return dic_iter->first == word;

        return true;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */