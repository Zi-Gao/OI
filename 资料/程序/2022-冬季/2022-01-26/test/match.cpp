/***
 * @Author: Zi_Gao
 * @Date: 2022-01-26 08:44:45
 * @LastEditTime: 2022-01-26 15:27:50
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[64][64]={0};
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
void COPY(int a,int b,int c,int d,int length,int plus){
    int i,j;
    for(i=0;i<length;i++){
        for(j=0;j<length;j++){
            arr[c+i][d+j]=arr[a+i][b+j]+plus;
        }
    }
}
int main(){
    // freopen("match.in","r",stdin);
    // freopen("match.out","w",stdout);
    int n=read();
    arr[0][0]=1;
    arr[0][1]=2;
    arr[1][0]=2;
    arr[1][1]=1;
    if(n==1){
        printf("%d\n",arr[0][0]);
        return 0;
    }
    for(int i=2;i<=128;i=i<<1){
        int a[2]={0,0};
        int b[2]={0,i};
        int c[2]={i,0};
        int d[2]={i,i};
        int plus=i;
        int length=i;
        COPY(a[0],a[1],b[0],b[1],length,plus);
        COPY(b[0],b[1],c[0],c[1],length,0);
        COPY(a[0],a[1],d[0],d[1],length,0);
        if(n==2){
            for(int j=0;j<(i<<1);j++){
                for(int k=0;k<(i<<1);k++){
                    printf("%d ",arr[j][k]);
                }
                printf("\n");
            }
            break;
        }
        n--;
    }
    return 0;
}