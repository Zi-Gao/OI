/***
 * @Author: Zi_Gao
 * @Date: 2022-02-10 09:42:57
 * @LastEditTime: 2022-02-10 10:08:06
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int a[20]={0};
int flag[20]={0};
int n=9;
void math(int step){
    if(step==7){
        int t=a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6];
        if(t<1000){
            flag[t/100]=1;
            flag[t%100/10]=1;
            flag[t%10]=1;
            if(flag[1]==1&&flag[2]==1&&flag[3]==1&&flag[4]==1&&flag[5]==1&&flag[6]==1&&flag[7]==1&&flag[8]==1&&flag[9]==1){
                printf("%d%d%d+%d%d%d=%d\n",a[1],a[2],a[3],a[4],a[5],a[6],t);
            }
        }

    }else{
        for(int i=1;i<=6;i++){
            if(flag[i]==0){
                a[step]=i;
                flag[i]=1;
                math(step+1);
                flag[i]=0;
            }
        }
    }
    return;
}
int main(){
    math(1);
    return 0;
}