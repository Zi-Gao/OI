/***
 * @Author: Zi_Gao
 * @Date: 2022-01-25 08:33:45
 * @LastEditTime: 2022-01-25 20:02:18
 * @LastEditors: Zi_Gao
 * @Description: 
 */
/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 16:10:47
 * @LastEditTime: 2022-01-25 08:20:59
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>

using namespace std;
unsigned long long n, cows;
unsigned long long a[50500] = {0};
inline unsigned long long read()
{
    unsigned long long x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
        c == '-' ? f = -1 : f, c = getchar(); //?=if,:=else
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c & 15);
        c = getchar();
    }
    return x * f;
}
void subArr(unsigned long long *p, unsigned long long i, unsigned long long len)
{
    p[i] = 0;
    for (unsigned long long j = i; j < len - 1; j++)
    {
        p[j] = p[j + 1];
    }
    p[len - 1] = 0;
}
int main()
{
    // freopen("house.in", "r", stdin);
    // freopen("house.out", "w", stdout);
    n = read();
    cows = read();
    unsigned long long iMAX = read();
    for (unsigned long long i = 1; i <= cows; i++)
    {
        a[i] = read();
    }
    a[cows + 1] = n;
    unsigned long long MIN = n;
    unsigned long long p;
    n = cows;
    for (unsigned long long i = 0; i < iMAX; i++)
    {
        MIN = a[n + 1];
        for (unsigned long long j = 1; j < n; j++)
        {
            if (a[j] - a[j - 1] < MIN)
            {
                MIN = a[j] - a[j - 1];
                p = j;
            }
        }
        subArr(a, p, n + 2);
        n--;
    }
    MIN = a[n + 1];
    for (unsigned long long i = 1; i <= n; i++)
    {
        if (a[i] - a[i - 1] < MIN)
        {
            MIN = a[i] - a[i - 1];
        }
    }
    printf("%llu", MIN);
    return 0;
}