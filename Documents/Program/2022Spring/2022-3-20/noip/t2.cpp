#include <iostream>
#include <algorithm>
#include <cstdio>
inline long long read();
using namespace std;
struct p{
	long long t,a;
};
bool cmp(const p &a,const p &b){//比较相邻两个人 
	return (a.t*a.a+(a.t+b.t)*b.a)<(b.t*b.a+(b.t+a.t)*a.a);
}
p arr[200000];
signed main() {
	freopen("t2.in", "r", stdin);
	freopen("t2.out", "w", stdout);
	
	long long n=read();
	for(long long i=0;i<n;i++){
		arr[i].a=read();
		arr[i].t=read();
	}
	sort(arr, arr + n, cmp);
	long long t=0,sum=0;
	for(long long i = 0; i < n; i++){
		t+=arr[i].t;
		sum+=t*arr[i].a;
	}
	printf("%lld",sum);
	return 0;
}
inline long long read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
