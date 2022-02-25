/***
 * @Author: Zi_Gao
 * @Date: 2022-01-25 14:34:55
 * @LastEditTime: 2022-01-25 14:58:51
 * @LastEditors: Zi_Gao
 * @Description: 
 */
/***
 * @Author: Zi_Gao
 * @Date: 2022-01-25 14:34:55
 * @LastEditTime: 2022-01-25 14:41:47
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    int a;
    scanf("%d",&a);
    if(a<=150){
        printf("%.1f",a*0.4463);
    }else if(a<=400){
        printf("%.1f",(a-150)*0.4663+150*0.4463);
    }else{
        printf("%.1f",(a-400)*0.5663+150*0.4463+250*0.4663);
    }
}