/***
 * @Author: Zi_Gao
 * @Date: 2022-02-18 21:05:26
 * @LastEditTime: 2022-02-18 21:24:26
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
#include <cmath>
#define aaa 0.01
using namespace std;
inline int read();
inline bool f();
double a,b,c,d,x=-100;
int main(){
    // cin >> a >> b >> c >> d;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    for(;x<100;){
        if(f()){
            printf("%.2f ",x);
            x+=1.0;
        }else{
            x+=0.01;
        }
    }
    return 0;
}
inline bool f(){
    if(fabs(a*x*x*x+b*x*x+c*x+d)<=aaa){
        return true;
    }
    return false;
    // return a*x*x*x+b*x*x+c*x+d;
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