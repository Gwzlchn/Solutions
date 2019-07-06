// 题目描述
// People in Mars represent the colors in their computers in a similar way as the Earth people.  That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits  for Blue.  The only difference is that they use radix 13 (0-9 and A-C) instead of 16.  Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

// 输入描述:
// Each input file contains one test case which occupies a line containing the three decimal color values.


// 输出描述:
// For each test case you should output the Mars RGB value in the following format: first output "#", then followed by a 6-digit number where all the English characters must be upper-cased.  If a single color is only 1-digit long, you must print a "0" to the left.

// 输入例子:
// 15 43 71

// 输出例子:
// #123456
// 注意！没有atoi

#include <cstdio>
using namespace std;
int main() {
    char c[14] = {"0123456789ABC"};
    printf("#");
    for(int i = 0; i < 3; i++) {
        int num;
        scanf("%d", &num);
        printf("%c%c", c[num/13], c[num%13]);
    }
 return 0;
}
