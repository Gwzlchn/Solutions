// 题目描述
// Calculate a + b and output the sum in standard format -- that is, 
// the digits must be separated into groups of three by commas (unless there are less than four digits).

// 输入描述:
// Each input file contains one test case.  Each case contains a pair of integers 
// a and b where -1000000 <= a, b <= 1000000.  The numbers are separated by a space.


// 输出描述:
// For each test case, you should output the sum of a and b in one line.  
// The sum must be written in the standard format.

// 输入例子:
// -1000000 9

// 输出例子:
// -999,991



#include <iostream>
#include<string>

using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        cout << s[i];
        if (s[i] == '-')
            continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1)
            cout << ",";
    }
    return 0;
}