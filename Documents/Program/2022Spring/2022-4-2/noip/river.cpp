/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
//#define file
using namespace std;
inline int read();
//bool cmp(int a,int b){
//	if(a<b){
//		re
//	}
//}
int main(){
	#ifdef file
	freopen("river.in", "r", stdin);
	freopen("river.out", "w", stdout);
	#endif

	int t=read();
	while(t--){
		int n=read();
		int arr[1010]={0};
		for(int i=0;i<n;i++){
			arr[i]=read();
		}
		sort(arr,arr+n);
		int out=0;
		while(n>3){
			out+=min(a[1]*2+arr[n]+arr[n-1],arr[n]+arr[0]);
			n-=2;
		}
		if(n==3){
			out+=arr[1]+arr[0]+arr[2];
		}
		if(n==2){
			out+=arr[1];
		}
		if(n==1){
			out+=arr[0];
		}
		printf("%d ",out);
	}

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
