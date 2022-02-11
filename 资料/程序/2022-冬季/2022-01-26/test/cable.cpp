/***
 * @Author: Zi_Gao
 * @Date: 2022-01-26 08:24:43
 * @LastEditTime: 2022-01-26 16:23:38
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
int arr[11000] = {0};
int K;
int N;
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
bool check(int n)
{
    int ans=0;
    for (int i = 0; i < N; i++){
        int t=arr[i];
        t-=n;
        while(t>=0){
            t-=n;
            ans++;
        }
    }
    return ans<K;
}
int main()
{
    freopen("cable.in", "r", stdin);
    freopen("cable.out", "w", stdout);
    N = read();
    K = read();
    int t1, t2;

    for (int i = 0; i < N; i++)
    {
        t1 = read();
        t2 = read();
        arr[i] += (t1 << 6) + (t1 << 5) + (t1 << 2) + t2;
    }
    int MAX=0;//MAX=arr
    int MIN=0;//MIN=arr
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > MAX)
            MAX = arr[i];
    }
    int ans = 0;
    while(MIN<MAX){
        int mid=(MAX+MIN+1)/2;
        if(check(mid)){//mid是否大了
            MAX=mid-1;
        }else{
            MIN=mid;
        }
    }
    if(MIN<1){
        printf("0.00\n");
        return 0;
    }else{
        printf("%f\n", MIN/100);
    }
}