/***
 * @Author: Zi_Gao
 * @Date: 2022-01-26 08:19:49
 * @LastEditTime: 2022-01-26 10:35:10
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
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    int n = read();
    int a[n] = {0};
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = read();
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (a[i] < a[j])
            {
                cnt++;
            }
        }
    }
    printf("%lld\n", cnt);
}
