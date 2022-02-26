/***
 * @Author: Zi_Gao
 * @Date: 2022-01-25 11:14:02
 * @LastEditTime: 2022-01-25 19:13:56
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int arr[100004];
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
int check(int mid)
{
    int i, sum, out;
    sum = 0;
    out = 1;
    for (i = 0; i < n; i++)
    {
        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            out++;
            sum = arr[i];
        }
    }
    return out > m;
}
int main()
{
    // freopen("divide_b.in", "r", stdin);
    // freopen("divide_b.out", "w", stdout);
    n = read();
    m = read();
    int l = 0, r = 0, mid;
    for (int i = 0; i < n; i++)
    {
        arr[i] = read();
        r += arr[i];
        if(arr[i] > l)
        {
            l = arr[i];
        }
    }
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d", l);
}