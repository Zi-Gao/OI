/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 17:02:00
 * @LastEditTime: 2022-01-21 21:09:14
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
int main(){
    int l;
    scanf("%d",&l);
    int arr[l+1]={0};
    int m;
    scanf(" %d",&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        memset(&arr[a],1,(b-a+1)*4);
    }
    int ans=0;
    for(int i=0;i<=l;i++){
        if(arr[i]==0){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}