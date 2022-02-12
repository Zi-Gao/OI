/***
 * @Author: Zi_Gao
 * @Date: 2022-02-10 11:19:11
 * @LastEditTime: 2022-02-10 11:43:35
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int B[11]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("matches.in","r",stdin);
    freopen("matches.out","w",stdout);
    int cnt=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<=1111;i++){
        for(int j=0;j<=1111;j++){
            int k=i+j;
            if(k>1111){
                break;
            }
            int t1=i,t2=j,t3=k,t4=0;
            if(t1==0){
                t4+=B[t1%10];
            }
            while(t1){
                t4+=B[t1%10];
                t1/=10;
            }
            if(t2==0){
                t4+=B[t2%10];
            }
            while(t2){
                t4+=B[t2%10];
                t2/=10;
            }
            if(t3==0){
                t4+=B[t3%10];
            }
            while(t3){
                t4+=B[t3%10];
                t3/=10;
            }
            if(t4+4==n){
                // printf("%d + %d = %d\n",i,j,k);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}