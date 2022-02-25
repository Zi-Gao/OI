/***
 * @Author: Zi_Gao
 * @Date: 2022-01-28 13:40:31
 * @LastEditTime: 2022-02-10 11:53:21
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    for(int i=123;i<329;i++){
        int t1=i;
        int t2=i<<1;
        int t3=(i<<1)+i;
        int tarr[10]={0};
        tarr[t1%10]=1;
        tarr[t1/10%10]=1;
        tarr[t1/100]=1;
        tarr[t2%10]=1;
        tarr[t2/10%10]=1;
        tarr[t2/100]=1;
        tarr[t3%10]=1;
        tarr[t3/10%10]=1;
        tarr[t3/100]=1;
        for(int j=1;j<=9;j++){
            if(tarr[j]==0){
                goto loop;
            }
        }
        printf("%d %d %d\n",t1,t2,t3);
        loop:continue;
    }
}