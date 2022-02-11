/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 08:08:02
 * @LastEditTime: 2022-01-24 09:07:44
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    int inarr[250]={0};
    int i=0;
    while(~scanf("%d",&inarr[i])){
        i++;
    }
    int in=0;
    for(int j=0;j<4;j++){
        in+=inarr[j];
    }

    return 0;
}