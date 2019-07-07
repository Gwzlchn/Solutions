

#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
 
int a[120], c[120];
 
bool isPalindromic() {
    for (int i = 1, j = a[0]; i < j; ++i, --j) {
        if (a[i] != a[j]) {
            return false;
        }
    }
    return true;
}
 
void cal() {
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= a[0]; ++i) {
        c[i] += (a[i] + a[a[0] - i + 1]);
        if (c[i] >= 10) {
            c[i] -= 10;
            ++c[i + 1];
        }        
    }
    c[0] = c[a[0] + 1]?(a[0] + 1):a[0];
}
 
void print() {
    if (a[0]) {
        for (int i = a[0]; i; --i) {
            printf("%d",a[i]);    
        }
        puts("");
    }
    else {
        puts("0");
    }
}
 
int main() {
long long x;
int k;
    scanf("%lld%d",&x,&k);
    for (a[0] = 0; x; a[++a[0]] = x % 10, x /= 10)
    ;
    int step = 0;
    for (; (step < k) && (!isPalindromic()); ++step) {
        cal();    
        memcpy(a, c, sizeof(a));
    }
    print();
    printf("%d\n",step);
    return 0;
}