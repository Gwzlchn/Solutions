// 题目描述
// This time, you are supposed to find A*B where A and B are two polynomials.

// 输入描述:
// Each input file contains one test case. Each case occupies 2 lines, and each 
// line contains the information of a polynomial:
// K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the 
// polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, 
// respectively.  It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.


// 输出描述:
// For each test case you should output the product of A and B in one line, with
// the same format as the input.  Notice that there must be NO extra space at the 
// end of each line.  Please be accurate up to 1 decimal place.

// 输入例子:
// 2 1 2.4 0 3.2
// 2 2 1.5 1 0.5

// 输出例子:
// 3 3 3.6 2 6.0 1 1.6

#include<cstdio>


using namespace std;

int main(){
    double res[2002] = {0.0},first[1003] = {0.0};
    int a_len = 0;
    scanf("%d",&a_len);
    for(int i=0;i<a_len;i++){
        int n1 = 0 ;double n2 = 0.0;
        scanf("%d %lf",&n1,&n2);
        first[n1] = n2; 
    }
    int b_len = 0;
    scanf("%d",&b_len);
    for(int i=0;i<b_len;i++){
        int n1 = 0 ;double n2 = 0.0;
        scanf("%d %lf",&n1,&n2);
        for(int j=0;j<1001;j++){
            res[j+n1] += first[j]*n2;            
      }
    }

    int cnt = 0;
    for(int i=0;i<2001;i++){
        if(res[i]!=0.0)cnt++;
    }
    printf("%d",cnt);
    for(int i = 2000; i >= 0; i--)
        if(res[i] != 0.0)
            printf(" %d %.1f", i, res[i]);
    
    return 0;


}
