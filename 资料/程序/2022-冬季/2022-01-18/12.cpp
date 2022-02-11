/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 16:15:04
 * @LastEditTime: 2022-01-18 17:17:40
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    int out[127]={0};
    int i=1;
    int AAA=0;
    int aaa=0;
    int ooo=0;
    char t;
    while(~scanf("%c",&t)){
        if(t =='\n'){
            printf(" ");
            ooo++;
            continue;
        }else{
            printf("%c",t);
        }
        if(t>=65&&t<=90){
            AAA++;
        }else if(t>=97&&t<=122){
            aaa++;
        }else{
            ooo++;
        }
        out[t]++;
        i++;
    }
    printf("\n%d %d %d\n",AAA,aaa,ooo);
    for(int j=65;j<=90;j++){
        if(out[j+32]!=0){
            printf("%c:%d\n",j+32,out[j+32]);
        }
        if(out[j]!=0){
            printf("%c:%d\n",j,out[j]);
        }
    }
}