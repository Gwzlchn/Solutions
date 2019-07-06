// 题目描述
// Given an increasing sequence S of N integers, the median is the number at the middle position.  
// For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15.  
// The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the 
// elements of both sequences.  For example, the median of S1 and S2 is 13.
// Given two increasing sequences of integers, you are asked to find their median.

// 输入描述:
// Each input file contains one test case.  Each case occupies 2 lines, each gives the information of a sequence.  
// For each sequence, the first positive integer N (<=1000000) is the size of that sequence.  
// Then N integers follow, separated by a space.  It is guaranteed that all the integers are in the range of long int.


// 输出描述:
// For each test case you should output the median of the two given sequences in a line.

// 输入例子:
// 4 11 12 13 14
// 5 9 10 15 16 17

// 输出例子:
// 13



#include<cstdio>
#include<iostream>

using namespace std;

#define length 1000000
long arr[2000005];

int main(){
    int l1,l2;
    cin>>l1;
    for(int i =0;i<l1;i++){
        cin>>arr[i];
    }
    cin>>l2;
    for(int i =0;i<l2;i++){
        cin>>arr[length+i];
    }

    int mid =(l1+l2)%2==0?(l1+l2)/2-1:(l1+l2)/2;

    long mid_num = 0;
    int arr1=0,arr2=0;
    for(int i=0;i<=mid;i++){
        if(arr[arr1]<arr[length+arr2]){
            mid_num = arr[arr1];
            arr1++;
            // cout<<mid_num<<"!"<<endl;
        }else{
            mid_num = arr[length+arr2];
            arr2++;
            //cout<<mid_num<<endl;
        }
    }
    cout<<mid_num;
    return 0;





}
