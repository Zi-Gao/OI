#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
inline long long read();
using namespace std;
struct p{
	long long a,t;
	bool operator < (const p & b) const
	{
		return (t*a+(t+b.t)*b.a)>(b.t*b.a+(b.t+t)*a);
	}
};
priority_queue<p>q;  

signed main() {
	freopen("t2.in", "r", stdin);
	freopen("t2.out", "w", stdout);
	
	long long n=read();
	for(long long i=0;i<n;i++){
		p t;
		t.a=read();
		t.t=read();
		q.push(t);
	}
	long long t=0,sum=0;
	for(long long i = 0; i < n; i++){
		t+=q.top().t;
		sum+=t*q.top().a;
		q.pop();
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
