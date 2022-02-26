/*
 * @Author: Zi_Gao
 * @Date: 2022-02-20 14:40:19
 * @LastEditTime: 2022-02-20 14:40:25
 * @LastEditors: Zi_Gao
 * @Description: 
 */
/***
 * @Author: Zi_Gao
 * @Date: 2022-02-10 09:03:36
 * @LastEditTime: 2022-02-20 14:42:19
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int a[100];
int n;
int book[100];
void dfs(int step){
    if(step==n+1){
        for(int i=1;i<=n;i++)
            printf("%5d",a[i]);
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
    scanf("%d",&n);
    dfs(1);
    return 0;
}
