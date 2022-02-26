/***
 * @Author: Zi_Gao
 * @Date: 2022-02-25 21:41:49
 * @LastEditTime: 2022-02-25 22:00:32
 * @LastEditors: Zi_Gao
 * @Description: Floyd-Warshall
 */
#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include <cstdio>

const int len=100;
const int inf=0x3f3f3f3f;

using namespace std;
inline int read();
int main(){
    //n:边 m:点
    int n=read(),m=read();

    int e[len][len];

    //init
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                e[i][j]=0;
            }else{
                e[i][j]=inf;
            }
        }
    }

    //read
    int t1,t2;
    for(int i=0;i<m;i++){
        t1=read();
        t2=read();
        e[t1][t2]=read();
    }

    //Floyd-Warshall
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                if(e[i][j]>e[i][k]+e[k][j]){
                    e[i][j]=e[i][k]+e[k][j];
                }
            }
        }
    }

    //output
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",e[i][j]);
        }
        putchar('\n');
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
/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/