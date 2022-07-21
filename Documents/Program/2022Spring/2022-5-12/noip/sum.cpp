/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

inline int read();
/*
6 4
1 -3 5 1 -2 3
*/
#define file
int main(){
	#ifdef file
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	#endif

	int n=read();
	int m=read();
	// int arr[]
	deque<int> q;
	long long int cnt=0;
	long long int now,best=0;
	
	for(int i=0;i<n;i++){
		arr[i]=read();
		while((now<q.back())&&(!q.empty())) q.pop();
		q.push_front(now);
		if(q)
	}

//	int arr[300010]={0};
//	for(int i=1;i<=n;i++){
//		arr[i]=arr[i-1]+read();
//	}
//
//	int s=0,j=0;
//	for(int i=0;i<n;i++){
//		if(s-j)
//	}
//	
//	printf("%lld",best);

//	int qz[300010]={0};
//	for(int i=1;i<=n;i++){
//		qz[i]=qz[i-1]+read();
//	}
//	
//	long long int best=0;
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<=n-m+3;j++){
//			if(qz[j+i]-qz[j]>best){
//				best=qz[j+i]-qz[j];
//			}
//		}
//	}
//	
	printf("%lld",best);
	
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
