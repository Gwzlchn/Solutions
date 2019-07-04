/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        //边界
        if(x<0)return false;
        if(x==0)return true;

        int length = log(x)+2;
        int* num = new int [length];

        //从1开始计数，方便之后取半
        int i=1;
        while(x){
            num[i] = x%10;
            x /=10;
            i++;
        }

        for(int j=1;j<=i/2;j++){
            if(num[j]!=num[i-j]){
                printf ("%d %dnn",num[j],num[i-j]);
                return false;
            }
        }
        return true;
    }
};


