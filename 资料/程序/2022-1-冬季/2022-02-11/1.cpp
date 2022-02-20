/***
 * @Author: Zi_Gao
 * @Date: 2022-02-11 08:04:33
 * @LastEditTime: 2022-02-11 09:02:58
 * @LastEditors: Zi_Gao
 * @Description:
 */
#include <cstdio>
int total=0;
int rulerLength=28;
int ruler[9]={0};
void DLS(int step){
    int flag[30]={0};
    if(step==7){
        for(int i=0;i<8;i++){
            flag[ruler[i]]=1;
            flag[29-ruler[i]]=1;
            for(int j=i;j<8;j++){
                flag[ruler[j]-ruler[i]]=1;
            }
        }
        int flag_b=1;
        for(int i=0;i<29;i++){
            if(flag[i]==0){
                flag_b=0;
                break;
            }
        }
        if(flag_b==1){

            for(int i=1;i<8;i++){
                printf("%d ",ruler[i]);
            }
            printf("\n");
        }
    }else{
        for(int i=1;i<=rulerLength;i++){
            rulerLength-=i;
            ruler[step+1]=i+ruler[step];

            DLS(step+1);

            ruler[step+1]=0;
            rulerLength+=i;
        }
    }
}
int main(){
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    DLS(0);
    printf("%d\n",total/2);
}