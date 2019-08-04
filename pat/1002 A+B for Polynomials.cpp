#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

double c[1003] = {0};

int main()
{
    int m=0,n=0,t=0;
    float num=0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (c[i] != 0)
            cnt++;
    }
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--)
    {
        if (c[i] != 0.0)
            printf(" %d %.1f", i, c[i]);
    }
    return 0;

}