/***
 * @Author: Zi_Gao
 * @Date: 2022-01-26 08:14:13
 * @LastEditTime: 2022-01-26 08:42:55
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
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
void Merge(int a[], int s, int m, int e, int tmp[])
{
    int pb = 0, p1 = s, p2 = m + 1;
    while (p1 <= m && p2 <= e)
    {
        if (a[p1] < a[p2])
            tmp[pb++] = a[p1++];
        else
            tmp[pb++] = a[p2++];
    }
    while (p1 <= m)
        tmp[pb++] = a[p1++];
    while (p2 <= e)
        tmp[pb++] = a[p2++];
    for (int i = 0; i < e - s + 1; ++i)
        a[s + i] = tmp[i];
}
void MergeSort(int a[], int s, int e, int tmp[])
{
    if (s < e)
    {
        int m = s + (e - s) / 2;
        MergeSort(a, s, m, tmp);
        MergeSort(a, m + 1, e, tmp);
        Merge(a, s, m, e, tmp);
    }
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int n = read();
    int a[n] = {0};
    for (int i = 0; i < n; i++)
        a[i] = read();
    int tmp[n];
    MergeSort(a, 0, n - 1, tmp);
    int k = read();
    for (int i = n - 1; i >= k; i--)
        printf("%d\n", a[i]);
}
