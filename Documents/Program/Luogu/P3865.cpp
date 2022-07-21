#include <cstdio>
#include <algorithm>
#include <cmath>
#define mx(a,b) ((a)>(b)?(a):(b))

#define MAX_I 100000+10
#define MAX_J 18

struct ST{
    int f[MAX_I][MAX_J];
    inline void c(int data[],int n){
        for(register int i=1;i<=n;++i){
            f[i][0]=data[i];
        }

        int k=std::__lg(n);

        for(register int j=1;j<=k;++j){
            for(register int i=1;i<=n+1-(1<<j);++i){
                f[i][j]=mx(f[i][j-1],f[i+(1<<(j-1))][j-1]);
            }
        }
        return;
    }

    inline int q(int l,int r){
        int k=std::__lg(r-l+1);
        return mx(f[l][k],f[r+1-(1<<k)][k]);
    }
}st;

inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}

int arr[MAX_I];

int main(){
    int n=read();
    int m=read();

    for(register int i=1;i<=n;++i){
        arr[i]=read();
    }

    st.c(arr,n);

    int l,r;

    for(register int i=0;i<m;++i){
        l=read();
        r=read();
        printf("%d\n",st.q(l,r));
    }

    return 0;
}