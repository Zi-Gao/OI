/***
 * @Author: Zi_Gao
 * @Date: 2022-01-20 08:26:06
 * @LastEditTime: 2022-01-20 19:08:44
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <string>
// #define MAX 100
int main(){
     freopen("sum.in","r",stdin);
     freopen("sum.out","w",stdout);
    char in_x[110]={0};
    int x[110]={0};
    char in_y[110]={0};
    int y[110]={0};
    int out[110]={0};
    scanf("%s %s",in_x,in_y);
    int x_i=0;
    for(int i=109;i>=0;i--){
        if(in_x[i]==0){
            continue;
        }
        x[x_i]=in_x[i]-'0';
        x_i++;
    }

    int y_i=0;
    for(int i=109;i>=0;i--){
        if(in_y[i]==0){
            continue;
        }
        y[y_i]=in_y[i]-'0';
        y_i++;
    }
    int i=0;

    for(;;i++){
        if(x_i>=y_i){
            if(x_i==i){
                break;
            }
        }else if(x_i<y_i){
            if(y_i==i){
                break;
            }
        }
        out[i]+=x[i]+y[i];
        if(out[i]>9){
            out[i]-=10;
            out[i+1]+=1;
        }
    }
    int j=i;
    for(;i>=0;i--){
        if(i==j&&out[i]==0){
            continue;
        }
        printf("%d",out[i]);
    }
    return 0;
}
