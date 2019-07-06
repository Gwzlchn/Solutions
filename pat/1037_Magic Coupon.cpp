// 题目描述
// The magic shop in Mars is offering some magic coupons.  Each coupon has an integer N printed on it, meaning that when
// you use this coupon with a product, you may get N times the value of that product back!  What is more, the shop also offers
//  some bonus product for free.  However, if you apply a coupon with a positive N to this bonus product, you will have to pay
// the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!
// For example, given a set of coupons {1 2 4 -1}, and a set of product values {7 6 -2 -3} (in Mars dollars M$) where a negative
// value corresponds to a bonus product.  You can apply coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28
//  back; coupon 2 to product 2 to get M$12 back; and coupon 4 to product 4 to get M$3 back.  On the other hand, if you
// apply coupon 3 to product 4, you will have to pay M$12 to the shop.
// Each coupon and each product may be selected at most once.  Your task is to get as much money back as possible.

// 输入描述:
// Each input file contains one test case.  For each case, the first line contains the number of coupons NC, followed by a line
// with NC coupon integers.  Then the next line contains the number of products NP, followed by a line with NP product values.
//  Here 1<= NC, NP <= 105, and it is guaranteed that all the numbers will not exceed 230.

// 输出描述:
// For each test case, simply print in a line the maximum amount of money you can get back.

// 输入例子:
// 4
// 1 2 4 -1
// 4
// 7 6 -2 -3

// 输出例子:
// 43

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef  long long ll;

int main()
{
    ll m, n, ans = 0, p = 0, q = 0;
    scanf("%lld", &m);
    vector<ll> v1(m);
    for (ll i = 0; i < m; i++)
        scanf("%lld", &v1[i]);
    scanf("%lld", &n);
    vector<ll> v2(n);
    for (ll i = 0; i < n; i++)
        scanf("%lld", &v2[i]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    while (p < m && q < n && v1[p] < 0 && v2[q] < 0)
    {
        ans += v1[p] * v2[q];
        p++;
        q++;
    }
    p = m - 1, q = n - 1;
    while (p >= 0 && q >= 0 && v1[p] > 0 && v2[q] > 0)
    {
        ans += v1[p] * v2[q];
        p--;
        q--;
    }
    printf("%lld", ans);
    return 0;
}