// 题目描述
// The highest building in our city has only one elevator. A request list 
// is made up with N positive numbers. The numbers denote at which floors 
// the elevator will stop, in specified order. It costs 6 seconds to move 
// the elevator up one floor, and 4 seconds to move down one floor. The 
// elevator will stay for 5 seconds at each stop.
// For a given request list, you are to compute the total time spent to 
// fulfill the requests on the list. The elevator is on the 0th floor at 
// the beginning and does not have to return to the ground floor when the 
// requests are fulfilled.

// 输入描述:
// Each input file contains one test case. Each case contains a positive integer
// N, followed by N positive numbers. All the numbers in the input are less than 100.


// 输出描述:
// For each test case, print the total time on a single line.

// 输入例子:
// 3 2 3 1

// 输出例子:
// 41

#include<iostream>
using namespace std;

int main(){
    int pre=0,cnt=0,sec=0;
    cin>>cnt;
    while(cnt--){
        int now;
        cin>>now;
        if(now>pre){
            sec += (now - pre)* 6 + 5;
            
        }else{
            sec += (pre-now)*4 + 5;
        }
        pre = now;
    }
    cout<<sec;
    return 0;
}