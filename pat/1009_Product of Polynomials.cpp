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
#include<vector>

using namespace std;

int main(){
    int a_size;
    scanf("%d ",&a_size);

    double a_arr[1001] = {0.0},res_arr[2005] = {0.0};
    for(int i=0;i<a_size;i++){
        int a;double b;
        scanf("%d %lf",&a,&b);
        a_arr[a] = b;
    }
    int b_size;
    scanf("%d ",&b_size);
    for(int i=0;i<b_size;i++){
        int a;double b;
        scanf("%d %lf",&a,&b);
        
        for(int j =0;j<1001;j++){
            res_arr[j+a] += a_arr[j] * b;
        }

    }
    int cnt = 0;
    for(int i=0;i<=2000;i++){
        if(res_arr[i]!=0){
            cnt++;
        }
    }
    printf("%d ",cnt);

    for(int i=2000;i>=0;i--){
        if(res_arr[i]!=0){
            printf("%d %.1f ",i,res_arr[i]);
        }
    }
    return 0;

}
