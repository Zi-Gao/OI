/***
 * @Author: Zi_Gao
 * @Date: 2022-01-26 08:24:43
 * @LastEditTime: 2022-01-26 08:43:17
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
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
int main()
{
    freopen("cable.in", "r", stdin);
    freopen("cable.out", "w", stdout);
    int N = read();
    int K = read();
    int t1, t2;
    unsigned long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        t1 = read();
        t2 = read();
        sum += (t1 << 6) + (t1 << 5) + (t1 << 2) + t2;
    }
    long double out = sum / 100 / K;
    printf("%.2Lf\n", out);
}