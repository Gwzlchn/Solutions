// 题目描述
// A reversible prime
//  in any number system is a prime whose "reverse" in that
// number system is also a prime. For example in the decimal system 73 is a
// reversible prime because its reverse 37 is also a prime.



// Now given any two positive integers N (< 105
// ) and D (1 < D <= 10), you are supposed to tell if N is a
// reversible prime with radix D.

// 输入描述:
// The input file consists of several test cases.  Each case occupies a 
// line which contains two integers N and D.  The input is finished by a negative N.


// 输出描述:
// For each test case, print in one line "Yes" if N is a reversible 
// prime with radix D, or "No" if not.

// 输入例子:
// 73 10
// 23 2
// 23 10
// -2

// 输出例子:
// Yes
// Yes
// No

#include<cstdio>
#include<cmath>

bool isPrime(int a){
    int i;
    if(a<=2){
        return false;
    }
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            
            return false;
        }
    }
    return true;
}

bool isRePrime(int a,int b){
    bool flag1 = isPrime(a);
    int res = 0;
    while(a){
        res = res*b +  a%b;
        a /= b;
    }
    //printf("%d",res);

    return isPrime(res) && flag1;
}
int main(){
    int a;
    scanf("%d",&a);
    while(a>0){
        int b;
        scanf("%d",&b);

        if(isRePrime(a,b)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }


        scanf("%d",&a);
    }

    return 0;
}