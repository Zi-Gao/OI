#include <cstdio>
#include <algorithm>
using namespace std;

//********
#include <cstring>
inline int ln(int n){
	return 63-__builtin_clzll(n);
}
const int RMQ_MAX_I=500000+10;
const int RMQ_MAX_J=19;
struct RMQ{
	int fmax[RMQ_MAX_I][RMQ_MAX_J],fmin[RMQ_MAX_I][RMQ_MAX_J];//f[i][j]---[i,i+2^j-1]
	void c(int data[],int n){
		memset(fmin,0x7f,sizeof(fmin));
		memset(fmax,0,sizeof(fmax));
		int k=ln(n);
		for(int i=1;i<=n;i++){
			fmax[i][0]=data[i];
			fmin[i][0]=data[i];
		}
		
		for(int j=1;j<=k;j++){
			for(int i=1;i<=n-(1<<j)+1;i++){
				fmax[i][j]=max(fmax[i][j-1],fmax[i+(1<<(j-1))][j-1]);
				fmin[i][j]=min(fmin[i][j-1],fmin[i+(1<<(j-1))][j-1]);
			}
		}
		return;
	}
	
	RMQ(){
		return;
	}
	
	inline int query_max(int l,int r){
		int k=ln(r-l+1);
		return max(fmax[l][k],fmax[r-(1<<k)+1][k]);
	}
	
	inline int query_min(int l,int r){
		int k=ln(r-l+1);
		return min(fmin[l][k],fmin[r-(1<<k)+1][k]);
	}
};
//********
inline int _abs(int in){
	return in>0?in:-in;
}
inline int read();
RMQ st;
int main(){

	int n=read();
	int k=read();
	
	int arr[500000+10];
	
	for(int i=1;i<=n;i++){
		arr[i]=read();
	}
	
	st.c(arr,n);
	int a,b;
	
	for(int i=1;i<=k;i++){
		a=read();
		b=read();
		printf("%d\n",abs(st.query_max(a,b)-st.query_min(a,b)));
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
