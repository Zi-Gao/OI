/***
 * @Author: Zi_Gao
 * @Date: 2022-02-12 08:11:28
 * @LastEditTime: 2022-02-12 11:29:53
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#define LENA 6
#define LENB 5
void openLamp(int x,int y);
void printLamp(bool* p);
void readLamp();
inline int read();
bool lampMap[LENB][LENA]={0};
bool outMap[LENB][LENA]={0};
int main(){
    int N=read();
    for(int i=0;i<N;i++){
        readLamp();
        memset(outMap,0,sizeof(outMap));

        int temp[LENB][LENA]={0};
        for(int j=0;j<LENB;j++){
            for(int k=0;k<LENA;k++){
                temp[j][k]=lampMap[j][k];
            }
        }

        printf("\n");
        // printLamp(&lampMap[0][0]);
        // printf("\n");
        // 计算
        for(int a1=0;a1<=1;a1++){
            for(int a2=0;a2<=1;a2++){
                for(int a3=0;a3<=1;a3++){
                    for(int a4=0;a4<=1;a4++){
                        for(int a5=0;a5<=1;a5++){
                            for(int a6=0;a6<=1;a6++){
                                // memset(lampMap,0,sizeof(outMap)/5);
                                if(a1!=lampMap[0][0]){
                                    lampMap[0][0]=a1;
                                    openLamp(1,0);
                                }
                                if(a2!=lampMap[0][1]){
                                    lampMap[0][1]=a2;
                                    openLamp(1,1);
                                }
                                if(a3!=lampMap[0][2]){
                                    lampMap[0][2]=a3;
                                    openLamp(1,2);
                                }
                                if(a4!=lampMap[0][3]){
                                    lampMap[0][3]=a4;
                                    openLamp(1,3);
                                }
                                if(a5!=lampMap[0][4]){
                                    lampMap[0][4]=a5;
                                    openLamp(1,4);
                                }
                                if(a6!=lampMap[0][5]){
                                    lampMap[0][5]=a6;
                                    openLamp(1,5);
                                }
                                //做出其他的灯
                                for(int y=1;y<LENB;y++){
                                    for(int x=0;x<LENA;x++){
                                        if(lampMap[y-1][x]){
                                            outMap[y][x]^=1;
                                            openLamp(y,x);
                                        }
                                    }
                                }
                                //测试
                                int flag=true;
                                for(int x=0;x<LENA;x++){
                                    if(lampMap[4][x]==true){
                                        flag=false;
                                        break;
                                    }
                                }
                                if(flag){
                                    goto loop;
                                }else{
                                    for(int y=0;y<LENB;y++){
                                        for(int x=0;x<LENA;x++){
                                            lampMap[y][x]=temp[y][x];
                                        }
                                    }
                                    memset(outMap,0,sizeof(outMap));
                                }
                            }
                        }
                    }
                }
            }
        }

        loop:
        //打印
        printLamp(&outMap[0][0]);
        //归零
        memset(lampMap,0,sizeof(lampMap));
    }
    // printf("\n");
    // printLamp(lampMap[0]);
}

void openLamp(int x,int y){
    lampMap[x][y]^=1;
    if(x==0&&y==0){
        lampMap[x+1][y]^=1;
        lampMap[x][y+1]^=1;
        return;
    }
    if(x==0&&y==LENB-1){
        lampMap[x+1][y]^=1;
        lampMap[x][y-1]^=1;
        return;
    }
    if(x==LENA-1&&y==0){
        lampMap[x-1][y]^=1;
        lampMap[x][y+1]^=1;
        return;
    }
    if(x==LENA-1&&y==LENB-1){
        lampMap[x-1][y]^=1;
        lampMap[x][y-1]^=1;
        return;
    }
    if(x==0){
        lampMap[x+1][y]^=1;
        lampMap[x][y-1]^=1;
        lampMap[x][y+1]^=1;
        return;
    }
    if(x==LENA-1){
        lampMap[x-1][y]^=1;
        lampMap[x][y-1]^=1;
        lampMap[x][y+1]^=1;
        return;
    }
    if(y==0){
        lampMap[x-1][y]^=1;
        lampMap[x+1][y]^=1;
        lampMap[x][y+1]^=1;
        return;
    }
    if(y==LENB-1){
        lampMap[x-1][y]^=1;
        lampMap[x+1][y]^=1;
        lampMap[x][y-1]^=1;
        return;
    }
    lampMap[x-1][y]^=1;
    lampMap[x+1][y]^=1;
    lampMap[x][y-1]^=1;
    lampMap[x][y+1]^=1;
    return;
}
void readLamp(){
    for(int x=0;x<LENA;x++){
        for(int y=0;y<LENB;y++){
            lampMap[x][y]=read();
        }
    }
}
void printLamp(bool* p){
    for(int y=0;y<LENB;y++){
        for(int x=0;x<LENA;x++){
            printf("%d ",p[x+y*LENA]);
        }
        printf("\n");
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