/***
 * @Author: Zi_Gao
 * @Date: 2022-02-13 10:23:06
 * @LastEditTime: 2022-02-13 15:36:19
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
using namespace std;
inline int read();
inline void print(int* a);
inline void zhuan(int& a,int du);
inline void ctrl(int in,int* a);
void work(int step);
int in[3][3];
int flag[10]={0};
int SHORT=0x7fffffff;
int main(){
    freopen("clock.in","r",stdin);
    freopen("clock.out","w",stdout);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            in[i][j]=read();
        }
    }
    int temp[3][3]={0};
    
    memcpy(temp,in,sizeof(in));
    for(int a1=0;a1<4;a1++)
        for(int a2=0;a2<4;a2++)
            for(int a3=0;a3<4;a3++)
                for(int a4=0;a4<4;a4++)
                    for(int a5=0;a5<4;a5++)
                        for(int a6=0;a6<4;a6++)
                            for(int a7=0;a7<4;a7++)
                                for(int a8=0;a8<4;a8++)
                                    for(int a9=0;a9<4;a9++){
                                        for(int i=0;i<a1;i++)
                                            ctrl(1,&in[0][0]);
                                        for(int i=0;i<a2;i++)
                                            ctrl(2,&in[0][0]);
                                        for(int i=0;i<a3;i++)
                                            ctrl(3,&in[0][0]);
                                        for(int i=0;i<a4;i++)
                                            ctrl(4,&in[0][0]);
                                        for(int i=0;i<a5;i++)
                                            ctrl(5,&in[0][0]);
                                        for(int i=0;i<a6;i++)
                                            ctrl(6,&in[0][0]);
                                        for(int i=0;i<a7;i++)
                                            ctrl(7,&in[0][0]);
                                        for(int i=0;i<a8;i++)
                                            ctrl(8,&in[0][0]);
                                        for(int i=0;i<a9;i++)
                                            ctrl(9,&in[0][0]);
                                        bool flag_=true;
                                        for(int i=0;i<3;i++)
                                            for(int j=0;j<3;j++)
                                                if(in[i][j]!=0)
                                                    flag_=false;
                                        if(flag_){
                                            for(int i=0;i<a1;i++)
                                                printf("1 ");
                                            for(int i=0;i<a2;i++)
                                                printf("2 ");
                                            for(int i=0;i<a3;i++)
                                                printf("3 ");
                                            for(int i=0;i<a4;i++)
                                                printf("4 ");
                                            for(int i=0;i<a5;i++)
                                                printf("5 ");
                                            for(int i=0;i<a6;i++)
                                                printf("6 ");
                                            for(int i=0;i<a7;i++)
                                                printf("7 ");
                                            for(int i=0;i<a8;i++)
                                                printf("8 ");
                                            for(int i=0;i<a9;i++)
                                                printf("9 ");
                                            break;
                                        }
                                        memcpy(in,temp,sizeof(in));
                                    }
    return 0;
}
inline void ctrl(int in,int* a){
    if(in==1){
        zhuan(a[0],1);
        zhuan(a[1],1);
        zhuan(a[3],1);
        zhuan(a[4],1);
        return;
    }
    if(in==2){
        zhuan(a[0],1);
        zhuan(a[1],1);
        zhuan(a[2],1);
        return;
    }
    if(in==3){
        zhuan(a[1],1);
        zhuan(a[2],1);
        zhuan(a[4],1);
        zhuan(a[5],1);
        return;
    }
    if(in==4){
        zhuan(a[0],1);
        zhuan(a[3],1);
        zhuan(a[6],1);
        return;
    }
    if(in==5){
        zhuan(a[3],1);
        zhuan(a[5],1);
        zhuan(a[1],1);
        zhuan(a[4],1);
        zhuan(a[7],1);
        return;
    }
    if(in==6){
        zhuan(a[2],1);
        zhuan(a[5],1);
        zhuan(a[8],1);
        return;
    }
    if(in==7){
        zhuan(a[3],1);
        zhuan(a[4],1);
        zhuan(a[6],1);
        zhuan(a[7],1);
        return;
    }
    if(in==8){
        zhuan(a[6],1);
        zhuan(a[7],1);
        zhuan(a[8],1);
        return;
    }
    if(in==9){
        zhuan(a[4],1);
        zhuan(a[5],1);
        zhuan(a[7],1);
        zhuan(a[8],1);
        return;
    }
}
inline void zhuan(int& a,int du){
    a+=du;
    a%=4;
    return;
}
inline void print(int* a){
    for(int i=0;i<9;i++){
        if(i%3==0)printf("\n");
        printf("%d ",a[i]);
    }
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