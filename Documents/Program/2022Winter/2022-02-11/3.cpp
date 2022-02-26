/***
 * @Author: Zi_Gao
 * @Date: 2022-02-11 17:01:24
 * @LastEditTime: 2022-02-12 08:32:26
 * @LastEditors: Zi_Gao
 * @Description: 数三角
 */
/*三角形类型
1.a=b=c
2.a=b=c/2
*/
#include <cstdio>
int cnt(int n){
    int dx[8]={1,1,0,-1,-1,-1,0,1};
    int dy[8]={0,-1,-1,-1,0,1,1,1};
    int g[10][10][8]={0};
    int f[10][10][8]={0};
    int N;

    scanf("%d",&N);

    // for(int i=1;i<=n;i++){
    //do 计算输入的N个木棒对应的g表元素值
    for(int x1=0;x1<=9;x1++){
        for(int y1=0;y1<=9;y1++){
            for(int d=0;d<7;d++){
                int i=0;
                int x2=x1,y2=y1;
                while(x2>=0&&x2<10&&y2>=0&&y2<10&&g[x2][y2][d]==0){
                    i++;
                    x2+=dx[d];
                    y2+=dy[d];
                }
                f[x1][y1][d]=i;
            }
        }
    }
    // }

    int total=0;
    for(int x1=0;x1<11;x1++){
        for(int y1=0;y1<11;y1++){
            for(int i=1;i<=f[x1][y1][0];i++){
                x2=x1+1*dx[0];
                y2=y1+1*dy[0];
                if()
                if()
                if()
            }
        }
    }
}