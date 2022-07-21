#include <cstdio>
#define max_n 3000000+10
// #define max_n 30+10

struct node{
    int i,w;
};

struct stack{
    int s_top;
    int s[max_n];
    stack(){
        s_top==0;
        return;
    }

    inline void push(int x){
        s[s_top++]=x;
        return;
    }

    inline void pop(){
        --s_top;
    }

    inline int top(){
        return s[s_top-1];
    }

    inline int bottom(){
        return s[0];
    }

    inline bool empty(){
        return s_top==0;
    }
}s,s2;

int arr[max_n];
inline int read();
int main(){
    int n=read();

    for(register int i=1;i<=n;++i){
        arr[i]=read();
    }

    for(register int i=n;i>0;--i){
        while((!s.empty())&&(arr[i]>=arr[s.top()])) s.pop();
        if(s.empty()){
            // printf("0 ");
            s2.push(0);
        }else{
            // printf("%d ",);
            s2.push(s.top());
        }
        s.push(i);
    }

    while(!s2.empty()){
        printf("%d ",s2.top());
        s2.pop();
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