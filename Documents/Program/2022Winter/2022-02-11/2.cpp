/***
 * @Author: Zi_Gao
 * @Date: 2022-02-11 14:33:28
 * @LastEditTime: 2022-02-12 08:57:27
 * @LastEditors: Zi_Gao
 * @Description: WHAT THE FUCK?
 */
#include <cstdio>
#define LEN 4
struct squ{
    int x,y;
    bool top;
    bool bottom;
    bool left;
    bool right;
    bool lt_rb;
    bool rt_lb;
};
struct p{
    int x,y;
};

squ chess[LEN][LEN];
inline int read();
void write(p in1,p in2);
void init();
void _print();
squ squMerge(p in1,int length);
bool checkLine(p in1,p in2);

int triangleCount(squ in);

int main(){
    init();

    // int out = 0;
    // int N=read();
    // p temp1,temp2;
    // for(int i=0;i<N;i++){
    //     temp1.x=read();
    //     temp1.y=read();
    //     temp2.x=read();
    //     temp2.y=read();
    //     write(temp1,temp2);
    // }

    // for(int length=1;length<LEN;length++){
    //     for(int i=1;i<LEN-length;i++){
    //         for(int j=1;j<LEN-length;j++){
    //             squ temp=squMerge({i,j},length);
    //             out+=triangleCount(temp);
    //         }
    //     }
    // }
    // printf("%d\n",out);

    // test checkLine????
    p test1,test2;
    // chess[1][1].top=true;
    test1.x=2;
    test1.y=2;
    test2.x=3;
    test2.y=1;
    write(test1,test2);
    printf("%d\n",checkLine(test1,test2));

    //test triangleCount
    // test.top=true;
    // test.bottom=true;
    // test.left=true;
    // test.right=true;
    // test.lt_rb=true;
    // test.rt_lb=true;
    // printf("%d\n",triangleCount(test));

    //test squMerge
    // chess[1][1].rt_lb=true;
    // chess[1][1].left=true;
    // chess[2][2].rt_lb=true;
    // chess[2][2].top=true;
    // chess[1][2].left=true;
    // chess[2][1].top=true;
    // printf("%d\n",triangleCount(squMerge(p{1,1},2)));

    // _print();

    return 0;
}

int triangleCount(squ in){
    int cnt=0;
    if(in.top&&in.left&&in.rt_lb){
        cnt++;
    }
    if(in.top&&in.right&&in.lt_rb){
        cnt++;
    }
    if(in.bottom&&in.left&&in.rt_lb){
        cnt++;
    }
    if(in.bottom&&in.right&&in.lt_rb){
        cnt++;
    }

    if(in.top&&in.rt_lb&&in.lt_rb){
        cnt++;
    }
    if(in.left&&in.rt_lb&&in.lt_rb){
        cnt++;
    }
    if(in.bottom&&in.rt_lb&&in.lt_rb){
        cnt++;
    }
    if(in.top&&in.left&&in.lt_rb){
        cnt++;
    }

    return cnt;
}

squ squMerge(p in1,int length){
    squ out;
    p lt,rt,lb,rb;
    lt.x=in1.x;
    lt.y=in1.y+length;

    rt.x=in1.x+length;
    rt.y=in1.y+length;

    lb=in1;

    rb.x=in1.x+length;
    rb.y=in1.y;
    if(checkLine(lt,rt)){
        out.top=true;
    }
    if(checkLine(lb,rb)){
        out.bottom=true;
    }
    if(checkLine(lt,lb)){
        out.left=true;
    }
    if(checkLine(rt,rb)){
        out.right=true;
    }
    if(checkLine(lt,rb)){
        out.lt_rb=true;
    }
    if(checkLine(rt,lb)){
        out.rt_lb=true;
    }
    return out;
}

bool checkLine(p in1,p in2){
    bool flag=true;
    // if()
    return flag;
}

void write(p in1,p in2){
    if(in1.x==in2.x){// |
        if(in1.y==in2.y+1){
            chess[in1.x][in1.y-1].right=true;
            chess[in1.x-1][in1.y-1].left=true;
        }else{
            chess[in1.x-1][in1.y].right=true;
            chess[in1.x][in1.y].left=true;
        }
    }else if(in1.y==in2.y){// _
        if(in1.x==in2.x+1){
            chess[in1.x-1][in1.y].bottom=true;
            chess[in1.x-1][in1.y-1].top=true;
        }else{
            chess[in1.x][in1.y].bottom=true;
            chess[in1.x][in1.y-1].top=true;
        }
    }else if(in1.x==in2.x+1){// |\|
        if(in1.y==in2.y+1){
            chess[in1.x-1][in1.y-1].rt_lb=true;
        }else{
            chess[in1.x-1][in1.y].lt_rb=true;
        }
    }else if(in1.x==in2.x-1){// |/|
        if(in1.y==in2.y+1){
            chess[in1.x][in1.y-1].lt_rb=true;
        }else{
            chess[in1.x][in1.y].rt_lb=true;
        }
    }
}

void _print(){
    for(int i=0;i<LEN*LEN;i++){
        printf("x:%d y:%d\ntop:%d bottom:%d\nleft:%d right:%d\nlt_rb:%d rt_lb:%d\n\n",chess[i%LEN][i/LEN].x,chess[i%LEN][i/LEN].y,chess[i%LEN][i/LEN].top,chess[i%LEN][i/LEN].bottom,chess[i%LEN][i/LEN].left,chess[i%LEN][i/LEN].right,chess[i%LEN][i/LEN].lt_rb,chess[i%LEN][i/LEN].rt_lb);
    }
}

void init(){
    for(int x=0;x<LEN;x++){
        for(int y=0;y<LEN;y++){
            chess[x][y].x=x;
            chess[x][y].y=y;
        }
    }
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