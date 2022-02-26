/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 14:20:58
 * @LastEditTime: 2022-01-21 14:27:31
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
int main(){
    int num[6]={0};
    int a,b;
    scanf("%d %d",&a,&b);
    int cnt=0;
    for(int i=a;i<=b;i++){
        num[0]=i%10;
        num[1]=i/10%10;
        num[2]=i/100%10;
        num[3]=i/1000%10;
        num[4]=i/10000%10;
        num[5]=i/100000;
        for(int j=0;j<6;j++){
            if(num[j]==2){
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}