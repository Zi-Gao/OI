#include <cstdio>
#include <algorithm>
using namespace std;
inline int read();

int main(){
//	freopen("name.in","r",stdin);
//	freopen("name.out","w",stdout);

	int arr[10]={2,4,5,8,10,12,13,15,18,20};
	
	int l=0;
	int r=9;
	
	int mid=(l+r)>>1;
	int p=2;
	
	while(l<r){
		if(arr[mid]==p) break;
		else if(arr[mid]<p){
			l=mid+1;
		}else{
			r=mid-1;
		}
		mid=(l+r)>>1;
	}
	
	printf("%d %d\n",mid,arr[mid]);
	
	printf("%d %d\n",lower_bound(arr,arr+10,p)-arr,arr[lower_bound(arr,arr+10,p)-arr]);

	return 0;
}

inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();
	while(c>='0'&&c<='0'){
		x=(x<<3)+(x<<1)+(c&15);
	}
	return x*f;
}
