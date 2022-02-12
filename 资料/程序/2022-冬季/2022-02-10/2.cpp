/***
 * @Author: Zi_Gao
 * @Date: 2022-02-10 09:26:07
 * @LastEditTime: 2022-02-10 09:29:59
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int a[100]={0};
int f[100]={0};
int n=3;
void dfs(int s){
    int i;
    if(s==n+1){
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }else{
        for(i=1;i<=n;i++){
            if(f[i]==0){
                a[s]=i;
                f[i]=1;
                dfs(s+1);
                f[i]=0;
            }
        }
    }
}
int main(){
    dfs(1);
}