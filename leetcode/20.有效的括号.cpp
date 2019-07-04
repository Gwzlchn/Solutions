/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 * 思路： 左括号入栈，右括号弹栈
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        
        if( s.size()%2!=0)
            return false;
        if(s.size()==0)
            return true;

        for(int i=0;i<s.size();i++){
            char cur = s[i];

          if(cur=='(' || cur=='[' || cur == '{'){
              s1.push(cur);
      
          }else{
            switch(cur){
                case ')':{
                     if(s1.empty() || s1.top()!='('){
                        return false;
                     }else{s1.pop();}
                    break;
                }
                case ']':{
                     if(s1.empty() || s1.top()!='['){
                        return false;
                     }else{s1.pop();}

                    break;
                }
                case '}':{
                     if(s1.empty() || s1.top()!='{'){
                         
                        return false;
                     }else{s1.pop();}
                    break;
                }      
            }
          }
        }

        if(s1.empty())
            return true;
        return false;
    }
};
