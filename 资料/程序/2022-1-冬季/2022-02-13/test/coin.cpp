/***
 * @Author: Zi_Gao
 * @Date: 2022-02-13 09:17:25
 * @LastEditTime: 2022-02-13 15:43:28
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
inline int read();
int N;
int main(){
    // freopen("coin.in","r",stdin);
    // freopen("coin.out","w",stdout);
    N=read();

    for(int i=1;i<=N;i++){
        int flag[12]={0};//标记 1:up 2:down 3:even 0:未访问
        //读入
        for(int j=0;j<3;j++){
            char temp[20]={0};//temp1-19输入 temp0:1:up 2:down 3:even
            //读入
            for(int k=1;true;k++){
                temp[k]=getchar();
                if(temp[k]=='e'){
                    temp[0]=3;
                    break;
                }else if(temp[k]=='u'){
                    temp[0]=2;
                    break;
                }else if(temp[k]=='d'){
                    temp[0]=1;
                    break;
                }
            }
            int flag2=1;
            for(int j=1;!(temp[j]==' '&&flag2==2);j++){
                //终止
                if(temp[j]==' '){//左右转换
                    flag2++;
                    // printf("%d\n",temp[0]==1);
                    if(temp[0]==1){
                        temp[0]=2;
                    }
                    if(temp[0]==2){
                        temp[0]=1;
                    }
                    continue;
                }
                if(flag[temp[j]-'A']==3) continue;//正常
                if(flag[temp[j]-'A']==1&&temp[0]==2){//设为正常
                    flag[temp[j]-'A']=3;
                    continue;
                }
                if(flag[temp[j]-'A']==2&&temp[0]==1){//设为正常
                    flag[temp[j]-'A']=3;
                    continue;
                }
                flag[temp[j]-'A']=temp[0];
            }
            //读掉多余的字符
            while(getchar()!='\n');
        }
        //扫描
        for(int j=0;j<12;j++){
            if(flag[j]==3) continue;//正常
            if(flag[j]==1){
                printf("%c is the counterfeit coin and it is light.\n",j+'A');
                break;
            }else if(flag[j]==2){
                printf("%c is the counterfeit coin and it is heavy.\n",j+'A');
                break;
            }
        }
        //输出
    }

    return 0;
}
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}