#include<bits/stdc++.h>

using namespace std;

int main(){
    string line;
    getline(cin,line);
    map<string,int> m;

    string cur_word = "";
    for(int i=0;i<line.size();i++){
        if(isalnum(line[i])){
            cur_word += tolower(line[i]);
        }else if(!cur_word.empty()){
            m[cur_word]++;
            cur_word = "";
        }
    }
    if(!cur_word.empty()){
        m[cur_word]++;
    }

    auto max_map = max_element(m.begin(),m.end(),
        [](auto& p1,auto& p2){return p1.second < p2.second;});
    
    cout<<max_map->first <<" "<<max_map->second<<endl;
    return 0;
}