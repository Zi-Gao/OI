/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
inline int read();

inline int qpow(int base,int exponential){
    int res = 1;
    while(exponential){
        if(exponential&1)
            res=res*base;
        base=base*base;
        exponential>>=1;
    }
    return res;
}

inline int qpow_mod(int base,int exponential,const int mod){
    int res = 1;
    base%=mod;
    while(exponential){
        if(exponential&1)
            res=(res*base)%mod;
        base=(base*base)%mod;
        exponential>>=1;
    }
    return res;
}

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
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
