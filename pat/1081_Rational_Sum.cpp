// Rational Sum (20)
// 时间限制 1000 ms 内存限制 65536 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
// 题目描述
// Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

// 输入描述:
// Each input file contains one test case. Each case starts with a positive integer N (<=100), 
// followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators 
// are in the range of "long int".  If there is a negative number, then the sign must appear in front of the numerator.


// 输出描述:
// For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is
//  the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. 
//  You must output only the fractional part if the integer part is 0.

// 输入例子:
// 5
// 2/5 4/15 1/30 -2/60 8/3

// 输出例子:
// 3 1/3
#include<cstdio>
#include<cmath>
typedef long long ll;

ll gcd(ll a, ll b){
    return b==0?std::abs(a):gcd(b,a%b);
}

int main(){
    ll cnt;
    scanf("%lld",&cnt);

    ll res_nume=0, res_deno = 1;
    for(ll i=0;i<cnt;i++){
        ll nume=0,deno=0;
        scanf("%lld/%lld",&nume,&deno);
        ll curgcd = gcd(nume,deno);
        nume /= curgcd;
        deno /= curgcd;

        res_nume = res_nume * deno + nume * res_deno;
        res_deno = deno * res_deno;

        ll res_gcd = (gcd(res_nume,res_deno));
        res_deno /= res_gcd;
        res_nume /= res_gcd;
        //printf("%lld",res_gcd);
    }
    // printf("%lld/%lld",res_nume,res_deno);
    ll integer=res_nume/res_deno;
    
    res_nume = res_nume - (integer * res_deno) ;
    
    if(integer!=0){
        printf("%lld",integer);
        if(res_nume!=0)printf(" ");
    }
    if(res_nume!=0){
        printf("%lld/%lld",res_nume,res_deno);
    }
    if(integer==0 && res_nume==0){
        printf("0");
    }
    return 0;

}

