// 题目描述
// Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

// 输入描述:
// Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).


// 输出描述:
// For each test case, output in one line the digits of the sum in English words. There must be one space 
// between two consecutive words, but no extra space at the end of a line.

// 输入例子:
// 12345

// 输出例子:
// one five

#include<iostream>
using namespace std;

string nums[10] = {
    "zero","one","two","three","four","five","six","seven","eight","nine"
};

int main(){
    string  in;
    cin>>in;
    int sum;
    for(int i=0;i<in.size();i++){
        sum += in[i] - '0';
    }
    //cout<<sum;
    int nums_arr[10];
    int i=0;
    while(sum){
        nums_arr[i] = sum %10;
        sum /=10;
        i++;
    }
    while(i--){
        cout<<nums[nums_arr[i]]<<" ";
    }
    
}