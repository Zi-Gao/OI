/***
 * @Author: Zi_Gao
 * @Date: 2022-01-28 20:37:57
 * @LastEditTime: 2022-01-28 21:00:06
 * @LastEditors: Zi_Gao
 * @Description: 
 */
int arr[25][2]={0};
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
void init(){
    //init x
    arr[1][0]=1;
    arr[2][0]=1;
    arr[3][0]=2;
    for(int i=4; i<25; i++){
        arr[i][0]=arr[i-1][0]+arr[i-2][0]-1;
    }

    arr[4][1]=1;
    arr[5][1]=2;
    for(int i=6; i<25; i++){
        arr[i][1]=arr[i-1][1]+arr[i-2][1]+1;
    }
}
int main(){
    init();
    int in_a=read(),in_n=read(),in_m=read(),in_x=read();
    int y=(in_m-arr[in_n-1][0]*in_a)/arr[in_n-1][1];
    int x=in_a;
    printf("%d",arr[in_x][0]*x+arr[in_x][1]*y);
}