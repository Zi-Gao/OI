/***
 * @Author: Zi_Gao
 * @Date: 2022-02-10 10:11:46
 * @LastEditTime: 2022-02-10 10:48:38
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
struct boom{
    int x,y;
    int p;
};
bool cmp(boom a,boom b){
    if(a.p!=b.p){
        return a.p>b.p;
    }else if(a.x!=b.x){
        return a.x<b.x;
    }else{
        return a.y<b.y;
    }
}
int main(){
    // freopen("bomberman.in","r",stdin);
    // freopen("bomberman.out","w",stdout);
    char map[110][110]={0};
    boom BOOM[110*110];
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",map[i]);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            int p=0;
            int x=i,y=j;
            if(map[i][j]=='.'){
                while(true){
                    if(map[x][y]=='#'){
                        break;
                    }else if(map[x][y]=='G'){
                        p++;
                    }
                    x--;
                }
                x=i,y=j;
                while(true){
                    if(map[x][y]=='#'){
                        break;
                    }else if(map[x][y]=='G'){
                        p++;
                    }
                    x++;
                }
                x=i,y=j;
                while(true){
                    if(map[x][y]=='#'){
                        break;
                    }else if(map[x][y]=='G'){
                        p++;
                    }
                    y--;
                }
                x=i,y=j;
                while(true){
                    if(map[x][y]=='#'){
                        break;
                    }else if(map[x][y]=='G'){
                        p++;
                    }
                    y++;
                }
                BOOM[i*m+j].x=i;
                BOOM[i*m+j].y=j;
                BOOM[i*m+j].p=p;
            }else{
                BOOM[i*m+j].x=-1;
                BOOM[i*m+j].y=-1;
                BOOM[i*m+j].p=-1;
            }

        }
    }
    std::sort(BOOM,BOOM+n*m,cmp);
    int MAX=BOOM[0].p;

    for(int i=0;i<n*m;i++){
        if(MAX==-1){
            printf("-1");
            break;
        }
        if(BOOM[i].p!=MAX){
            break;
        }
        printf("%d %d %d\n",BOOM[i].x+1,BOOM[i].y+1,BOOM[i].p);
        MAX=BOOM[i].p;
    }
}