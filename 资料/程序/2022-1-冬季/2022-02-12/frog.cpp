/***
 * @Author: Zi_Gao
 * @Date: 2022-02-12 15:02:21
 * @LastEditTime: 2022-02-12 19:53:06
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
using namespace std;
struct xy{
    int x,y;
};
inline int read();
inline bool cmp(xy in1,xy in2);

int main(){
    // freopen("frog.in","r",stdin);
    // freopen("frog.out","w",stdout);
    int R,C,N,MAX=2;
    xy tian[6000];
    //read
    R=read(),C=read(),N=read();
    for(int i=0;i<N;i++){
        tian[i].x=read(),tian[i].y=read();
    }
    sort(tian,tian+N,cmp);

    //find line
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int dx=tian[j].x-tian[i].x;
            int dy=tian[j].y-tian[i].y;
            xy copy,last,nextMAX;
            copy.x=tian[i].x;
            copy.y=tian[i].y;
            nextMAX.x=dx*(MAX-1)+tian[i].x;
            nextMAX.y=dy*(MAX-1)+tian[i].y;
            last.x=tian[i].x-dx;
            last.y=tian[i].y-dy;
            if(last.x<=R&&last.x>=1&&last.y<=C&&last.y>=1){//重复
                continue;
            }
            if(nextMAX.x>R){
                break;
            }
            if(nextMAX.y>C||nextMAX.y<1){
                continue;
            }

            int count=0;
            while(copy.x<=R&&copy.y<=C&&copy.x>=1&&copy.y>=1){
                if(!binary_search(tian,tian+N,copy,cmp)){
                    count=0;
                    break;
                }
                count++;
                copy.x+=dx;
                copy.y+=dy;
            }
            if(count>MAX){
                MAX=count;
            }
        }
    }
    if(MAX==2){
        MAX=0;
    }
    printf("%d",MAX);
}

inline bool cmp(xy in1,xy in2){
    if(in1.x!=in2.x){
        return in1.x<in2.x;
    }else{
        return in1.y<in2.y;
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