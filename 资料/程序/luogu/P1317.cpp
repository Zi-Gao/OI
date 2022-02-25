#include <cstdio>
int main()
{
    int n, ans = 0;
    int t1, t2, t3;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
        {
            ans++;
            continue;
        }
        int j = i;
        for (; a[j] == a[i] && j <= n; j++)
        {
        }
        if (a[i - 1] > a[i] && a[i] < a[j])
        {
            ans++;
        }
    }
    printf("%d", ans);
}