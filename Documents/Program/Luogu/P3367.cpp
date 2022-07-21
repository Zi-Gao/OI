#include <cstdio>

#define max_n 10000+10

struct UFDS{
    int parents[max_n];
    UFDS(){
        for(int i=0;i<max_n;i++) parents[i]=i;
        return;
    }

    int find(int x){
        return x==parents[x]?x:parents[x]=find(parents[x]);
    }

    inline void merge(int a,int b){
        parents[find(b)]=find(a);
    }
}u;

inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
int main(){
    read();
    int m=read();
    int op;

    for(int i=0;i<m;i++){
        op=read();
        if(op==1) u.merge(read(),read());
        else printf("%c\n",u.find(read())==u.find(read())?'Y':'N');
    }

    return 0;
}