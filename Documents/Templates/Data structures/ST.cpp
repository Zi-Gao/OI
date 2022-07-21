/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file

#include <cstring>
#define M >
#define mm(a,b) ((a)M(b)?(a):(b))
inline int ln(int n){
	return 63-__builtin_clzll(n);
}
const int RMQ_MAX_I=1000;
const int RMQ_MAX_J=9;
struct ST{
	int f[RMQ_MAX_I][RMQ_MAX_J];//f[i][j]---[i,i+2^j-1]
	inline void create(int data[],int n){
		memset(f,0,sizeof(f));
		int k=ln(n);
		for(register int i=1;i<=n;++i){
			f[i][0]=data[i];
		}

		for(register int j=1;j<=k;++j){
			for(register int i=1;i<=n-(1<<j)+1;++i){
				f[i][j]=mm(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
		return;
	}

	inline int query(int l,int r){
		int k=ln(r-l+1);
		return mm(f[l][k],f[r-(1<<k)+1][k]);
	}
};

inline int read();
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
