/***
 * @Author: Zi_Gao
 * @Date: 2022-01-31 22:15:34
 * @LastEditTime: 2022-01-31 22:21:02
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int a=read(),b=read(),c=read();\
    int MAX=a;
    int MIN=a;
    if(b>MAX)MAX=b;
    if(b<MIN)MIN=b;
    if(c>MAX)MAX=c;
    if(c<MIN)MIN=c;
    printf("%d/%d",MIN/gcd(MAX,MIN),MAX/gcd(MAX,MIN));

}