/***
 * @Author: Zi_Gao
 * @Date: 2022-01-23 21:15:41
 * @LastEditTime: 2022-01-27 14:08:28
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    bool flag = true;
    int flag10 = 0;
    int zero=0;
    int one=0;
    int h=0;
    char temp;
    int arr[210]={0};
    int i=1;
    while(~scanf("%c",&temp)){
        if(temp=='\n'&&flag){
            arr[0]=h;
            flag=false;
            continue;
        }
        if(flag){
            h++;
        }
        if(temp=='\n'){
            continue;
        }
        if(temp=='0'){
            if(flag10==1){
                arr[i]=one;
                i++;
                one=0;
            }
            zero++;
            flag10=0;
        }
        if(temp=='1'){
            if(flag10==0){
                arr[i]=zero;
                i++;
                zero=0;
            }
            one++;
            flag10=1;
        }
    }
    if(zero!=0){
        arr[i]=zero;
    }else{
        arr[i]=one;
    }
    for(int j=0;j<=i;j++){
        printf("%d ",arr[j]);
    }
}