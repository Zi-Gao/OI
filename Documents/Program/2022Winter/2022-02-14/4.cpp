/***
 * @Author: Zi_Gao
 * @Date: 2022-02-14 11:19:14
 * @LastEditTime: 2022-02-14 11:35:03
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
using namespace std;
int arr[5]={0};
int liyi[5][5]={{13,11,10,4,7},
                {12,10,10,8,5},
                {5,9,7,7,4},
                {15,12,10,11,5},
                {10,11,8,8,4}};
int flag[5]={0};
int max=0;
int maxarr[5]={0};
inline int read();
void DFS(int step);
int main(){
    DFS(0);
    for(int i=0;i<5;i++){
        printf("%c:J%d ",i+'A',maxarr[i]+1);
    }
    printf("\nsupply:%d",max);
    return 0;
}
void DFS(int step){
    if(step==5){
        int temp=0;
        for(int i=0;i<5;i++){
            temp+=liyi[i][arr[i]];
        }
        if(temp>max){
            memcpy(maxarr,arr,sizeof(arr));
            max=temp;
        }
    }
    for(int i=0; i<5; i++){
        if(flag[i]==0){
            flag[i]=1;
            arr[step]=i;
            DFS(step+1);
            flag[i]=0;
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