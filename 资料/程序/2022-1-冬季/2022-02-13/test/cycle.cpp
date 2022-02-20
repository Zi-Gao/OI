/***
 * @Author: Zi_Gao
 * @Date: 2022-02-13 08:52:49
 * @LastEditTime: 2022-02-13 09:10:55
 * @LastEditors: Zi_Gao
 * @Description: 
 */
/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 08:29:06
 * @LastEditTime: 2022-01-19 08:33:00
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define GCD 21252
using namespace std;
inline int read();
int P,E,I,D;
int day;
int main(){
    freopen("cycle.in","r",stdin);
    freopen("cycle.out","w",stdout);

    P=read();E=read();I=read();D=read();
    day=I;

    while(true){
        if(((day-P)%23==0)&&((day-E)%28==0)){
            break;
        }
        day+=33;
    }
    if(day>=D){
        printf("%d\n",day-D);
    }else{
        for(day+=GCD;day<D;day+=GCD);
        printf("%d\n",day-D);
    }

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