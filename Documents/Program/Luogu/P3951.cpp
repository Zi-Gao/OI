/***
 * @Author: Zi_Gao
 * @Date: 2022-02-26 20:52:08
 * @LastEditTime: 2022-02-26 20:55:49
 * @LastEditors: Zi_Gao
 * @Description: 
 */

#include <cstdio>
#define int long long
using namespace std;
inline int read();
signed main(){
    int a=read();
    int b=read();
    printf("%lld",a*b-a-b);

    return 0;
}
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}