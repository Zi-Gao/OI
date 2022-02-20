/***
 * @Author: Zi_Gao
 * @Date: 2022-02-14 08:37:26
 * @LastEditTime: 2022-02-14 16:44:18
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
using namespace std;
inline int read();
void DFS(int x,int y);
int maze[200][300]={0};
struct p{
    int x,y,d;
};

int move[4][2]={{0,1},
                {1,0},
                {0,-1},
                {-1,0}};
int main(){
    freopen("family.in","r",stdin);
    freopen("family.out","w",stdout);
    int N=read();
    for(int i=0;i<200;i++){
        for(int j=0;j<300;j++){
            maze[i][j]=1;
        }
    }
    for(int i=1;i<=N;i++){
        char in;
        int j=1;
        while(true){
            in=getchar();
            if(in=='\n'){
                break;
            }
            if(in==EOF){
                break;
            }
            if('a'<=in&&in<='z'){
                maze[i][j]=0;
            }else{
                maze[i][j]=1;
            }
            j++;
        }
    }
    int total=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<300;j++){
            if(maze[i][j]==0){
                DFS(i,j);
                total++;
                // printf("YES\n");
                // return 0;
            }
        }
    }
    printf("%d",total);
    return 0;
}
void DFS(int x,int y){
    int top=0;
    p zhan[1000];
    memset(zhan,0,sizeof(zhan));
    zhan[0].x=x;
    zhan[0].y=y;
    zhan[0].d=0;
    while(true){
        while(zhan[top].d<=4){
            if(zhan[top].d==4){
                if(top==0){
                    return;
                }
                // maze[zhan[top].x][zhan[top].y]=0;
                zhan[top].x=0;
                zhan[top].y=0;
                zhan[top].d=0;
                top--;
                goto loop2;
            }
            if(maze[zhan[top].x+move[zhan[top].d][0]][zhan[top].y+move[zhan[top].d][1]]==0){
                zhan[top+1].x=zhan[top].x+move[zhan[top].d][0];
                zhan[top+1].y=zhan[top].y+move[zhan[top].d][1];
                top++;
                maze[zhan[top].x][zhan[top].y]=1;
            }else{
                if(zhan[top].d==3){
                    if(top==0){
                        return;
                    }
                    // maze[zhan[top].x][zhan[top].y]=0;
                    zhan[top].x=0;
                    zhan[top].y=0;
                    zhan[top].d=0;
                    top--;
                }
                loop2:
                zhan[top].d++;
            }
        }

    }
    loop:
    return;
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