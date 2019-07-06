// 题目描述
// A number that will be the same when it is written forwards or backwards is known as a Palindromic Number.  
// For example, 1234321 is a palindromic number.  All single digit numbers are palindromic numbers.
// Non-palindromic numbers can be paired with palindromic ones via a series of operations. First,
//  the non-palindromic number is reversed and the result is added to the original number. 
// If the result is not a palindromic number, this is repeated until it gives a palindromic number.  
// For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.
// Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

// 输入描述:
// Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 1010) 
// is the initial numer and K (<= 100) is the maximum number of steps.  The numbers are separated by a space.


// 输出描述:
// For each test case, output two numbers, one in each line.  The first number is the paired palindromic number of N, 
// and the second number is the number of steps taken to find the palindromic number.  
// If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.



// 输入例子:
// 67 3

// 输出例子:
// 484
// 2

#include<string>
#include<cstdio>
#include <algorithm>
#include<iostream>
using namespace std;

bool isPal(string p){
    string p_temp(p);
    reverse(p.begin(),p.end());

    if(p == p_temp){
        return true;
    }
    return false;
}

string add(string s1){
    string s2(s1);
    reverse(s2.begin(),s2.end());
    //cout<<s2;
    string res(s1);
    int c = 0;
    for(int i=s1.size()-1;i>=0;i--){
        //char t = s1[i] - '0' + s2[i] - '0' + c ; 
        res[i] = (s1[i] - '0' + s2[i] - '0' + c ) % 10 + '0';
        c = (s1[i] - '0' + s2[i] - '0' + c ) /10;
    }
    if(c>0){
        res = '1' + res;
    }
    // cout<<res;
    return res;
}

int main(){
    string  num;
    int k;
    cin>>num;
    cin>>k;
    
    int cnt=0;
    for(;cnt<k;cnt++){
        if(!isPal(num)){
            num = add(num);
            // cout<<num<<" " <<cnt<<endl;
        }else{
            break;
        }
    }

    if(isPal(num)){
        cout<<num<<endl<<cnt;
    }

    return 0;
}
