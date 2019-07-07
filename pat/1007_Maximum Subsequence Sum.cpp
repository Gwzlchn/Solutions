// 题目描述
// Given a sequence of K integers { N1 , N2 , ..., NK }.  A continuous
// subsequence is defined to be { Ni , Ni+1 , ..., Nj  } where
// 1 <= i <= j <= K.  The Maximum Subsequence
//  is the continuous subsequence which has the largest sum of its
// elements.  For example, given sequence { -2, 11, -4, 13, -5, -2 }, its
// maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

// Now you are supposed to find the largest sum, together with the first
// and the last numbers of the maximum subsequence.

// 输入描述:
// Each input file contains one test case. Each case occupies two lines.
// The first line contains a positive integer K (<= 10000).  The second
// line contains K numbers, separated by a space.

// 输出描述:
// For each test case, output in one line the largest sum, together with
// the first and the last numbers of the maximum subsequence. The numbers
// must be separated by one space, but there must be no extra space at the
//  end of a line.  In case that the maximum subsequence is not unique,
// output the one with the smallest indices i and j (as shown by the sample
// case).  If all the K numbers are negative, then its maximum sum is defined
// to be 0, and you are supposed to output the first and the last numbers
// of the whole sequence.

// 输入例子:
// 10
// -10 1 2 3 4 -5 -23 3 7 -21

// 输出例子:
// 10 1 4

//思路 最长子序列和

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        temp = temp + v[i];

        if (temp < 0)
        {
            temp = 0;
            tempindex = i + 1;  
        }
        
        else if (temp > sum)
        {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if (sum < 0)
        sum = 0;
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}