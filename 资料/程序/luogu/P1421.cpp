/***
 * @Author: Zi_Gao
 * @Date: 2022-01-25 14:17:56
 * @LastEditTime: 2022-01-25 14:19:46
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//quik read
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
    int a=read(),b=read();
    printf("%d",((a<<3)+(a<<1)+b)/19);
}