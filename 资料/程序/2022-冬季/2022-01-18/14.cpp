/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 20:04:21
 * @LastEditTime: 2022-01-18 20:08:17
 * @LastEditors: Zi_Gao
 * @Description: 快读
 */
#include <cstdio>
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
int main(){
    printf("%d",read());
}