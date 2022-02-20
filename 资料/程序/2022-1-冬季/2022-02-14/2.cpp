/***
 * @Author: Zi_Gao
 * @Date: 2022-02-14 09:16:22
 * @LastEditTime: 2022-02-14 09:25:05
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
inline int read();
int maze[8][10]={{1,1,1,1,1,1,1,1,1,1},
                {1,0,1,1,1,0,1,1,1,1},
                {1,0,0,1,0,1,1,1,1,1},
                {1,0,0,0,0,0,0,0,1,1},
                {1,0,1,1,1,0,1,1,1,1},
                {1,1,0,0,1,0,0,0,0,1},
                {1,0,1,1,0,0,1,1,3,1},
                {1,1,1,1,1,1,1,1,1,1}};
void DFS(int x,int y);
int main(){
    DFS(1,1);
    return 0;
}
void DFS(int x,int y){
    if(maze[x][y]==-1||maze[x][y]==1){
        return;
    }
    if(maze[x][y]==3){
        printf("YES");
        return;
    }
    maze[x][y]=-1;
    DFS(x,y-1);
    DFS(x,y+1);
    DFS(x+1,y);
    DFS(x-1,y);
    maze[x][y]=0;
    return;
}
void DFS();
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}