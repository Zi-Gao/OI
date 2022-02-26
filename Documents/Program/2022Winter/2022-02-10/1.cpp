/***
 * @Author: Zi_Gao
 * @Date: 2022-02-10 09:03:36
 * @LastEditTime: 2022-02-10 09:25:41
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int a[100];
int n=10;
int book[100];
void dfs(int step){
    if(step==n+1){
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }else{
        for(int i=1;i<=n;i++){
            if(book[i]==0){
                a[step]=i;
                book[i]=1;
                dfs(step+1);
                book[i]=0;
            }
        }
    }
    return;
}
int main()
{
    dfs(1);
    return 0;
}
