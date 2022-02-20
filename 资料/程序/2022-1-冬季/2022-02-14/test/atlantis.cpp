/***
 * @Author: Zi_Gao
 * @Date: 2022-02-14 15:40:03
 * @LastEditTime: 2022-02-14 15:49:24
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
inline int read();
int main(){
    freopen("atlantis.in","r",stdin);
    freopen("atlantis.out","w",stdout);
    for(int i=0;i<3;i++){
        int temp=0;
        char in;
        while(true){
            in=getchar();
            if(in=='\n'){
                break;
            }
            if(in==EOF){
                break;
            }
            temp+=in-'0';
        }
        if(temp%3==0){
            printf("King will win.\n");
        }else{
            printf("MaoLaoDa will win.\n%d\n",temp%3);
        }
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