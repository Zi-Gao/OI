/***
 * @Author: Zi_Gao
 * @Date: 2022-02-13 08:18:16
 * @LastEditTime: 2022-02-13 08:52:59
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
inline int read();
int main(){
    freopen("cube.in","r",stdin);
    freopen("cube.out","w",stdout);
    int N=read();
    for(int a=1;a<=N;a++){
        for(int b=1;b<=a;b++){
            for(int c=b+1;c<=a;c++){
                for(int d=c+1;d<=a;d++){
                    if(a*a*a==b*b*b+c*c*c+d*d*d){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                    }
                }
            }
        }
    }
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