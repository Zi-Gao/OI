/***
 * @Author: Zi_Gao
 * @Date: 2022-02-12 11:31:14
 * @LastEditTime: 2022-02-12 19:30:02
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
using namespace std;
bool in[7][8];
bool temp[7][8];
bool out[7][8];
inline int readnum();
inline void print();
inline void read();
inline void open(int x,int y);
inline void work();

int main(){
    freopen("lamp.in","r",stdin);
    freopen("lamp.out","w",stdout);
    // read();
    int N=readnum();
    for(int i=0;i<N;i++){
        read();
        memset(out,0,sizeof(out));
        memcpy(temp,in,sizeof(in));
        printf("PUZZLE #%d\n",i+1);
        work();
        print();
    }
    // open(1,2);
    // print();
}

inline void work(){
    char i=0;
    while(i<63){
        if((i&1)==1){
            open(1,1);
            out[1][1]^=1;
        }
        if((i&2)==2){
            open(1,2);
            out[1][2]^=1;
        }
        if((i&4)==4){
            open(1,3);
            out[1][3]^=1;
        }
        if((i&8)==8){
            open(1,4);
            out[1][4]^=1;
        }
        if((i&16)==16){
            open(1,5);
            out[1][5]^=1;
        }
        if((i&32)==32){
            open(1,6);
            out[1][6]^=1;
        }


        //做出其他的灯

        for(int x=2;x<=5;x++){
            for(int y=1;y<=6;y++){
                if(temp[x-1][y]==1){
                    open(x,y);
                    out[x][y]^=1;
                }
            }
        }

        bool flag=true;
        for(int x=1;x<=6;x++){
            if(temp[5][x]){
                flag=false;
                break;
            }
        }
        if(flag){
            return;
        }

        memset(out,0,sizeof(out));
        memcpy(temp,in,sizeof(in));

        i++;
    }
}

inline void open(int x,int y){
    temp[x][y]^=1;
    temp[x][y+1]^=1;
    temp[x][y-1]^=1;
    temp[x+1][y]^=1;
    temp[x-1][y]^=1;
}

inline void print(){
    for(int x=1;x<6;x++){
        for(int y=1;y<7;y++){
            printf("%d ",out[x][y]);
        }
        printf("\n");
    }
}

inline void read(){
    for(int x=1;x<=5;x++){
        for(int y=1;y<=6;y++){
            in[x][y]=readnum();
        }
    }
}

inline int readnum(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}