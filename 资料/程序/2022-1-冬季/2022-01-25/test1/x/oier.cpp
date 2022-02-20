/***
 * @Author: Zi_Gao
 * @Date: 2022-01-25 09:09:36
 * @LastEditTime: 2022-01-25 20:51:19
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct oier
{
    char name[40];
    unsigned long long value;
};
bool name(oier a, oier b)
{
    return strcmp(a.name, b.name) < 0;
}
bool value(oier a, oier b)
{
    if (a.value != b.value)
    {
        return a.value > b.value;
    }
    else
    {
        return strcmp(a.name, b.name) < 0;
    }
}
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
int main()
{
    // freopen("oier.in", "r", stdin);
    // freopen("oier.out", "w", stdout);
    unsigned long long N = read();
    oier in[N + 1];
    for (unsigned long long i = 0; i < N; i++)
    {
        scanf("%s", in[i].name);
        in[i].value = 0;
    }
    in[N + 1].value = 0;
    sort(in, in + N, name);
    unsigned long long K = read();
    for (unsigned long long i = 0; i < K; i++)
    {
        char name[40];
        scanf("%s", &name);
        unsigned long long l = 0, r = N;
        while (l <= r)
        {
            unsigned long long mid = (l + r) >> 1;
            if (strcmp(in[mid].name, name) == 0)
            {
                in[mid].value += read();
                break;
            }
            else if (strcmp(in[mid].name, name) < 0)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    sort(in, in + N, value);
    for (unsigned long long i = 0; i < N; i++)
    {
        printf("%s %d\n", in[i].name, in[i].value);
    }
    return 0;
}