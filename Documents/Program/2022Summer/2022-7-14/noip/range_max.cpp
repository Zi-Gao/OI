#include <cstdio>
#include <algorithm>
using namespace std;

//********
#include <cstring>
inline int ln(int n){
	return 63-__builtin_clzll(n);
}
const int RMQ_MAX_I=100000;
const int RMQ_MAX_J=19;
struct RMQ{
	int f[RMQ_MAX_I][RMQ_MAX_J];//f[i][j]---[i,i+2^j-1]
	void c(int data[],int n){
		memset(f,0,sizeof(f));
		int k=ln(n);
		for(int i=1;i<=n;i++){
			f[i][0]=data[i];
		}
		
		for(int j=1;j<=k;j++){
			for(int i=1;i<=n-(1<<j)+1;i++){
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
		return;
	}
	
	RMQ(){
		return;
	}
	
	inline int query(int l,int r){
		int k=ln(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
};
//********

inline int read();
RMQ st;
int main(){
	freopen("range_max.in","r",stdin);
	freopen("range_max.out","w",stdout);

	int arr[100000+10]={0};
	int n=read();
	int m=read();
	for(int i=1;i<=n;i++){
		arr[i]=read();
	}
	
	st.c(arr,n);
	
	for(int i=0;i<m;i++){
		int t=read();
		int t2=read();
		printf("%d\n",st.query(t,t2));
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
