/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 08:10:08
 * @LastEditTime: 2022-01-21 08:27:22
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    int n;
    scanf("%d",&n);
    int a[1001]={0};
    int M=0;
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        if(a[t]==0){
            a[t]=1;
            M++;
        }
    }

    //输出
    printf("%d\n",M);
    for(int i=2;i<1001;i++){
        if(a[i]==1){
            printf("%d ",i);
        }
    }
}