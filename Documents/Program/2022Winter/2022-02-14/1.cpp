/***
 * @Author: Zi_Gao
 * @Date: 2022-02-14 08:37:26
 * @LastEditTime: 2022-02-14 16:02:30
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
using namespace std;
inline int read();
void DFS();
// int maze[8][10]={{1,1,1,1,1,1,1,1,1,1},
//                 {1,0,1,1,1,0,1,1,1,1},
//                 {1,1,0,1,0,1,1,1,1,1},
//                 {1,0,1,0,0,0,0,0,1,1},
//                 {1,0,1,1,1,0,1,1,1,1},
//                 {1,1,0,0,1,1,0,0,0,1},
//                 {1,0,1,1,0,0,1,1,3,1},
//                 {1,1,1,1,1,1,1,1,1,1}};
int maze[8][10]={{1,1,1,1,1,1,1,1,1,1},
                {1,0,1,1,1,0,1,1,1,1},
                {1,0,0,1,0,1,1,1,1,1},
                {1,0,0,0,0,0,0,0,1,1},
                {1,0,1,1,1,0,1,1,1,1},
                {1,1,0,0,1,0,0,0,0,1},
                {1,0,1,1,0,0,1,1,3,1},
                {1,1,1,1,1,1,1,1,1,1}};
struct p{
    int x,y,d;
};
p zhan[1000];
int top=0;
int move[8][2]={{0,1},
                {1,1},
                {1,0},
                {1,-1},
                {0,-1},
                {-1,-1},
                {-1,0},
                {-1,1}};
int main(){
    DFS();
    return 0;
}
void DFS(){
    zhan[0].x=1;
    zhan[0].y=1;
    zhan[0].d=0;
    while(true){
        while(zhan[top].d<8){
            if(maze[zhan[top].x+move[zhan[top].d][0]][zhan[top].y+move[zhan[top].d][1]]==3){
                zhan[top+1].x=zhan[top].x+move[zhan[top].d][0];
                zhan[top+1].y=zhan[top].y+move[zhan[top].d][1];
                top++;
                maze[zhan[top].x][zhan[top].y]=-1;
                for(int i=0;i<top;i++){
                    printf("%d %d\n",zhan[i].x,zhan[i].y);
                }
                printf("step:%d",top);
                goto loop;
            }
            if(maze[zhan[top].x+move[zhan[top].d][0]][zhan[top].y+move[zhan[top].d][1]]==0){
                zhan[top+1].x=zhan[top].x+move[zhan[top].d][0];
                zhan[top+1].y=zhan[top].y+move[zhan[top].d][1];
                top++;
                maze[zhan[top].x][zhan[top].y]=-1;
            }else{
                if(zhan[top].d==7){
                    if(top==0){
                        printf("no way");
                        return;
                    }
                    maze[zhan[top].x][zhan[top].y]=0;
                    zhan[top].x=0;
                    zhan[top].y=0;
                    zhan[top].d=0;
                    top--;
                }
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