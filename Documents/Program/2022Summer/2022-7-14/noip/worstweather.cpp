#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#include <cstring>
inline int ln(int n){
	return 63-__builtin_clzll(n);
}
const int RMQ_MAX_I=200000+10;
const int RMQ_MAX_J=15;
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
		if(l>r)return -2147483647;
		int k=ln(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
};

inline int read();

int book[200000+10];
int arr[200000+10];

RMQ st;
/*
8
-8 1
-2 2
0 6
1 5
2 7
13 1
18 10
19 14
10000
-16 1
*/
int main(){
	freopen("worstweather.in","r",stdin);
	freopen("worstweather.out","w",stdout);

	int n=read();
	
	for(int i=1;i<=n;i++){
		book[i]=read();
		arr[i]=read();
	}
	
	st.c(arr,n);
	
	//ask
	int m=read();
	int ys,yf,s,f,l,r,t;	
	for(int i=0;i<m;i++){
		ys=read();
		yf=read();
		
		s=lower_bound(book+1,book+n,ys)-book;
		f=lower_bound(book+1,book+n,yf)-book;
		
//		l=0;
//		r=n;
//		int mid=(l+r)>>1;
//		while(l<r){
//			if(book[mid]==ys){
//				break;
//			}
//			if(book[mid]<ys){
//				l=mid+1;
//				
//			}else{
//				r=mid-1;
//			}
//			mid=(l+r)>>1;
//		}
//		
//		if(book[mid]!=ys){
//			s=mid+1;
//		}else{
//			s=mid;
//		}
//		
//
//		l=0;
//		r=n;
//		mid=(l+r)>>1;
//		while(l<r){
//			if(book[mid]==yf){
//				break;
//			}
//			if(book[mid]<yf){
//				l=mid+1;
//			}else{
//				r=mid-1;
//			}
//			mid=(l+r)>>1;
//		}
//
//		if(book[mid]!=yf){
//			f=mid+1;
//		}else{
//			f=mid;
//		}
	
		
		if(book[s]!=ys&&book[f]!=yf) puts("maybe");
		else if(book[s]==ys&&book[f]==yf){
			if(st.f[s][0]<st.f[f][0])puts("false");
			else{
				t=st.query(s+1,f-1);
				if(t<st.f[f][0]){
					if(f-s==yf-ys)puts("true");
					else puts("maybe");
				}else puts("false");
			}
		}else if(book[s]==ys&&book[f]!=yf){
			t=st.query(s+1,f-1);
			if(t>=st.f[s][0])puts("false");
			else puts("maybe");
		}else{
			t=st.query(s,f-1);
			if(t>=st.f[f][0])puts("false");
			else puts("maybe");
		}
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
