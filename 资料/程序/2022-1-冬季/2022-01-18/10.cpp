/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 14:53:21
 * @LastEditTime: 2022-01-18 15:42:03
 * @LastEditors: Zi_Gao
 * @Description: 素数2
 */
#include <cstdio>
#include <cmath>
int main(){
    int MAX=100;
    int a[MAX+1]={0};
    int iMAX=sqrt(MAX);
    for(int i=2;i<=(int)iMAX;i++){//n的倍数 a 2a 3a
                            //        b=2a 2b=4a
        if(a[i]==1){
            continue;
        }
        for(int j=i+i;j<=MAX;j+=i){//n的m倍数
            if(a[j]==0){
                a[j]=1;//筛除
            }
        }
    }
    for(int i=0;i<100;i++){//输出
        if(a[i]==0){
            printf("%d\n",i);
        }
    }
}