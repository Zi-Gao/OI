/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 21:28:51
 * @LastEditTime: 2022-01-21 21:30:54
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    int cnt=0;
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]<a[j]){
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}