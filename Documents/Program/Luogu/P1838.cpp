/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 10:09:02
 * @LastEditTime: 2022-01-21 11:45:11
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    int arr[9]={0};
    char t;
    bool f=true;
    while(~scanf("%c",&t)){
        if(f){
            arr[t-'0'-1]=1;
            f=false;
        }else{
            arr[t-'0'-1]=-1;
            f=true;
        }
    }
    if((arr[0]==1&&arr[1]==1&&arr[2]==1)||
       (arr[3]==1&&arr[4]==1&&arr[5]==1)||
       (arr[6]==1&&arr[7]==1&&arr[8]==1)||
       (arr[0]==1&&arr[4]==1&&arr[8]==1)||
       (arr[2]==1&&arr[4]==1&&arr[6]==1)||
       (arr[0]==1&&arr[3]==1&&arr[6]==1)||
       (arr[1]==1&&arr[4]==1&&arr[7]==1)||
       (arr[2]==1&&arr[5]==1&&arr[8]==1)){
        printf("xiaoa wins.");
    }else if((arr[0]==-1&&arr[1]==-1&&arr[2]==-1)||
             (arr[3]==-1&&arr[4]==-1&&arr[5]==-1)||
             (arr[6]==-1&&arr[7]==-1&&arr[8]==-1)||
             (arr[0]==-1&&arr[4]==-1&&arr[8]==-1)||
             (arr[2]==-1&&arr[4]==-1&&arr[6]==-1)||
             (arr[0]==-1&&arr[3]==-1&&arr[6]==-1)||
             (arr[1]==-1&&arr[4]==-1&&arr[7]==-1)||
             (arr[2]==-1&&arr[5]==-1&&arr[8]==-1)){
        printf("uim wins.");
    }else{
        printf("drew.");
    }
    return 0;
}