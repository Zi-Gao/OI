/***
 * @Author: Zi_Gao
 * @Date: 2022-02-11 08:04:33
 * @LastEditTime: 2022-02-11 11:12:53
 * @LastEditors: Zi_Gao
 * @Description:
 */
#include <cstdio>
int total=0;
int N;
int K;
int rulerLength;
int ruler[100]={0};
void DLS(int step){
    int flag[1000]={0};
    if(step==K){
        for(int i=0;i<K+1;i++){
            flag[ruler[i]]=1;
            flag[N-ruler[i]]=1;
            flag[N]=1;
            for(int j=i;j<K+1;j++){
                flag[ruler[j]-ruler[i]]=1;
            }
        }
        int flag_b=1;
        for(int i=0;i<N;i++){
            if(flag[i]==0){
                flag_b=0;
                break;
            }
        }
        if(flag_b==1){
            int flag_c=1;
            for(int i = 1; i <= (K+1)/2;i++){
                // printf("i:%d K-i+1:%d ruler[i]:%d N-ruler[K-i+1]:%d \n",i,K-i+1,ruler[i],N-ruler[K-i+1]);
                if(ruler[i]!=(N-ruler[K-i+1])){
                    flag_c=0;//0 1 2 3 4 5 6 7 8
                }
            }
            if(flag_c==1){
                total+=2;
                // for(int i = 1; i <= K/2;i++){
                //     printf("i:%d K-i+1:%d ruler[i]:%d N-ruler[K-i+1]:%d \n",i,K-i+1,ruler[i],N-ruler[K-i+1]);
                //     if(ruler[i]!=(N-ruler[K-i+1])){
                //         flag_c=0;//0 1 2 3 4 5 6 7 8
                //     }
                // }
            }else{
                total++;
            }
            
        }
    }else{
        for(int i=1;i<=rulerLength-(K-step);i++){
            rulerLength-=i;
            ruler[step+1]=i+ruler[step];

            DLS(step+1);

            // ruler[step+1]=0;
            rulerLength+=i;
        }
    }
}
int main(){
    freopen("ruler.in","r",stdin);
    freopen("ruler.out","w",stdout);
    scanf("%d %d",&N,&K);
    rulerLength=N;
    DLS(0);
    printf("%d\n",total/2);
}